/*
**
** code segments

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH Cfl
#define MAX_FIELD_LENGTH 100

int main() {
    char line[MAX_LINE_LENGTH];
    char field[MAX_FIELD_LENGTH];
    char *token;
    int i = 0;
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        token = strtok(line, ",");
        while (token != NULL) {
            strcpy(field, token);
            // do something with the field
            printf("%d: %s\n", i++, field);
            token = strtok(NULL, ",");
        }
    }
    fclose(fp);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LENGTH 100

int is_enclosed_by_quotes(char* token) {
    int len = strlen(token);
    if (len < 2 || token[0] != '"' || token[len-1] != '"') {
        return 0;
    }
    for (int i = 1; i < len - 1; i++) {
        if (token[i] == '"' && token[i-1] != '\\') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char field[MAX_FIELD_LENGTH];
    char* token = "\"hello, world\"";
    if (is_enclosed_by_quotes(token)) {
        strncpy(field, token+1, strlen(token)-2);
        field[strlen(token)-2] = '\0';
        printf("Field: %s\n", field);
    } else {
        printf("Not enclosed in quotes: %s\n", token);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LENGTH 100

int is_enclosed_by_quotes(char* token) {
    int len = strlen(token);
    if (len < 2 || token[0] != '"' || token[len-1] != '"') {
        return 0;
    }
    for (int i = 1; i < len - 1; i++) {
        if (token[i] == '"' && token[i-1] != '\\') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char field[MAX_FIELD_LENGTH];
    char* token = "\"hello, world\"";
    if (is_enclosed_by_quotes(token)) {
        strncpy(field, token+1, strlen(token)-2);
        field[strlen(token)-2] = '\0';
        printf("Field: %s\n", field);
    } else {
        printf("Not enclosed in quotes: %s\n", token);
    }
    return 0;
}

*/