#include "crud.h"

void create_table() {
    char name_of_table[100];
    scanf(" TABLE %s ", name_of_table);
    char full_path[100] = db_path;
    strcat(full_path, name_of_table);
    strcat(full_path, table_format);
    FILE * new_table = fopen(full_path, "wb");
    char new_column[100];
    struct MetaInfo meta;
    int i = 0;
    while (getchar() != ')') {
        scanf("%s", new_column);
        strcpy(meta.columns[i].name, new_column);
        char type[10];
        scanf(" %30[^,)]", type);
        if (!strcmp(type, "int")) {
            meta.columns[i].type_of_column = sizeof(int);
        } else if (!strcmp(type, "double")) {
            meta.columns[i].type_of_column = sizeof(double);
        } else if (!strcmp(type, "varchar")) {
            meta.columns[i].type_of_column = SIZE_OF_NAME;
        }
        i++;
    }
    meta.columns_count = i;
    fwrite(&meta, sizeof(struct MetaInfo), 1, new_table);
    fclose(new_table);
    get_metadata(full_path);
}

void insert() {
    char name_of_table[100];
    scanf(" INTO %s VALUES ", name_of_table);
    char full_path[100] = db_path;
    strcat(full_path, name_of_table);
    strcat(full_path, table_format);
    int sizes[SIZE];
    int len = get_size_of_string(full_path, sizes);
    for (int i = 0; i < len; i++) {
        printf("%d", sizes[i]);
    }
    FILE * table = fopen(full_path, "ab");
    char data_to_write[SIZE_OF_NAME];
    int j = 0;
    while (getchar() != ')' && j < len) {
        scanf("%30[^,)]", data_to_write);
        printf("%s", data_to_write);
        fwrite(data_to_write, sizes[j], 1, table);
        fflush(table);
        rewind(table);
        j++;
    }
}
//
//void read() {
//
//}

void select_data() {
    char name_of_table[100];
    scanf(" * FROM %s", name_of_table);
    char full_path[100] = db_path;
    strcat(full_path, name_of_table);
    strcat(full_path, table_format);
    get_column_names(full_path);
    int sizes[SIZE];
    int columns = get_size_of_string(full_path, sizes);
    int size = 0;
    int prefix[columns + 1];
    prefix[0] = 0;
    for (int i = 1; i < columns + 1; i++) {
        size += sizes[i - 1];
        prefix[i] = size;
    }
    FILE * new_table = fopen(full_path, "r");
    int stings = count_strings(size, new_table);
    for (int j = 0; j < stings; j ++) {
        for (int i = 0; i < columns; i++) {
            fseek(new_table, sizeof(struct MetaInfo) + prefix[i] + size * j, SEEK_SET);
            char record[size];
            fread(&record, sizes[i], 1, new_table);
            printf("%s ", record);
            rewind(new_table);
        }
        printf("\n");
    }
    fclose(new_table);
}
