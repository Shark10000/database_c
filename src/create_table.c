#include "main.h"

void create_table(char *request, char *operation) {
    operation = strtok(NULL, sep);
    printf("%s", operation);
    char name_of_table[100];
    strcat(name_of_table, table_format);
    FILE * new_file = fopen(name_of_table, "wb");
    char table_struct[100];
    strcat(table_struct, table_structure_format);
    FILE  * structure_file = fopen(table_struct, "w");
    fclose(new_file);
    fclose(structure_file);
}
