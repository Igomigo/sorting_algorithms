#include "sort.h"


/*Methods to work with*/
void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Turns a binary tree into a complete binary heap.
 * @array: Array of integers representing a binary tree.
 * @size: Size of the array/tree.
 * @base: Index of the base row of the tree.
 * @root: Root node of the binary tree.
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t l, r, large;

	l = 2 * root + 1;
	r = 2 * root + 2;
	large = root;

	if (l < base && array[l] > array[large])
		large = l;
	if (r < base && array[r] > array[large])
		large = r;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm.
 *
 * Return: The array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		max_heapify(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swap_ints(array, array + x);
		print_array(array, size);
		max_heapify(array, size, x, 0);
	}
}
