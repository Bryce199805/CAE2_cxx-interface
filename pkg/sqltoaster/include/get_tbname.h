
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
            ptr.process_statements();
            if (ptr.statement_node_count()) {
                sqltoaster::mapping_t statements;
                statements.setattr("statements", ptr.statements);
                get_table(statements, res_lst);
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
