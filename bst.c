#include<stdio.h>
#include<stdlib.h>

struct bst {
  int data;
  struct bst *left, *right;
};


void inorder(struct bst *head);
struct bst * insertnewnode(int element);
struct bst *  insertnode(struct bst *head, int element);
struct bst *insertnewway(struct bst *head, int element);
int maxnode(struct bst *head);
int minnode(struct bst *head);
int search(struct bst *head, int);
struct bst * delete(struct bst *head,  int);


int main() {


 struct bst *head, *node;

 int element, searchelement, deleteelement;

 head = (struct bst *)malloc(sizeof(struct bst));

 printf("\n Enter the first element data \n");
 scanf("%d", &head->data);
 
 head->left = NULL;
 head->right = NULL;




 printf("\n Now Enter the elements  Press NULL to exit \n");

 while(1) {

   scanf("%d", &element);

  
   if(element == -1)
    break;


   insertnewway(head, element);


}

  inorder(head);

 printf("\n The maximum node in binary search tree is \n");

 printf("%d\n", maxnode(head));

 printf("\n minimum node in binary search tree is \n");
 printf("%d\n", minnode(head));


 printf("\n Enter node to search in binary search tree\n");

 
 scanf("%d", &searchelement);

 int elementfound =  search(head, searchelement);

printf("\n returned is %d\n", elementfound);

 if(elementfound)
  printf("\n ELement is found \n");
 else
  printf("\n Element is not found \n");

 printf("\n Enter the value of element to be deleted \n");
 scanf("%d", &deleteelement);

 delete(head, deleteelement);


 
 inorder(head);


/*
 printf("\n Enter the new value of element to be deleted \n");
 scanf("%d", &deleteelement);
 
 delete(head, deleteelement);




  printf("\n Enter the new element to be deleted \n");
  scanf("%d", &deleteelement);

  delete(head, deleteelement);
 */

  return 0;
}



struct bst *  delete(struct bst *head,  int element) {


  if(head == NULL)
     printf(" Node not found ");


  // Leaf Node


  if(head->data == element) {

  if(head->right == NULL && head->left == NULL) {
   free(head);
   return NULL;
  }
  else if(head->left == NULL || head->right == NULL) {
   struct bst * temp = head->right == NULL ? head->left : head->right;
   free(head);
   return temp;
  }
  else if(head->left != NULL && head->right != NULL) {

   int inordersuccessor = minnode(head->right);
   head->data = inordersuccessor;
   head->right = delete(head->right, inordersuccessor);
   
}
}

  else if(element > head->data) {

     head->right = delete(head->right, element);
}
  else if(element < head->data) {

    head->left = delete(head->left, element);
}

}

int search(struct bst *head, int element) {

   if(head == NULL) {
     return 0;
}

   if(element > head->data)
    search(head->right, element);
   else if (element < head->data)
    search(head->left, element);
   else if(element == head->data) {
   return 1;
}

}


int minnode(struct bst *head) {


   while(head->left != NULL)
     head = head->left;


    return head->data;


}


int maxnode(struct bst *head) {


  while(head->right != NULL)
    head = head->right;

  return head->data;


}






void inorder(struct bst *head) {


   if(head == NULL)
   return;
 

   inorder(head->left);
   printf("\n element is %d\n", head->data);
   inorder(head->right);
}


struct bst * insertnewnode(int element) {
  
     struct bst *newnode = (struct bst *)malloc(sizeof (struct  bst));
     newnode->data = element;
     newnode->left = NULL;
     newnode->right = NULL;
     return newnode;
}



struct bst * insertnode(struct bst *head, int element) {


   if(element > head->data) {

      if(head->right != NULL) 
      insertnode(head->right, element);
       else
       head->right =  insertnewnode(element);
  }

   else if(element < head->data) {
 
      if(head->left != NULL)
        insertnode(head->left, element);
      else
        head->left = insertnewnode(element); 
   }

    
   return head;

}

struct bst *insertnewway(struct bst *head, int element) {

     if(head == NULL)
        return insertnewnode(element); 

     if(element > head->data)
        head->right = insertnewway(head->right, element);
     else if(element < head->data)
        head->left = insertnewway(head->left, element);


       return head;
}

