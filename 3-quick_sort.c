#include "sort.h"
/**
 * swap - swaps two numbers in an array
 * @a: a
 * @b: b
 */

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * partition - function that takes last element a pivot,
 * places the pivot element at its correct position is sorted array,
 * and places all smaller (smaller than pivot) to left of pivot
 * and all greate elements at the right of pivot
 *@arr: array
 *@l: starting index
 *@h: ending index
 *@size: size
 *Return: return pivot
 */
int partition(int *arr, int l, int h, size_t size)
{
	int x = arr[h];
	int i = (l - 1), j;
	(void) size;

	for (j = l; j <= h - 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(arr + i, arr + j);
		}
	}
	swap(arr + i + 1, arr + h);
	return (i + 1);
}

/**
 * sort_quick - function that sorts an array recursevly
 * @array: array
 * @l: starting position
 * @h: ending position
 * @size: size
 */
void sort_quick(int *array, int l, int h, size_t size)
{
	int p;

	if (l < h)
	{
		p = partition(array, l, h, size);
		print_array(array, size);
		sort_quick(array, l, p - 1, size);
		sort_quick(array, p + 1, h, size);
	}
}

/**
 *quick_sort - function that sorts an arary using the quick sort array
 *@array: array to be sorted
 *@size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	sort_quick(array, 0, size - 1, size);
}
