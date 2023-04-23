#include "sort.h"


/**
 * get_max - gets the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Return: Maximum integer in the array.
 */

int get_max(int *array, int size)
{
	int maxi, i;

	for (maxi = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxi)
			maxi = array[i];
	}

	return (maxi);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: Array of integers.
 * @size: The size of the array.
 *
 * Return: The counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maxi, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxi = get_max(array, size);
	count = malloc(sizeof(int) * (maxi + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (maxi + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (maxi + 1); i++)
		count[i] += count[i - 1];
	print_array(count, maxi + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
