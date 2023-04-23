#include "sort.h"


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
 * bubble_sort - sorts an array of integers in ascending order.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 *
 * Return: The array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t j, length = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (j = 0; j < length - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		length--;
	}
}
