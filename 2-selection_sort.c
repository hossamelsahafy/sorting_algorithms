#include <stdio.h>
#include "sort.h"

/**
 * swap - function to swap two integers
 *
 * @x: parameter that point to integer
 *
 * @y: parameter that point to integer
 */

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
/**
 * selection_sort - function sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: parameter that point to int
 *
 * @size: parameter to define size_t
 *
 * Return: return if array == NULL
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
