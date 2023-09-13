#include "sort.h"
/**
 *selection_sort - selection sort
 *@array: array to be sorted
 *@size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int tmp, i, j, min, minIndex, foundMin = 0;

	for (i = 0; i < (int) size - 1; i++)
	{
		min = array[i];
		minIndex = i;
		foundMin = 0;
		for (j = i + 1; j < (int) size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				minIndex = j;
				foundMin = 1;
			}
		}
		if (foundMin)
		{
			tmp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = tmp;
			print_array(array, size);
		}
	}
}
