#include<stdio.h>
#include<stdlib.h>


struct linkedlist {

  int element;
  struct linkedlist *ptr;

};

typedef struct linkedlist linkedlist;


linkedlist * startpointloop(linkedlist *loopdetect, linkedlist *start);

linkedlist * getmemoryspace();
void displayData(linkedlist *head);
linkedlist * insertdata(linkedlist *root, int element);
linkedlist * findmiddlelinkedlist(linkedlist *head);
linkedlist *  findmiddlelinkedlistnewway(linkedlist *head);
linkedlist *  reverselinkedlist(linkedlist **head);
int lengthRecursive(linkedlist * head);
int searchIterative(linkedlist *head, int element);
int searchRecursive(linkedlist *head, int element, int *); 
linkedlist * getnthnode(linkedlist *head, int position);

linkedlist *nthnodefromend(linkedlist *head, int position);
linkedlist* detectloop(linkedlist *head);

linkedlist *removeLoop (linkedlist *loopdetect, linkedlist *start);

int lengthloop(linkedlist *startpoint) ;


int main() {


  linkedlist *head = NULL, *newnode = NULL, *newdata1 , *newdata2, *newdata3, *newdata4, *newdata5;

  head = insertdata(head, 12);
   
  newdata1 = insertdata(head, 13);

  newdata2 = insertdata(head, 14);
  newdata3 = insertdata(head, 15); 
  newdata4 = insertdata(head, 16);
  newdata5 = insertdata(head, 17);


//  head->ptr->ptr->ptr = head;

  head->ptr->ptr->ptr->ptr->ptr->ptr = newdata2;


 linkedlist *loopdetect =   detectloop(head);

  if (loopdetect != NULL) {
  linkedlist *startpoint = startpointloop(loopdetect, head);
  
   printf("\n Start node is %d\n", startpoint->element);


  int length = lengthloop(startpoint);  


printf("\n length of loop is %d\n", length);

}


 if (loopdetect == NULL)
  printf("\n No loop exists \n");
 else
   printf("\n Loop exists \n");


// displayData(head);
   
//  detectloop(head); 
  
 
 return 0;

}

int lengthloop(linkedlist *startpoint) {

 linkedlist *endpoint = startpoint;

 int length = 0;

  while(startpoint->ptr != endpoint) {
    startpoint = startpoint->ptr;
    length++;    
 } 

  length++;
  return length;
}



linkedlist * startpointloop(linkedlist *loopdetect, linkedlist *start) {


   while ( loopdetect != start ) {
     loopdetect = loopdetect->ptr;
     start = start->ptr;
}
   
   return loopdetect;

}


linkedlist * detectloop(linkedlist *head) {
  
   linkedlist *slowptr = head, *fastptr = head;


  while( slowptr && fastptr && fastptr->ptr) {

    slowptr = slowptr->ptr;
    fastptr = fastptr->ptr->ptr;

 
   if( slowptr == fastptr)
      return fastptr;

}

     return NULL;

}

void displayData(linkedlist *head) {


  while(head != NULL) {
    printf("\n data is %d\n", head->element);
    head = head->ptr;
}

}





linkedlist * insertdata(linkedlist *root, int element) {


    if( root == NULL)   {


       root = getmemoryspace();
       root->element = element;
       root->ptr = NULL;
       return root;
}
   else {

     linkedlist *newnode = getmemoryspace();
     newnode->element = element;
     newnode->ptr = NULL;


     while ( root->ptr != NULL)
          root = root->ptr;
 
     root->ptr = newnode;  
     return newnode;   
}   


}



linkedlist * getmemoryspace() {

   return (linkedlist *)malloc(sizeof (linkedlist));

}
