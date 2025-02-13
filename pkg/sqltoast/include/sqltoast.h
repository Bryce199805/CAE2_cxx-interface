// DO NOT EDIT. Only edit the lnclude/sqltoast.h.in file, since sqltoast.h is
// generated during build.
#ifndef SQLTOAST_H
#define SQLTOAST_H

#define SQLTOAST_VERSION_MAJOR 0
#define SQLTOAST_VERSION_MINOR 1

#if defined(__GNUC__) || defined(__clang__)
#define SQLTOAST_UNREACHABLE() __builtin_unreachable()
#else
#define SQLTOAST_UNREACHABLE() assert(!"code should not be reachable")
#endif

#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include "lexeme.h"
#include "identifier.h"
#include "data_type.h"
#include "constraint.h"
#include "column_definition.h"
#include "value.h"
#include "value_expression.h"
#include "column_reference.h"
#include "predicate.h"
#include "table_reference.h"
#include "query.h"
#include "statement.h"

#include "debug.h"

namespace sqltoast {

// Dialects of SQL that can be parsed by sqltoast
typedef enum sql_dialect {
    SQL_DIALECT_ANSI_1992,
    SQL_DIALECT_ANSI_1999,
    SQL_DIALECT_ANSI_2003
} sql_dialect_t;

// Possible return codes from parsing
enum parse_result_code {
    PARSE_OK,
    PARSE_INPUT_ERROR,
    PARSE_SYNTAX_ERROR
};

typedef enum error {
    ERR_NONE,
    ERR_NO_CLOSING_DELIMITER
} error_t;

typedef struct parse_options {
    // The dialect of SQL to parse the input with
    sql_dialect_t dialect;
    // If true, sqltoast::parse() will not attempt to create
    // sqltoast::statement objects during parsing. If all the caller is
    // interested in is determining whether a particular input is valid SQL and
    // parses to one or more SQL statements, this can reduce both the CPU time
    // taken as well as the memory usage of the parser.
    bool disable_statement_construction;
} parse_options_t;

typedef struct parse_result {
    parse_result_code code;
    std::string error;
    // As each SQL statement in an input stream is successfully parsed, a
    // sqltoast::statement derived object will be dynamically allocated and
    // pushed onto this vector
    std::vector<std::unique_ptr<statement>> statements;
} parse_result_t;

parse_result_t parse(parse_input_t& subject);
parse_result_t parse(parse_input_t& subject, parse_options_t &opts);

} // namespace sqltoast

#endif /* SQLTOAST_H */
