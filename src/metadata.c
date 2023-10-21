#include "metadata.h"

void get_metadata (char * full_path) {
    FILE * new_table = fopen(full_path, "r");
    struct MetaInfo inform;
    fread(&inform, sizeof(struct MetaInfo), 1, new_table);
    for (int i = 0; i < inform.columns_count; i++) {
        printf("%s %d\n", inform.columns[i].name, inform.columns[i].type_of_column);
    }
    fclose(new_table);
}

int get_size_of_string (char * full_path, int sizes[SIZE]) {
    FILE * new_table = fopen(full_path, "r");
    struct MetaInfo inform;
    fread(&inform, sizeof(struct MetaInfo), 1, new_table);
    for (int i = 0; i < inform.columns_count; i++) {
        sizes[i] = inform.columns[i].type_of_column;
//        printf("%s %d\n", inform.columns[i].name, inform.columns[i].type_of_column);
    }
    int columns = inform.columns_count;
    fclose(new_table);
    return columns;
}

void get_column_names (char * full_path) {
    FILE * new_table = fopen(full_path, "r");
    struct MetaInfo inform;
    fread(&inform, sizeof(struct MetaInfo), 1, new_table);
    for (int i = 0; i < inform.columns_count; i++) {
        printf("%s ", inform.columns[i].name);
    }
    printf("\n");
    fclose(new_table);
}