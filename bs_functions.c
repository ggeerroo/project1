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
		// printf("%d ", *(array_pt + *count));

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
	return array_pt;	
}


// print content of array
void print_numbers(int *pt, int *count)
{
	int i;
	for (i = 0; i < *count; i++)
	{
		printf("%d ", pt[i]);
	}
	printf("\n");	
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
	
	free(temp);
}

// mergesort algorithm
void merge_sort(int *arr, int *temp, int left, int right)
{
	if (left >= right) return;            // If it's a base case, we are done here, go back.
	
	int middle = (left + right) / 2; 	  // Else, cut the array in half.

	merge_sort(arr, temp, left, middle); 		// sort left half
	merge_sort(arr, temp, middle + 1, right); 	// sort right half
	

	// merge algorithm
	int index = left;
	int leftEnd = middle;
	int rightEnd = right;
	right = leftEnd + 1; // we redefine right to start at first element of right half

	while (left <= leftEnd && right <= rightEnd)	
	{
		if (arr[left] <= arr[right])     // when we have one element to merge, 								
		{                                // these two are pointing to the same memory address?? 
			temp[index] = arr[left]; 	// NO, BECAUSE WE NEVER MERGE 1 ELEMENT (that's the base case, which means is sorted) 
			left++;
		}
		else
		{
			temp[index] = arr[right];
			right++;
		}
		index++;
	}	
	
	// copy rest of right half into temp	
	if (left > leftEnd)
	{
		for (int i = 0; i <= (rightEnd - right); i++)
		{
			temp[index + i] = arr[right + i];
		}
	}
	// copy rest of left half into temp
	else
	{
		for (int i = 0; i <= (leftEnd - left); i++)
		{
			temp[index + i] = arr[left + i];
		}
	}
	// copy temp into arr
	for (int i = 0; i <= rightEnd; i++) 	arr[i] = temp[i];
}

// search for number in array
void search(int *arr, int *num_elements, int number)
{
	int right = *num_elements - 1;
	int left = 0;
	int centre = right;
	
	while (arr[centre] != number) 
	{
		centre = (left + right) / 2;

		if (centre == right || centre == left) // the number is not in the array
		{
			printf("Sorry, your number is not in the array.\n");
			return;
		}		
		else if (arr[centre] > number)
		{
			right = centre;
		}
		else 
		{
			left = centre;
		}		
	}
	
	printf("Your number is in the array! :)\n");
	// decorated print
	print_numbers_deco(arr, num_elements, number);
	return;
}


// print array with user's number highlighted
void print_numbers_deco(int *pt, int *count, int number)
{
	int i;
	for (i = 0; i < *count; i++)
	{	
		if (pt[i] == number)
		{
			printf("**%d** ", pt[i]);
		}
		else
		{
			printf("%d ", pt[i]);
		}
	}
	printf("\n");	
}



