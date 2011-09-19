#include <stdio.h>

#include "stringy.h"

#define ARRAYLEN(array, type) (sizeof(array)/sizeof(type))

int main (int argc, char* argv)
{
    char* list_of_files[4];
    list_of_files[0] = "stringy.c";
    list_of_files[1] = "string_test.c";
    list_of_files[2] = "stringy.h";
    list_of_files[3] = "Makefile";

    printf("%s\n", strjoin("four", "char"));
    printf("%s\n", strlistjoin(ARRAYLEN(list_of_files, char*), list_of_files, ", "));

    return 0;
}
