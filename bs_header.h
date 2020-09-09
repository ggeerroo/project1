#ifndef _UNIT_HEADER_   // set of preprocessor directives to ensure that the headers are not included
#define _UNIT_HEADER_   // more than once

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Definitions
#define INIT_SIZE 5

// Type Definitions

// my functions declarations
FILE *open_file(const char *path);
int *read_numbers(FILE *fp, int *array, int *count, int *size);
void print_numbers(int *pt, int *count);
void sort(int *arr, int elements_array);
void merge(int *arr, int *temp, int leftStart, int rightEnd);
void merge_sort(int *arr, int *temp, int left, int right);
void search(int *arr, int *num_elements, int number);
void print_numbers_deco(int *pt, int *count, int number);

#endif // _UNIT_HEADER_

