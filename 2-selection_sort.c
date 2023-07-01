#include "sort.h"

/**
 * swap - Function that swaps two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Function to sort array
 * @array: The array to be sorted
 * @size: Number of elements
 * Return : sorted array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tiny;

	for (i = 0; i < size - 1; i++)
	{
		tiny = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < tiny)
			{
				tiny = array[j];
			}
		}
		swap(&array[j], &array[i]);
		print_array(array, size);
	}
}
