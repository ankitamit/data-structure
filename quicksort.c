#include<stdio.h>

  void quicksort(int [], int , int );
  int partition(int [], int , int);
  void swap(int *, int *);

int main() {



   int array[100],n,i;

   printf("\n Enter number of elements of array\n");
   scanf("%d", &n);

   
   printf("\n Enter elements of array \n");
   for(i = 0;i< n; i++) {
   scanf("%d", &array[i]);
}

   quicksort(array, 0, n-1);

   printf("\n ELements of array is \n");

   for(i= 0; i<n; i++) {
   printf("%d\n",array[i]);

}
}
 
    
    
  void quicksort(int array[], int p, int r) {

     if(r > p) {

      int q = partition(array, p, r);


      quicksort(array, p, q-1);
      quicksort(array, q+1, r);

}
}



  int partition(int array[], int p, int r)  {

      int pivot = array[r], i = p-1, j;

   
      for(j = p ;j < r ; j++) {
        if(array[j] <= pivot) {
          i++;  
          swap(&array[i], &array[j]);
     
      }
    }
        swap(&array[i+1], &array[r]);
        return i+1;


}


   void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}
