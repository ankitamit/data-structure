#include<stdio.h>

int binarysearch( int [], int , int, int);



int main() {


 int array[] = {2, 3, 8, 12, 17, 23, 29};

 int count = sizeof(array)/sizeof(int);



 int position = binarysearch(array, 0,  count-1, 29);

 if(position != -1)
   printf("\n position returned is %d\n", position+1);
 else
   printf(" Element is not found \n");

 return -1;

}


int binarysearch(int *array, int low, int high, int search) {




    if (low > high)
      return -1;

 
  
    int mid = (low+high)/2;

   
    if( *(array+mid) == search)
          return mid;
    else if( *(array+mid) < search)
         low = mid+1;
    else if( *(array+mid) > search)
         high = mid-1;
    
   
    return binarysearch (array, low, high, search);
   
}
