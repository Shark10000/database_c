#pragma once
//#include <stdio.h>
//#include <stdlib.h>
#include "metadata.h"
#define table_format ".bin"
#define db_path "../tables/"

int get_file_size_in_bytes(FILE *table);
int count_strings(int size, FILE *table);
void create_path(char *table_name);
int is_available(FILE *table);