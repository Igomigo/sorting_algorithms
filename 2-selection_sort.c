#include "sort.h"


/**
 * swap_ints - swaps two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Return: The array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *mini;
	size_t i, mi;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		mini = array + i;
		for (mi = i + 1; mi < size; mi++)
			mini = (array[mi] < *mini) ? (array + mi) : mini;

		if ((array + i) != mini)
		{
			swap_ints(array + i, mini);
			print_array(array, size);
		}
	}
}
