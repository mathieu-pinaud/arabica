#include "arabica.h"

t_hexaCode *pushHexaCode(t_hexaCode *hexaCodeList, char **hexa) {
    t_hexaCode *newHexaCode = malloc(sizeof(t_hexaCode));
    t_hexaCode *tmp = hexaCodeList;

    int i = 0; 
    while(hexa[i] != NULL) {
        i++;
    }
    newHexaCode->hexa = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while(hexa[i] != NULL) {
        newHexaCode->hexa[i] = malloc(sizeof(char) * 3);
        newHexaCode->hexa[i][0] = hexa[i][0];
        newHexaCode->hexa[i][1] = hexa[i][1];
        newHexaCode->hexa[i][2] = '\0';
        i++;
    }
    newHexaCode->hexa[i] = NULL;
    newHexaCode->next = NULL;
    newHexaCode->prev = NULL;
    if (hexaCodeList == NULL) {
        return newHexaCode;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newHexaCode;
    newHexaCode->prev = tmp;
    return hexaCodeList;
}