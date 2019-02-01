#include<stdio.h>
#include<stdlib.h>


struct linkedlist {

  int element;
  struct linkedlist *ptr;

};

typedef struct linkedlist linkedlist;


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

int main() {


  linkedlist *head = NULL, *newnode = NULL;

  head = insertdata(head, 12);
   
  insertdata(head, 13);
  insertdata(head, 14);
  insertdata(head, 15); 
  insertdata(head, 16);
  insertdata(head, 17);
  insertdata(head, 18);
  insertdata(head, 19);
  insertdata(head, 20);

  displayData(head);
  
  int lengthrecursive =  lengthRecursive(head);

 printf("\n length recursive is %d\n", lengthrecursive);


  int searchElement = searchIterative(head, 15);

  printf("\n search element position is %d\n", searchElement);

   
   int countPosition = 0;

   searchElement  = searchRecursive(head, 18, &countPosition);

  printf("\n Search Element Recursive position is %d\n", countPosition);


 linkedlist * nthnode = getnthnode(head, 4);

  printf("\n 4th node from begining is %d\n", nthnode->element);

  linkedlist* middlelinkedlist = findmiddlelinkedlist(head);


  if(middlelinkedlist != NULL)
  printf("\n middle of linked list is %d\n", middlelinkedlist->element);



   linkedlist *newmiddle = findmiddlelinkedlistnewway(head);

   if(newmiddle != NULL)
   printf("\n middle of linked list is %d\n", newmiddle->element);

    reverselinkedlist(&head);

   printf("\n After reversing linked list is \n\n");
    displayData(head);



  
  

 return 0;

}


linkedlist * getnthnode(linkedlist *head, int position) {

  
  int count = 1;

  if( head == NULL)
      return NULL;
 

 if ( position == count)
   return head;



  return getnthnode(head->ptr, position-1);

}

int searchRecursive(linkedlist *head, int element, int * count) {


  if(head == NULL)
     return -1;

   *count = *count + 1;

  if( head->element == element)
      return *count;


   return searchRecursive(head->ptr, element, count);
  

}
int searchIterative(linkedlist *head, int element) {


   int count = 0;

  while(head != NULL) {
 

   count = count + 1; 
   if( head->element == element)
       return count;


   head = head->ptr;
   
  }


  return -1;

}

int lengthRecursive(linkedlist * head) {


     if(head == NULL)
       return 0;

 
     return 1+lengthRecursive(head->ptr);    


}


linkedlist * reverselinkedlist(linkedlist **head) {

   
     linkedlist *start = &(**head);


     linkedlist *prev = NULL, *current = start, *next = NULL;

  
     while(current != NULL) {

      next = current->ptr;
      current->ptr = prev;
      prev = current;
      current = next;
   }

    (*head) = prev;
}

  

linkedlist *  findmiddlelinkedlistnewway(linkedlist *head) {


   int countnodes = 0;


   linkedlist *start = head;
   
   while( head != NULL) {
    head = head->ptr;
    countnodes++; 
  } 

   for(int i = 0; i< (countnodes/2); i++) {
      start = start->ptr;
  }   

   return start;

}



linkedlist * findmiddlelinkedlist(linkedlist *head) {



  linkedlist *p, *q;

    p = head;
    q = head;


    while( q != NULL && q->ptr != NULL) {
      p = p->ptr;
      q = q->ptr->ptr;
    }  
 
     return p;
  
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
}   


}



linkedlist * getmemoryspace() {

   return (linkedlist *)malloc(sizeof (linkedlist));

}
