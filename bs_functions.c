#include <bs_header.h>


// open file
FILE * file_open(const char *path)
{
    FILE *fp;
    if ((fp = fopen(path, "r")) == NULL)
    {
        fprintf(stdout, "Error opening file\n");
        return NULL;
    }
    else
    {
        return fp;
    }
}



// read numbers into an array, return pointer to array
int *read_numbers(FILE *fp, int array[])
{
	// I need to declare an array which needs a fixed size
	// I can implement a dynamic array-> if the elements surpass a certain	
	// amount, then I create a new, bigger array and copy array1 into array2
	
	int *arr_pt = NULL;	
	int array_size = 5;
	int numbers[array_size];
	int array_position = 0;
	
	int check;
	check = fscanf(fp, %*s, %d, array[array_postition]);
	while (check == 1)
	{
		
		// check if number of items > array size		
		if (array_position = array_size)
		{
			// create new bigger array and copy a1 to a2
			array_size = array_size * 2;			
			int new_arr[array_size];
			for (int i = 0; i < array_position; i++)
			{
				new_arr[i] = array[i]; 
			}
			arr_pt = array;
		}
		array_postition++;
		check = fscanf(fp, %*s, %d, array[array_postition]);
	}
	return arr_pt;	
}
