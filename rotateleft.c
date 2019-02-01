#include<stdio.h>
#include<stdlib.h>

void leftrotateelement(int array[], int number, int rotation);
void leftrotationnewway(int array[], int number, int rotation);
void  leftrotation(int array[], int n) ;

int main() {


 int * array, n, i, rotation;

 printf("\n Enter number of elements of array \n");
 scanf("%d", &n);

  array = (int *)malloc(sizeof(n));

 printf("\n Enter elements of array \n");
 
 
 for(i = 0; i<n; i++ ) {

 scanf("%d", &array[i]);

 }


 printf("\n Enter number of rotations \n");


 scanf("%d", &rotation);


 leftrotationnewway( array, n, rotation);
/* 
 
 if(n%rotation) {

   if( rotation > n)
     rotation = rotation%n;

  leftrotateelement(array, n, rotation);

  }
*/

 printf("\n The elements of array after rotation is \n\n");
  for(i=0 ; i<n;i++ )
  printf(" %d \n", array[i]);
 
  return 0;
}

void leftrotationnewway(int array[], int number, int rotation) {


  int i = 0;


  for ( i = 0;i<rotation; i++)
    leftrotation(array, number);




}

void  leftrotation(int array[], int n) {


   int i = 0, temp = array[0];

  
   for(i=0 ;i<n-1; i++)
    array[i] = array[i+1];


   array[i] = temp;
}




void leftrotateelement(int array[], int number, int rotation) {


  int temp[rotation], i, j, k = 0;

 for( j = 0 ; j < rotation; j++)
   temp[j] = array[j];


 for( i = 0;i< number-rotation; i++)
    array[i] = array[i+rotation];


 for (;i<number;i++) {
    array[i] = temp[k];
    k++;
 }
 

}
