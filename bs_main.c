#include <bs_header.h>


void main(int argc, char *argv[])
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
	open_file(path);


	// read numbers into an array 
	
	
	// menu (input number to search)
	// search
	// output: found/ not found + place in the array



}

