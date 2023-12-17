#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

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
 * bubble_sort - function that sorts an array of
 * integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: parameter that point to int
 *
 * @size: parameter to define size_t
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
}

