#include "crud.h"

void create_table() {
    char full_path[100];
    scanf(" TABLE %s ", full_path);
    create_path(full_path);
    FILE* new_table = fopen(full_path, "wb");
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
    char full_path[100];
    scanf(" INTO %s VALUES ", full_path);
    create_path(full_path);
    int sizes[SIZE];
    int len = get_size_of_string(full_path, sizes);
    FILE* table = fopen(full_path, "ab");
    if (!is_available(table)) {
        return;
    }
    char data_to_write[SIZE_OF_NAME];
    int j = 0;
    while (getchar() != ')' && j < len) {
        scanf("%30[^,)]", data_to_write);
        fwrite(data_to_write, sizes[j], 1, table);
        j++;
    }
    fclose(table);
}

void select_data() {
    char full_path[100];
    scanf(" * FROM %s", full_path);
    create_path(full_path);
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
    FILE* table = fopen(full_path, "r");
    if (!is_available(table)) {
        return;
    }
    int stings = count_strings(size, table);
    for (int j = 0; j < stings; j++) {
        for (int i = 0; i < columns; i++) {
            fseek(table, sizeof(struct MetaInfo) + prefix[i] + size * j, SEEK_SET);
            char record[size];
            fread(&record, sizes[i], 1, table);
            printf("%s ", record);
            rewind(table);
        }
        printf("\n");
    }
    fclose(table);
}
