#ifndef STORAGE_H
#define STORAGE_H
#include <stdint.h>

#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

#define TABLE_MAX_PAGES 100
extern const uint32_t ID_SIZE;
extern const uint32_t USERNAME_SIZE;
extern const uint32_t EMAIL_SIZE;
extern const uint32_t ID_OFFSET;
extern const uint32_t USERNAME_OFFSET ;
extern const uint32_t EMAIL_OFFSET ;
extern const uint32_t ROW_SIZE ;

extern const uint32_t PAGE_SIZE;
extern const uint32_t ROWS_PER_PAGE;
extern const uint32_t TABLES_MAX_ROWS;

typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
} Table;

typedef struct {
     uint32_t id;
     char username[COLUMN_USERNAME_SIZE];
     char email[COLUMN_EMAIL_SIZE];
} Row;

void print_row(Row* row);

void serialize_row(Row* source, void* destination);

void deserialize_row(void* source, Row* destination);

void* row_slot(Table* table, uint32_t row_num);

Table* new_table();

void free_table(Table* table);
#endif
