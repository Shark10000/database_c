#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define SIZE_OF_NAME 100

struct ColumnInfo {
    char name[SIZE_OF_NAME];
    int type_of_column;
};

struct MetaInfo {
    int columns_count;
    struct ColumnInfo columns[SIZE];
};

void get_metadata(char* full_path);
int get_size_of_string(char* full_path, int sizes[SIZE]);
void get_column_names(char* full_path);