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
	
	// arbitrary initial array size
	int size = 5;

	// declare the initial array to hold the numbers
	int array[size];
	
	// open file
	FILE *file = open_file(path);

	// read numbers into an array 
	int *array_pointer = read_numbers(file, array, size);
	if (array_pointer == NULL) return 3;

	// print array one by one
	//print_array(array_pointer);

	// menu (input number to search)
	// search
	// output: found/ not found + place in the array



}

