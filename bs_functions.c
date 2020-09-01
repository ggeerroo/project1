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
int *read_numbers(FILE *fp, int *array_pt, int *count, int *size)
{
	*size = INIT_SIZE;

	// malloc() memory of initial size
	array_pt = malloc(INIT_SIZE * sizeof(int));
	if (!array_pt)
	{
		fprintf(stderr, "Allocation problem\n");
		exit(1);
	}
		
	while ((fscanf(fp, "%d", &array_pt[*count])) != EOF)
	{
		printf("%d ", *(array_pt + *count));

		// Add one to count of items
		*count += 1;
		
		// check if number of items > size		
		if (*count == *size)
		{
			// Double the memory size 
			*size *= 2;
			
			// realloc() new memory
			array_pt = realloc(array_pt, *size * sizeof(int));
			if (!array_pt)
			{
				fprintf(stderr, "Allocation problem\n");
				exit(1);
			}
			
		}
	} 
	printf("\n");
	printf("END OF read_numbers()\n");

	return array_pt;	
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

// sort
void sort(int *arr, int elements_array)
{
	int leftStart = 0; // index for the first element of the array
	int rightEnd = elements_array - 1; // index for the last element of the array
	
	int *temp = malloc(sizeof(int) * elements_array); // temporal array used for merging
	if (temp == NULL)
	{
		fprintf(stderr, "Allocation error in sort()\n");
		exit(1);
	}

	// call of actual merge_sort function
	merge_sort(arr, temp, leftStart, rightEnd);
}

// mergesort algorithm
void merge_sort(int *arr, int *temp, int left, int right)
{
	if (left >= right) return; // IT'S SORTED! (recursion base case)
		
	int middle = (left + right) / 2; // this expression is what makes 
									 // the array smaller with each recursive call
	merge_sort(arr, temp, left, middle); // sort left half
	merge_sort(arr, temp, middle + 1, right); // sort right half
	merge(arr, temp, left, right); // merge two halves 
							 // (here I'm passing the last values for 
							 //	left and right before we reached the base case,
							 // which means that on the first call is gonna be 0 and 0?)
							// NO, BECAUSE IF left == right MEANS THAT IT'S A BASE CASE (SO IT'S SORTED)
}

// merge algorithm
void merge(int *arr, int *temp, int leftStart, int rightEnd)
{
	int temp_index = leftStart;
	int left = leftStart;
	int leftEnd = (leftStart + rightEnd) / 2;
	int right = leftEnd + 1;

	while (left <= leftEnd && right <= rightEnd)	
	{
		if (arr[left] <= arr[right])     // when we have one element to merge, 								
		{                                // these two are pointing to the same memory address?? 
			temp[temp_index] = arr[left]; // NO, BECAUSE WE NEVER MERGE 1 ELEMENT
			left++;
		}
		else
		{
			temp[temp_index] = arr[right];
			right++;
		}
		temp_index++;
	}	
	
	// copy rest of right half into temp	
	if (left > leftEnd)
	{
		for (int i = 0; i <= (rightEnd - right); i++)
		{
			temp[temp_index + i] = arr[right + i];
		}
	}
	// copy rest of left half into temp
	else
	{
		for (int i = 0; i <= (leftEnd - left); i++)
		{
			temp[temp_index + i] = arr[left + i];
		}
	}
	// copy temp into arr
	for (int i = 0; i <= rightEnd; i++) 	arr[i] = temp[i];
}
