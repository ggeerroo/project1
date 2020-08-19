#ifndef _UNIT_HEADER_   // set of preprocessor directives to ensure that the headers are not included
#define _UNIT_HEADER_   // more than once

// Includes
#include <stdio.h>
#include <stdlib.h>

// Definitions
#define INIT_SIZE 5

// Type Definitions

// my functions declarations
FILE *open_file(const char *path);
int *read_numbers(FILE *fp);
void print_numbers(int *pt);

#endif // _UNIT_HEADER_

