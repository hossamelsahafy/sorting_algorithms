#include <stdio.h>
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
 * @arr: parametre to define int
 *
 * @low: parameter to define int
 *
 * @high: parameter to define int
 *
 * Return: will be i + 1
 */
int partition(int arr[], int low, int high)
{
	int j;
	int pivot = arr[high];
	int i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
/**
 * quick_sort_helper - helper function for quick sort
 *
 * @array: parameter that point to int
 *
 * @low: parameter to identify int
 *
 * @high: parameter to identify int
 *
 * @size: parameter to define size_t
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		print_array(array, size);
		quick_sort_helper(array, low, pi - 1, size);
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
	quick_sort_helper(array, 0, size - 1, size);
	print_array(array, size);
}

