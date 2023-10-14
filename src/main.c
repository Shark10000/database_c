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
    char * operation;
    operation = strtok(request, sep);
    printf("%s\n", operation);
    if (!strcmp(operation, "CREATE\0")) {
        create_table(request, operation);
    } else if (!strcmp(operation, "SELECT\0")) {
        printf("select");
    }
}