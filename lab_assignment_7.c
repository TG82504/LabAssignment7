#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int data;
	int numswaps;
} element;

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

element* numSwapsBubbleSort(int* arr, int size) {
	element* swaps = (element*)malloc(sizeof(element) * size);
	for (int i = 0; i < size; i++) {
		swaps[i].data = arr[i];
		swaps[i].numswaps = 0;
	}
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (swaps[j].data > swaps[j + 1].data) {
				swap(&swaps[j].data, &swaps[j + 1].data);
				swaps[j].numswaps += 1;
				swaps[j + 1].numswaps += 1;
			}
		}
	}
}

element* numSwapsSelectionSort(int* arr, int size) {
	element* swaps = (element*)malloc(sizeof(element) * size);
	for (int i = 0; i < size; i++) {
		swaps[i].data = arr[i];
		swaps[i].numswaps = 0;
	}
	for (int i = 0; i < size - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < size; j++) {
			if (swaps[j].data < swaps[min_idx].data) {
				min_idx = j;
			}
			// Swap the found minimum element with the first element 
			if (min_idx != i) {
				swap(&swaps[min_idx].data, &swaps[i].data);
				swaps[min_idx].numswaps += 1;
				swaps[i].numswaps += 1;
			}
		}
	}
}

int main(void) {
	int count;
	int array1[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
	int array2[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };

	element array1Bubble[] = numSwapsBubbleSort(array1, 9);
	element array2Bubble[] = numSwapsBubbleSort(array2, 9);
	element array1Selection[] = numSwapsSelectionSort(array1, 9);
	element array2Selection[] = numSwapsSelectionSort(array2, 9);

	printf("array1 bubble sort:\n");
	count = 0;
	for (int i = 0; i < 9; i++) {
		printf("%d: %d\n", array1Bubble[i].data, array1Bubble[i].numswaps);
		count += array1Bubble[i].numswaps;
	}
	printf("%d\n\n", count / 2);
	printf("array2 bubble sort:\n");
	count = 0;
	for (int i = 0; i < 9; i++) {
		printf("%d: %d\n", array2Bubble[i].data, array2Bubble[i].numswaps);
		count += array2Bubble[i].numswaps;
	}
	printf("%d\n\n", count / 2);
	printf("array1 selection sort:\n");
	count = 0;
	for (int i = 0; i < 9; i++) {
		printf("%d: %d\n", array1Selection[i].data, array1Selection[i].numswaps);
		count += array1Selection[i].numswaps;
	}
	printf("%d\n\n", count / 2);
	printf("array2 selection sort:\n");
	count = 0;
	for (int i = 0; i < 9; i++) {
		printf("%d: %d\n", array2Selection[i].data, array2Selection[i].numswaps);
		count += array2Selection[i].numswaps;
	}
	printf("%d\n\n", count / 2);
	return 0;
}