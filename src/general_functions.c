#include "general_functions.h"

int get_file_size_in_bytes(FILE *table) {
    int size;
    fseek(table, 0, SEEK_END);
    size = ftell(
            table);
    rewind(table);
    return size;
}

int count_strings(int size, FILE * table) {
    return (get_file_size_in_bytes(table) - sizeof (struct MetaInfo)) / size;
}