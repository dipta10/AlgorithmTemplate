#include <stdio.h>
// #define max 10 

void merge(int ar[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1; // length of the first first/subarray
/***************MOST IMPORTANT******************************************
			N1 = MIDDLE - LEFT + 1 !!!!!
			DON'T MISS " + 1 " !!!!!!!!!
************************************************************************
*/
	int n2 = right - mid; // length of the right/second subarray

	int L[n1], R[n2]; // not applicable in c90

	for (i = 0; i < n1; i++) L[i] = ar[left+i];

	for(i = 0; i < n2; i++) R[i] = ar[mid+1+i];


	// mergin it now finally
	i = 0; // index for left array
	j = 0; // index for right array
	k = left; // initial index of merged subarray
/***************MOST IMPORTANT******************************************
		K = LEFT;
		IF YOU ASSIGN K = 0 THEN THE ANSWER WILL BE ONLY THE NUMBERS
		PRINTED TWICE FROM THE RIGHT ARRAY 
************************************************************************/

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]) {
			ar[k] = L[i];
			i++;
		}
		else {
			ar[k] = R[j];
			j++;
		}

		k++;
	}

	while (i < n1) {
		ar[k++] = L[i++];
	}

	while (j < n2) ar[k++] = R[j++];



}


void mergeSort(int ar[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(ar, left, mid);
		mergeSort(ar, mid+1, right);

		merge(ar, left, mid, right);
	} 
	else {
		return;
	}
}


int main()
{
	int ar[] = {12, 42, 19, 3, 64, 4, 19, 23, 55, 230};
	int size = sizeof(ar)/sizeof(ar[0]);

	for(int i = 0; i < size; i++) {
		printf("%d ", ar[i]);
	}
	puts("");

	mergeSort(ar, 0, size-1);

	for(int i = 0; i < size; i++) {
		printf("%d ", ar[i]);
	}
	puts("");


	return 0;
}




// tutorialspoint
// quiz.geeksforgeeks.org/merge-sort/
// int ar[10] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
// int b[10];

// void merge(int low, int mid, int high) {
// 	int l1, l2, i;

// 	for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
// 		if (ar[l1] <= ar[l2])
// 			b[i] = ar[l1++];
// 		if (ar[l2] <= ar[l1]) 
// 			b[i] = ar[l2];
// 	}

// 	while (l1 <= mid)
// 		b[i++] = ar[l1];

// 	while (l2 <= high)
// 		b[i++] = ar[l2];

// 	for(i = low; i <= high; i++)
// 		ar[i] = b[i];


// }


// void sort(int low, int high)
// {
// 	int mid;
// 	if (low < high) {
// 		mid = (low+high)/2;
// 		sort(low, mid);
// 		sort(mid+1, high);
// 		merge(low, mid, high);
// 	}
// 	else {
// 		return;
// 	}


// }


// int main()
// {
// 	int i;
// 	printf("List before sorting: ");
// 	for(int i = 0; i < max; i++) {
// 		printf("%d ", ar[i]);
// 	}
// 	puts("");

// 	sort(0, max);

// 	printf("After: ");
// 	for(int i = 0; i < max; i++) {
// 		printf("%d ", ar[i]);
// 	}
// 	puts("");


// 	return 0;
// }