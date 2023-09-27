#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *			  Merge sort algorithm (top-down).
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_merge_sort(array, 0, size - 1, size);
}

/**
 * _merge_sort - Helper function for merge_sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the left sub-array
 * @high: Ending index of the right sub-array
 * @size: Number of elements in @array
 */
void _merge_sort(int *array, int low, int high, size_t size)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		_merge_sort(array, low, mid, size);
		_merge_sort(array, mid + 1, high, size);
		merge(array, low, mid, high, size);
	}
}

/**
 * merge - Merges two sub-arrays into a sorted array
 *
 * @array: The array to be sorted
 * @low: Starting index of the left sub-array
 * @mid: Middle index
 * @high: Ending index of the right sub-array
 * @size: Number of elements in @array
 */
void merge(int *array, int low, int mid, int high, size_t size)
{
	int *left, *right;
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;

	left = malloc(sizeof(int) * n1);
	right = malloc(sizeof(int) * n2);

	if (left == NULL || right == NULL)
	{
		free(left);
		free(right);
		return;
	}

	for (i = 0; i < n1; i++)
		left[i] = array[low + i];
	for (j = 0; j < n2; j++)
		right[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = low;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	print_array(array, size);

	free(left);
	free(right);
}
