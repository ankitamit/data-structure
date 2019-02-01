#include<stdio.h>
#include<stdlib.h>


struct Node {
  int data;
  struct Node *next;
};

void printData(struct Node *);
void insertDataBegin(struct Node **head, int element);



struct Node * reverse( struct Node *head, struct Node *prevPointer,  int k);

int main() {

    struct Node *head = NULL,  *newNode, *pointer;
 
    int element, k;

    head = (struct Node *)malloc(sizeof(struct Node));
 
    printf("\n Enter element Press -1 for exit\n");

    scanf("%d", &head->data);

    head->next = NULL;

    pointer = head;
  

  while(1) {

  printf("\n Enter element \n");

  scanf("%d", &element);


  

  if(element == -1)
     break;




   newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = element;
   pointer->next = newNode; 
   newNode->next = NULL;
   pointer = pointer->next;
}


 printf("\n\n Printing of Data here \n\n");
 printData(head);  

 printf("\n\n After inserting element at begining \n\n");

 printf("\n Enter the value of k here \n");

 scanf("%d", &k);

 struct Node *prev = NULL;

head = reverse(head,prev, k);


 printf("\n\n The elements are \n\n");
 printData(head);

}   


struct Node * reverse( struct Node *head, struct Node *prevPointer,  int k) {


  struct Node  *next= NULL,  *prev= NULL, *current = head;

 int i = 0;

 
  while ( current != NULL && i < k) {

    next  = current->next;
    current->next = prev;
    prev = current;
    current = next;
    i++;
 }


    
 if(current != NULL) {
 
     head->next = prevPointer;
     reverse(current, prev,  k);  
 }

  head->next = prevPointer;
 
 return prev;
 
}




void printData(struct Node *head) {


    while(head != NULL ) { 
     printf("\n%d\n",head->data);
     head = head->next;
   }



}
