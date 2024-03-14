#include "arabica.h"



char **hexaTab(char **splitLine, int i, t_instructionSet instructionSet, int len) {
    printf("len: %d\n", len);
    char **hexa = malloc(sizeof(char *) * (len + 1));
    hexa[0] = my_strdup(instructionSet.opcodes[i]);
    int j = 1;
    int k = 0;
    
    hexa[j] = NULL;
    return hexa;
}

int getHexaLine(char *line, t_hexaCode *hexaCodeList) {
    t_instructionSet instructionSet = {
    .names = {"LOAD_VAL", "READ_VAR", "STORE_VAR", "ADD", "SUB", "MUL", "DIV", "MOD", "JMP", "JMP_IF_ZERO", "JMP_IF_TRUE", "EQ", "NEQ", "GT", "LT", "GTE", "LTE", "PRINT_VAL", "INPUT_VAL", "HALT", "LOAD_STR", "PRINT_STR", "INPUT_STR", "STR_LEN", "CONCAT", "GET_CHAR", "SET_CHAR", "STR_CMP"},
    };
    int len = my_strlen(line);
    char **splitLine = split(line, ' ');
    int i = 0;
    if (splitLine == NULL || splitLine[0] == NULL) {
        return 1;
    }
    while (my_strcmp(instructionSet.names[i], splitLine[0]) != 0 && i < 28) {
        i++;
    }
    if (i == 28) {
        return 1;
    }
    // if (checkArgs(splitLine, i) == 1) {
    //     return 1;
    // }
    pushHexaCode(hexaCodeList, hexaTab(splitLine, i, instructionSet, len));
    return 0;
}

t_hexaCode *getHexaCodeList(char *filename) {
    FILE *file;
    char *buffer = NULL;
    ssize_t read;
    size_t len = 0;
    t_hexaCode *hexaCodeList = NULL;
    int chk = 0;
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        return NULL;
    }
    while (((read = getline(&buffer, &len, file)) != -1) && chk == 0) {
        chk = getHexaLine(buffer, hexaCodeList);
    }
    free(buffer);
    fclose(file);
    return hexaCodeList;
}

int main(int ac, char **av) {

    if (ac != 2 ){
        printf("Usage: %s <file>\n", av[0]);
        return 1;
    }
    t_hexaCode *hexaCodeList = NULL;
    hexaCodeList = getHexaCodeList(av[1]);
}