#ifndef GET_TBNAME_H
#define GET_TBNAME_H

#include <iostream>

#include <sqltoast.h>

#include "measure.h"
#include "printer.h"

namespace sqltoaster {
    struct parser {
        sqltoast::parse_options_t opts;
        sqltoast::parse_input_t subject;
        sqltoast::parse_result_t res;

        parser(sqltoast::parse_options_t &opts, const std::string &input) : opts(opts), subject(input.cbegin(), input.cend()) {
        }
        void operator()() {
            res = sqltoast::parse(subject, opts);
        }
    };

    bool getTBName(std::string input, std::vector<std::string> &res_lst) {
        sqltoast::parse_options_t opts = {sqltoast::SQL_DIALECT_ANSI_1999, false};
        parser p(opts, input);
        auto dur = measure<std::chrono::nanoseconds>::execution(p);
        sqltoaster::printer ptr(p.res, std::cout);
        // ptr.output_format = sqltoaster::OUTPUT_FORMAT_YAML;

        if (p.res.code == sqltoast::PARSE_OK) {
            for (const auto &stmt: p.res.statements) {
                switch (stmt->type) {
                    case sqltoast::STATEMENT_TYPE_SELECT: {
                        // 处理 SELECT 的表信息
                        ptr.process_statements();
                        if (ptr.statement_node_count()) {
                            sqltoaster::mapping_t statements;
                            statements.setattr("statements", ptr.statements);
                            get_table(statements, res_lst);
                        }
                        break;
                    }
                    case sqltoast::STATEMENT_TYPE_INSERT: {
                        const auto &insert_stmt = static_cast<const sqltoast::insert_statement_t &>(*stmt);
                        // 提取 INSERT 的目标表
                        res_lst.push_back(std::string(insert_stmt.table_name.start, insert_stmt.table_name.end));
                        break;
                    }
                    case sqltoast::STATEMENT_TYPE_UPDATE: {
                        const auto &update_stmt = static_cast<const sqltoast::update_statement_t &>(*stmt);
                        // 提取 UPDATE 的目标表
                        res_lst.push_back(std::string(update_stmt.table_name.start, update_stmt.table_name.end));
                        break;
                    }
                    case sqltoast::STATEMENT_TYPE_DELETE: {
                        const auto &delete_stmt = static_cast<const sqltoast::delete_statement_t &>(*stmt);
                        // 提取 DELETE 的目标表
                        res_lst.push_back(std::string(delete_stmt.table_name.start, delete_stmt.table_name.end));
                        break;
                    }
                    default:
                        std::cout << "Unsupported statement type: " << stmt->type << std::endl;
                }
            }

        } else if (p.res.code == sqltoast::PARSE_INPUT_ERROR) {
            std::cout << "Input error: " << p.res.error << std::endl;
            return false;
        } else {
            std::cout << "Syntax error." << std::endl;
            std::cout << p.res.error << std::endl;
            return false;
        }
        return true;
    }
}
#endif //GET_TBNAME_H
