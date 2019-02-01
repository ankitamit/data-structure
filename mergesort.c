#include<stdio.h>
#include<limits.h>

#define MAXELEMENT 100

void mergesort(int array[], int p, int r);
void merge(int array[], int p, int q, int r);

int main() {


	int array[MAXELEMENT], n, i;

	printf("\n Enter the number of  elements of array\n");
	scanf("%d",&n);

	printf("\n Enter the elements of array\n");

	for(i=0; i<n ;i++) {

		scanf("%d",&array[i]);
	}


	mergesort(array,0, n-1);


	printf("\n Elements of array are \n");


	for(i=0;i< n;i++) {

		printf("%d\n", array[i]);
	}

	return 0;

}


void mergesort(int array[], int p, int r) {

	int q;


	if(r>p) {

		q = (p+r)/2;

		mergesort(array, p, q);
		mergesort(array, q+1, r);
		merge(array, p, q, r);
	}

}



void merge(int array[], int p, int q, int r) {


	int left[50], right[50];

	int leftCount =  q-p+1;
	int rightCount = r-q, i, j;

	for(i = 0;i< leftCount; i++) {
		left[i] = array[p+i];
	}

	for(j = 0;j < rightCount; j++) {
		right[j] = array[q+j+1];
	}


	left[i] = INT_MAX;
	right[j] = INT_MAX;


	i=0;
	j=0;


	for(int k = p; k<=r; k++) {

		if(left[i] <= right[j]) {
			array[k] = left[i];
			i++;
		} else {
			array[k] = right[j];
			j++;
		}
	}


} 
