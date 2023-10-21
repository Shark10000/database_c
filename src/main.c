#include "main.h"

void handle_request();

int main() {
    while (1) {
        handle_request();
        break;
    }
    return 0;
}


void handle_request() {
    char request[100];
    scanf("%s", request);
    if (!strcmp(request, "CREATE\0")) {
        create_table();
    } else if (!strcmp(request, "SELECT\0")) {
        select_data();
    } else if (!strcmp(request, "INSERT\0")) {
        insert();
    }
}