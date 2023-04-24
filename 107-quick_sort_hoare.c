#include "sort.h"

/*Functions to work with*/
void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swaps two integers in an array.
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
 * hoare_partition - Orders a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, top, below;

	pivot = array[right];
	for (top = left - 1, below = right + 1; top < below;)
	{
		do {
			top++;
		} while (array[top] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (top < below)
		{
			swap_ints(array + top, array + below);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * hoare_sort - Implements the quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: It uses the Hoare partition scheme.
 * Return: Prints the array after each swap of two elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
