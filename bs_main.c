#include "bs_header.h"

int main(int argc, char *argv[])
{
	// initialize counters for number of items in array + size of array
	int count = 0, size = 0;
	
	// pointers to counters
	int * count_pt = &count;
	int * size_pt = &size;

	// sanitize command line arguments
	if (argc != 2)
	{	
		printf("Usage: program_name your_file\n");
		return 1;
	}

	// get the name of the file
	char *path = argv[1];

	// open file
	FILE *file = open_file(path);

	// read numbers into an array 
	int * num_pt = read_numbers(file, count_pt, size_pt);
	
	// print array one by one
	print_numbers(num_pt, count_pt,size_pt);
	
	// GC
	free(num_pt);

	// close file
	fclose(file);

	// menu (input number to search)
	// search
	// output: found/ not found + place in the array



}

