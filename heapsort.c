#include<stdio.h>

void heapsort(int *, int);
void heapify(int *, int , int );
void swap(int *,int *);


int main() {

	int array[100], n, i;

	printf("\n Enter number of elements in array\n");
	scanf("%d", &n);

	printf("\n  Enter elements of array \n");

	for(i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	heapsort(array, n);

	for(i = 0; i < n; i++) {
		printf("array is %d\n", array[i]);
	}


	return 0;

}

void heapsort(int array[], int n) {

	int i;

	for(i = n/2 -1 ; i >= 0 ; i--) {
		heapify(array, i, n);
	}
 
     
       for( i = n-1; i > 0; i--) {
            swap(&array[0], &array[i]);
            heapify(array, 0, i-1);
}
 
}


void heapify(int array[] , int i, int n) {

         
      
 
	int item = array[i];

	int j = 2*i + 1;

	if(j < n -1 && array[j+1] > array[j]) 
		j++;

        if(j < n && item < array[j]) {
		swap(&array[j], &array[i]);
		heapify(array, j, n);    
	}  

}


void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;

}

