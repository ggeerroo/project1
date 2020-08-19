#include "bs_header.h"

int main(int argc, char *argv[])
{
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
	int * num_pt = read_numbers(file);
	
	// print array one by one
	print_numbers(num_pt);
	
	// GC
	free(num_pt);

	// close file
	fclose(file);

	// menu (input number to search)
	// search
	// output: found/ not found + place in the array



}

