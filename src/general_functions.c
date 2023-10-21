#include "general_functions.h"

int get_file_size_in_bytes(FILE *table) {
    int size;
    fseek(table, 0, SEEK_END);
    size = ftell(table);
    rewind(table);
    return size;
}

int count_strings(int size, FILE *table) {
    return (get_file_size_in_bytes(table) - sizeof(struct MetaInfo)) / size;
}

void create_path(char *table_name) {
    char full_path[100] = db_path;
    strcat(full_path, table_name);
    strcat(full_path, table_format);
    strcpy(table_name, full_path);
}

int is_available(FILE *table) {
    if (table == NULL) {
        return 0;
    }
    return 1;
}