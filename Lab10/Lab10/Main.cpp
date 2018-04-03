#include "Header.h"

int main(void) {
	int data[] = { 2, 4, 3, 6, 7, 5, 1, 9, 8 }, size = 9;
	mergeSort(data, 0, size - 1);
	
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
}

void mergeSort(int arr[], int startIndex, int endIndex) {
	if (startIndex < endIndex) {
		int middleIndex = (startIndex + endIndex) / 2;

		/*Sort first and second halves*/
		mergeSort(arr, middleIndex + 1, endIndex);
		mergeSort(arr, startIndex, middleIndex);

		/*Merge*/
		merge(arr, startIndex, middleIndex, endIndex);
	}
}

void merge(int arr[], int startIndex, int middleIndex, int endIndex) {
	int firstHalfLen  = middleIndex - startIndex + 1;
	int secondHalfLen = endIndex - middleIndex;

	/*create temp arrays*/
	int *firstHalf  = new int [firstHalfLen], 
		*secondHalf = new int [secondHalfLen];

	/*Copy data to temp arrays firstHalf[] and secondHalf[]*/
	for (int i = 0; i < firstHalfLen; i++)
		firstHalf[i] = arr[startIndex + i];

	for (int i = 0; i < secondHalfLen; i++)
		secondHalf[i] = arr[middleIndex + i + 1];

	/*Initial indexes for subarrays*/
	int i = 0, j = 0, k = startIndex;

    /*Merge the temp arrays back into arr[startIndex..endIndex]*/
	for (; i < firstHalfLen && j < secondHalfLen; k++)
		if (firstHalf[i] <= secondHalf[j])
			arr[k] = firstHalf[i++];
		else
			arr[k] = secondHalf[j++];

	/*Copy the remaining elements of firstHalf[], if there are any*/
	for (; i < firstHalfLen; i++, k++)
		arr[k] = firstHalf[i];

	/*Copy the remaining elements of secondHalf[], if there are any*/
	for (; j < secondHalfLen; j++, k++)
		arr[k] = secondHalf[j];
}
