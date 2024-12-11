/*
 * Use and distribution licensed under the Apache license version 2.
 *
 * See the COPYING file in the root project directory for full text.
 */

#include <string.h>

#include <iostream>

#include <sqltoast/sqltoast.h>

#include "measure.h"
#include "printer.h"

struct parser {
    sqltoast::parse_options_t opts;
    sqltoast::parse_input_t subject;
    sqltoast::parse_result_t res;

    parser(sqltoast::parse_options_t& opts, const std::string& input) : opts(opts),
    subject(input.cbegin(), input.cend()) {
    }

    void operator()() {
        res = sqltoast::parse(subject, opts);
    }
};


int main() {
    // std::string input ="SELECT t1.a, t1.b, t2.c FROM DB1.TB1 AS t1 JOIN (SELECT * FROM DB2.TB2 JOIN DB3.TB3 ON TB2.id = TB3.id) t2 ON t1.a = t2.b";

    std::string input ="SELECT e.name, e.salary, d.name as department_name FROM employees e JOIN departments d ON e.department_id = d.department_id";

    sqltoast::parse_options_t opts = {sqltoast::SQL_DIALECT_ANSI_1999, false};
    parser p(opts, input);
    auto dur = measure<std::chrono::nanoseconds>::execution(p);
    sqltoaster::printer ptr(p.res, std::cout);
    // ptr.output_format = sqltoaster::OUTPUT_FORMAT_YAML;

    std::vector<std::string> res_lst;

    if (p.res.code == sqltoast::PARSE_OK) {
        ptr.process_statements();
        if (ptr.statement_node_count()) {
            sqltoaster::mapping_t statements;
            statements.setattr("statements", ptr.statements);
            get_table(statements, res_lst);
        }
    }
    else if (p.res.code == sqltoast::PARSE_INPUT_ERROR)
        std::cout << "Input error: " << p.res.error << std::endl;
    else {
        std::cout << "Syntax error." << std::endl;
        std::cout << p.res.error << std::endl;
    }

    for (auto& i : res_lst) {
        std::cout << i << std::endl;
    }
    return 0;
}
