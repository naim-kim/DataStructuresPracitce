#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_CONTACTS 1000

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char name[64];
    Date dob;
    char email[64];
    char phone[14];
} Person;

Person str2person(char*);
Date str2date(char*);
void print_contact(Person*, int);
char *trim(char*);

int main() {
    FILE *fp;
    char file_name[1024];
    char line[MAX_LINE_LENGTH];
    Person contacts[MAX_CONTACTS];
    size_t len;

    printf("Enter the file name: ");
    scanf("%s", file_name);
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Cannot open %s\n", file_name);
        exit(-1);
    }

    int cont_i = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        line[strcspn(line, "\n")] = 0; // Remove trailing newline if present
        contacts[cont_i++] = str2person(trim(line));
    }
    fclose(fp);

    print_contact(contacts, cont_i);

    return 0;
}

void print_contact(Person* cont, int cont_i) {
    for (int i = 0; i < cont_i; i++) {
        printf("[%s][%04d%02d%02d][%s][%s]\n",
            cont[i].name, cont[i].dob.year, cont[i].dob.month,
            cont[i].dob.day, cont[i].email, cont[i].phone);
    }
}

Person str2person(char* line) {
    Person p1;
    char *token;
    int i = 0;

    token = strtok(line, ";");
    while (token) {
        switch (i) {
        case 0: strcpy(p1.name, trim(token)); break;
        case 1: p1.dob = str2date(trim(token)); break;
        case 2: strcpy(p1.email, trim(token)); break;
        case 3: strcpy(p1.phone, trim(token)); break;
        }
        token = strtok(NULL, ";");
        i++;
    }
    return p1;
}

Date str2date(char* str) {
    Date date;
    char temp[10];
    strncpy(temp, str, 4);
    temp[4] = 0;
    date.year = atoi(temp);

    strncpy(temp, str + 4, 2);
    temp[2] = 0;
    date.month = atoi(temp);

    strncpy(temp, str + 6, 2);
    temp[2] = 0;
    date.day = atoi(temp);

    return date;
}

char* trim(char* s) {
    char* ptr;
    if (!s) return NULL; // NULL string
    while (isspace(*s)) s++; // skip left side white spaces
    for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr)
        ;
    *(ptr + 1) = '\0';
    return s;
}