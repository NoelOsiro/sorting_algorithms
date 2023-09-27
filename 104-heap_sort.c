#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *			 Heap sort algorithm (sift-down).
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	build_heap(array, size);
	heapify(array, size);
}

/**
 * build_heap - Builds a max heap from the array
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void build_heap(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i);
}

/**
 * sift_down - Performs the sift-down operation on the heap
 *
 * @array: The array representing the heap
 * @size: Number of elements in the heap
 * @index: The index to start the sift-down operation from
 */
void sift_down(int *array, size_t size, int index)
{
	int largest = index;
	int left_child = (2 * index) + 1;
	int right_child = (2 * index) + 2;

	if (left_child < (int)size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < (int)size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != index)
	{
		swap(&array[index], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest);
	}
}

/**
 * heapify - Sorts the array using the heapify process
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heapify(int *array, size_t size)
{
	int i;

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0);
	}
}

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
