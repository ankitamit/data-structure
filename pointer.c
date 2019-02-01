#include<stdio.h>
#include<stdlib.h>

void passInt(int *p);

int main() {

 int *p;

  p = (int *) malloc(sizeof (int));

 *p = 12;


 printf("\n value of p  is %d and addrss is %ld\n",*p,p);


 passInt(&p);

 printf("\n value of p is %d\n",*p);

}

 void passInt(int **p) {

		 *p = *p+5;

 

}

