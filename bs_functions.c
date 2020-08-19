#include "bs_header.h"


// open file
FILE * open_file(const char *path)
{
    FILE *fp;
    if ((fp = fopen(path, "r")) == NULL)
    {
        fprintf(stdout, "Error opening file\n");
        return NULL;
    }
    return fp;
}



// read numbers into dynamically allocated memory (at heap), return pointer to memory
int *read_numbers(FILE *fp)
{
	//int current_size = INIT_SIZE;

	// malloc() memory of initial size
	int *numbers_pt = malloc(INIT_SIZE * sizeof(int));
	if (!numbers_pt)
	{
		fprintf(stderr, "Allocation problem\n");
		exit(1);
	}
	
	// save the initial address of memory
	int *copy_num = numbers_pt;
	
	// count number of items
	int count = 0;

	while ((fscanf(fp, "%d", &numbers_pt[count])) != EOF)
	{
		printf("%d ", *(numbers_pt + count));

		// Add one to count of items
		count++;
	} 
	printf("\n");
	printf("END OF read_numbers()\n");

	*(numbers_pt + count) = '\0';

	return copy_num;	
}


// print content of array
void print_numbers(int *pt)
{
	
	while (*pt != '\0')
	{
		printf("%d ", *pt);
		pt++;
	}
	printf("\n");
}

/*
	// check if number of items > size		
		if (count == current_size)
		{
			// Double the memory size 
			current_size *= 2;
			
			// realloc() new memory
			numbers_pt = realloc(numbers_pt, current_size);
			if (!numbers_pt)
			{
				fprintf(stderr, "Allocation problem\n");
				exit(1);
			}
			
			// get new address
			copy_num = numbers_pt;
		}
		*/
