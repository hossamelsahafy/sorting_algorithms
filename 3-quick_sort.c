#include "sort.h"
/**
 * swap - function to swap two integers
 *
 * @x: parameter point to int
 *
 * @y: parameter point to int
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
 * @arr: parameter to define int
 *
 * @low: parameter to define int
 *
 * @high: parameter to define int
 *
 * @size: parameter to define size_t
 *
 * Return: will be i + 1
 */
int partition(int arr[], int low, int high, size_t size)
{
	int j;
	int pivot = arr[high];
	int i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			print_array(arr, size);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	print_array(arr, size);
	return (i + 1);
}
/**
 * quick_sort_helper - function to help
 *
 * @array: parameter that point to int
 *
 * @low: parameter to identify int
 *
 * @high: parameter to identify int
 *
 * @size: parameter to identify size_t
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		if (pi > 1)
			quick_sort_helper(array, low, pi - 1, size);
		if (high > 1)
			quick_sort_helper(array, pi + 1, high, size);
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
