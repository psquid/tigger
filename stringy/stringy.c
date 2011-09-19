#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "stringy.h"

char* strjoin (char* astr, char* bstr)
{   
    size_t newlen = strlen(astr) + strlen(bstr) + 1;
    char* newstr = malloc(newlen);

    strcpy(newstr, astr);
    strcat(newstr, bstr);

    return newstr;
}

char* strlistjoin (int strcount, char* strlist[], char* separator)
{
    char* oldfinalstr;
    char* finalstr = malloc(1);

    finalstr[0] = '\0';
    
    int i;
    for (i = 0 ; i < strcount ; i++) {
        if (i > 0) {
            oldfinalstr = finalstr;
            finalstr = strjoin(finalstr, separator);
            free(oldfinalstr);
        }
    
        oldfinalstr = finalstr;
        finalstr = strjoin(finalstr, strlist[i]);
        free(oldfinalstr);
    }

    return finalstr;
}
