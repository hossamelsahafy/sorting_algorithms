#include "sort.h"
/**
 * swap - function to swap two integers
 *
 * @x: parameter to define int
 *
 * @y: parameter to define int
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
/**
 * partition - function Function that partitions an array and places
 * the pivot element in its sorted position
 *
 * @array: parameter to define int
 *
 * @low: parameter to define int
 *
 * @high: parameter to define int
 *
 * @size: parameter to define size_t
 *
 * Return: will be i + 1
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low - 1;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
		print_array(array, size);
	return (i + 1);
}
/**
 * quick_sort_helper - function to help in quick sort method
 *
 * @array: parameter that point to int
 *
 * @low: parameter to define size_t
 *
 * @high: parameter to define size_t
 *
 * @size: parameter to define size_t
 */
void quick_sort_helper(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		if (pivot_index > 1)
			quick_sort_helper(array, low, pivot_index - 1, size);
		if (high > 1)
			quick_sort_helper(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: parameter that point to int
 *
 * @size: parameter to define size_t
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
