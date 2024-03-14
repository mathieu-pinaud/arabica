#ifndef ARABICA_H
#define ARABICA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct hexaCode {
    char **hexa;
    struct hexaCode *next;
    struct hexaCode *prev;
} t_hexaCode;

typedef struct instructionSet {
    char *names[28];
    char *opcodes[28];
    int args[28];
} t_instructionSet;

t_hexaCode *pushHexaCode(t_hexaCode *hexaCodeList, char **hexa);
char **split(char *src, char c);
int my_strcmp(const char *s1, char *s2);
char *my_strdup(char *str);
int my_strlen(char *str);
int mytablen(char **tab);

#endif // _ARABICA_H