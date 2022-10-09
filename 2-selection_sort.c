#include "sort.h"

/**
  * selection_sort - a function that sorts an array of integers in ascending \
  order using the Selection sort algorithm
  * @array: array to be sorted
  * @size: number of elements in array
  */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (size <= 1 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		temp = array[min_idx];
		array[min_idx] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
