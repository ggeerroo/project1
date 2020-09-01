#include "bs_header.h"

int main(int argc, char *argv[])
{
	// declare pointer to array
	int *array_pt = NULL;

	// initialize counters for number of items in array + size of array
	int count = 0, size = 0;
	
	// pointers to counters
	int * count_pt = &count;
	int * size_pt = &size;

	// sanitize command line arguments
	if (argc != 3)
	{	
		printf("Usage: *program*  *file*  *number*\n");
		return 1;
	}
	
	// get number from command line
	int number;
	if ((number = atoi(argv[2])) == 0)
	{
		printf("*number* should be an integer\n");
		printf("Usage: *program*  *file*  *number*\n");
		return 1;
	}
		
	printf("number: %d\n", number);

	// get the name of the file
	char *path = argv[1];

	// open file
	FILE *file = open_file(path);

	// read numbers into an array 
	array_pt = read_numbers(file, array_pt, count_pt, size_pt);
	
	// print array one by one
	print_numbers(array_pt, count_pt,size_pt);
	
	// sort array
	sort(array_pt, count);
	
	// print sorted array
	print_numbers(array_pt, count_pt,size_pt);

	// GC
	free(array_pt);

	// close file
	fclose(file);

	// menu (input number to search)
	// search
	// output: found/ not found + place in the array



}

