#include "sort.h"
#include <stdio.h>
/**
 * swap - utility function to swap to integers
 * @a: integer a
 * @b: integer b
 **/
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * maxHeapify - The main function to heapify a Max Heap. The function
 * assumes that everything under given root (element at index num)
 * is already heapified
 * @array: array
 * @size: size of the array for print
 * @num: index
 * @n: size of the array to run
 */
void maxHeapify(int *array, size_t size, int num, size_t n)
{
	int largest = num;		 /* Initialize largest as root*/
	int left = 2 * num + 1;	 /* left = (num << 1) + 1*/
	int right = 2 * num + 2; /* right = (num + 1) << 1*/

	/* See if left child of root exists and is greater than root*/
	if (left < (int)n && array[left] > array[largest])
		largest = left;

	/**
	 * See if right child of root exists and is greater than
     *the largest so far
	 */
	if (right < (int)n && array[right] > array[largest])
		largest = right;

	/* Change root, if needed*/
	if (largest != num)
	{
		swap(&array[num], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int i;
	/**
	 * Start from bottommost and rightmost internal mode and heapify all
     * internal modes in bottom up way
	 */
	if (array == '\0' || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeapify(array, size, i, size);

	/**
	* Repeat following steps while heap size is greater than 1.
    * The last element in max heap will be the minimum element
	*/
	for (i = (size - 1); i > 0; --i)
	{
		/**
		* The largest item in Heap is stored at the root. Replace
		*it with the last item of the heap followed by reducing the
		*size of heap by 1.
		*/
		swap(&array[0], &array[i]);
		print_array(array, size);

		/* Finally, heapify the root of tree.*/
		maxHeapify(array, size, 0, i);
	}
}
