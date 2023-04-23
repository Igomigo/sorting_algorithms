#include "sort.h"

/* functions to work with */
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);


/**
 * swap_ints - swaps two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - orders a subset of an array of integers according to
 *                    the lomuto partition scheme(last element as pivot).
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: Final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *piv, top, below;

	piv = array + right;
	for (top = below = left; below < right; below++)
	{
		if (array[below] < *piv)
		{
			if (top < below)
			{
				swap_ints(array + below, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *piv)
	{
		swap_ints(array + top, piv);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - Implements the quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: It uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int parti;

	if (right - left > 0)
	{
		parti = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, parti - 1);
		lomuto_sort(array, size, parti + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
