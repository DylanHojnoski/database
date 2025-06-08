#ifndef PARSER_H
#define PARSER_H
#include "db.h"
#include <stdint.h>
#include <sys/types.h>
#include "storage.h"

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_SYNTAX_ERROR,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef  enum {
    EXECUTE_SUCCESS,
    EXECUTE_TABLE_FULL
} ExecuteResult;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;


typedef struct {
    StatementType type;
    Row row_to_insert;
} Statement;


MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

 ExecuteResult execute_statement(Statement* statement, Table* table);

#endif
