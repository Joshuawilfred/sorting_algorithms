#include "sort.h"
#include <stdio.h>
/**
 * swap - change two values in ascending or descending order
 * @arr: array
 * @item1: item one
 * @item2: item two
 *
 * @order: 1: ascending order, 0 descending order
 */
void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}
/**
 * merge - sort bitonic sequences recursively in both orders
 * @arr: array
 * @low: first element
 * @num: elements number
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int num, int order)
{
	int mid, i;

	if (num > 1)
	{
		mid = num / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}
/**
 * bitonicsort - bitonic sort algorithm implementation
 * @arr: array
 * @low: first element
 * @num: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bitonicsort(int arr[], int low, int num, int order, int size)
{
	int mid;

	if (num > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", num, size);
			print_array(&arr[low], num);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", num, size);
			print_array(&arr[low], num);
		}
		mid = num / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, num, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", num, size);
			print_array(&arr[low], num);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", num, size);
			print_array(&arr[low], num);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
