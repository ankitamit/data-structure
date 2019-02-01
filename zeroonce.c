#include<stdio.h>
#include<stdlib.h>


void countzeroonetwo(int array[], int number, int *countzero, int *countone, int *counttwo);

int main() {


int n, *array, i, countzero  = 0, countone = 0, counttwo = 0;

printf("\n Enter the number of  elements of array \n");
scanf("%d", &n);

array = (int *)malloc(sizeof (int)*n);

printf("\n Enter the elements of array \n");

for(i = 0;i<n; i++)
 scanf("%d", &array[i]);


 countzeroonetwo(array,n, &countzero, &countone, &counttwo);

 int j = 0;

  for ( i = 0 ;i< countzero;i++) {
    array[j] = 0;
    j++;
  }

  for ( i = 0 ;i< countone;i++) {
    array[j] = 1;
    j++;
  }

  for ( i = 0 ;i< counttwo;i++) {
    array[j] = 2;
    j++;
  }




 printf("\n Elements of array are \n");

 for(i= 0 ;i<n ; i++)
   printf("%d\n", array[i]);

  return 0;
}


void countzeroonetwo(int array[], int number, int *countzero, int *countone, int *counttwo) {


 int i;

 for(i = 0;i< number;i++) {

  if( array[i] == 0)
    (*countzero)++;

  if( array[i] == 1)
    (*countone)++;

 if( array[i] == 2)
    (*counttwo)++;
}

}


