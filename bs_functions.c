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



// read numbers into an array, return pointer to array
int *read_numbers(FILE *fp, int array[], int size)
{
	// I need to declare an array which needs a fixed size
	// I can implement a dynamic array-> if the elements surpass a certain	
	// amount, then I create a new, bigger array and copy array1 into array2
	
	int *arr_pt = NULL;	
	int array_position = 0;
	
	int check;
	check = fscanf(fp, "%*s%d", &array[array_position]);
	while (check == 1)
	{
		
		// check if number of items > size		
		if (array_position == size)
		{
			// create new bigger array and copy a1 to a2
			size = size * 2;			
			int new_array[size];
			for (int i = 0; i < array_position; i++)
			{
				new_array[i] = array[i]; 
				printf("%d ", new_array[i]);
			}
			arr_pt = new_array;
		}
		array_position++;
		check = fscanf(fp, "%*s%d", &array[array_position]);
	}
	array[array_position] = '\0';
	return arr_pt;	
}


// print content of array
void print_array(int *array)
{
	int i = 0;
	while (*(array + i) != '\0')
	{
		printf("%d ", *(array + i));
		i++;
	}
}
