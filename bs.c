#include <bs_header.h>


void main(argc, argv)
{
	// sanitize command line arguments
	if (argc > 2)
	{	
		printf("Usage: bs.c file.txt\n");
		return 1;
	}
	
	// get the name of the file
	char *file_name = argv[1];
	// open file
	FILE *filePt = NULL;
	if	(fopen(filePt, file_name, "r") == NULL)
	{
		fprintf(stderr, "There was a problem opening the file\n");
		return 2;
	}
	// read numbers into an array in sorted order THIS DOESN'T WORK
	
	// I need to declare an array which needs a fixed size
	// I can implement a dynamic array-> if the elements surpass a certain	
	// amount, then I create a new, bigger array and copy array1 into array2
	int array_position = 0;
	int array_size = x;
	
	while (c != EOF)
	{
		if (array_position = array_size)
		{
			// create new bigger array and copy a1 to a2
			array_size = new_size;
		}
		c = getc(filePt);
		array[array_position] = c;
		array_position++;
	}
	// menu (input number to search)
	// search
	// output: found/ not found + place in the array



}

