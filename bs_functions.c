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
int *read_numbers(FILE *fp, int *count, int *size)
{
	*size = INIT_SIZE;

	// malloc() memory of initial size
	int *numbers_pt = malloc(INIT_SIZE * sizeof(int));
	if (!numbers_pt)
	{
		fprintf(stderr, "Allocation problem\n");
		exit(1);
	}
		
	while ((fscanf(fp, "%d", &numbers_pt[*count])) != EOF)
	{
		printf("%d ", *(numbers_pt + *count));

		// Add one to count of items
		*count += 1;
		
		// check if number of items > size		
		if (*count == *size)
		{
			// Double the memory size 
			*size *= 2;
			
			// realloc() new memory
			numbers_pt = realloc(numbers_pt, *size);
			if (!numbers_pt)
			{
				fprintf(stderr, "Allocation problem\n");
				exit(1);
			}
			
		}
	} 
	printf("\n");
	printf("END OF read_numbers()\n");

	return numbers_pt;	
}


// print content of array
void print_numbers(int *pt, int *count, int *size)
{
	int i;
	for (i = 0; i < *count; i++)
	{
		printf("%d ", *(pt + i));
	}
	printf("\n");
	printf("Number of items: %d\n", *count);
	printf("Size of array: %d\n", *size);	
}

