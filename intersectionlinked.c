#include<stdio.h>
#include<stdlib.h>


 struct linkedlist {
 int data;
 struct linkedlist *next;
};


typedef struct linkedlist linkedlist;

void display(linkedlist *root);
linkedlist * getElement(int element);
linkedlist * getmemoryspace();
linkedlist * getIntersectionpoint(linkedlist *root, linkedlist *root1);
linkedlist * move(linkedlist *root, int movepointer);
int getLength(linkedlist *root);

linkedlist stack1[100], stack2[100]
int top1 = -1, top2= -1;

int main() {

  linkedlist *root, *root1;

  root = getElement(1);

  root->next = getElement(2);
  root->next->next = getElement(3);
  root->next->next->next = getElement(6);
  root->next->next->next->next = getElement(7);

  printf("\n ELement of first linkedlist is \n");
  display(root);

  push_1(root);
  
  root1 = getElement(4);
  root1->next = root->next->next->next->next->next;

  printf("\n Element of second linked list is \n");
  display(root1);
 

  linkedlist *intersectionNode =   getIntersectionpoint(root, root1);

 if(intersectionNode != NULL)
 printf("\n Intersection point data is %d\n", intersectionNode->data);
  else
  printf("\n No intersection node found\n");

 return 0;

}

linkedlist * getIntersectionNewway(linkedlist *root, linkedlist *root) {


}
linkedlist * getIntersectionpoint(linkedlist *root, linkedlist *root1) {


      if (root == NULL || root1 == NULL)
          return NULL;
   


    int getLengthfirst = getLength(root);
    int getLengthSecond = getLength(root1);
   
    int getDifference = abs(getLengthfirst-getLengthSecond);


    if ( getLengthfirst > getLengthSecond)
         root = move(root, getDifference);
    else if (getLengthfirst < getLengthSecond)
         root1 = move (root1, getDifference);


     while (root != root1 && root!= NULL && root!= NULL) {
         root = root->next;
         root1 = root1->next;
      }
 

      if (root = root1)
          return root;


      return NULL;
}

  
linkedlist * move(linkedlist *root, int movepointer) {

  while(movepointer != 0) {
      root=root->next;
      movepointer--;
  }

  return root;
}


int getLength(linkedlist *root) {

 int count = 0;

   while(root!=NULL) {
     count++;
     root=root->next;
}
  return count;

}

void display(linkedlist *root) {

 while(root!= NULL ) {

  printf("\n Element is %d\n", root->data);
  root = root->next;
}

}

linkedlist * getElement(int element) {


   linkedlist *memory = getmemoryspace();
   memory->data = element;
   memory->next = NULL;
   return memory;

}
linkedlist * getmemoryspace() {

 return (linkedlist *)malloc(sizeof(linkedlist));
}
