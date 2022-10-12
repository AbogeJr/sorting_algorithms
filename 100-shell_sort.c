#include "sort.h"
/**
* shell_sort - function that sorts array of int in ascending order
* using the shell sort algorithm using Knuth sequence
* @array: the array of elements to be sorted
* @size: size of array of elements
* Return: sorted list
*/

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
