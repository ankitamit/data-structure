#include<stdio.h>
#include<stdlib.h>


struct binaryTree {

  char data;
  struct binaryTree *left;
  struct binaryTree *right;
};

void inorder(struct binaryTree *root);
void mirror ( struct binaryTree *root);
struct binaryTree * getnode(char data);
struct binaryTree * getmemoryspace();
int ismirror(struct binaryTree *root1, struct binaryTree *root2);
int isidentical(struct binaryTree *root, struct binaryTree *root1);

int subtree(struct binaryTree *root, struct binaryTree *root1);

int main() {


 struct binaryTree *root, *root1, *newnode;


 root = getnode('a');
 newnode = getnode('b');
 root->left = newnode;

 newnode = getnode('c');
 root->right  = newnode;

 newnode = getnode('d');
 root->left->left = newnode;

 newnode = getnode('e');
 root->left->right = newnode;

 newnode = getnode('f');
 root->right->left = newnode;

 newnode = getnode('g');
 root->right->right = newnode;
 


 root1 = getnode('d');
/* newnode = getnode('d');
 root1->left = newnode;

 newnode = getnode('e');
 root1->right  = newnode;

 newnode = getnode('d');
 root1->left->left = newnode;

 newnode = getnode('e');
 root1->left->right = newnode;

 newnode = getnode('f');
 root1->right->left = newnode;

 newnode = getnode('g');
 root1->right->right = newnode;
*/


 int issubtree = subtree(root, root1);
 

 if (issubtree)
  printf("\n One tree is subtree of  another\n");
 else
  printf("\n One tree is not subtree of another\n");

}



int subtree(struct binaryTree *root, struct binaryTree *root1) {

    if (root1 == NULL)
         return 1;

    if (root == NULL)
        return 0;


     
    if( isidentical (root, root1 )) 
        return 1;


  

    return subtree(root->left, root1) || subtree(root->right, root1);
    

}

int isidentical(struct binaryTree *root, struct binaryTree *root1) {


   if (root == NULL && root1 == NULL)
      return 1;


   if (root != NULL && root1 != NULL)  {


    if (root->data == root1->data)
    return isidentical(root->left, root1->left) && isidentical(root->right, root1->right);
  
    }


   return 0;


}

int ismirror(struct binaryTree *root1, struct binaryTree *root2) {



  if (root1 == NULL && root2 == NULL)
      return 1;
 
  if (root1 == NULL || root2 == NULL)
       return 0;


  if( root1->data == root2->data) {
    
     return ismirror(root1->left, root2->right) && ismirror(root1->right, root2->left);
 } 

  return 0;

}

void inorder(struct binaryTree *root) {


  if(root == NULL)
   return;

  inorder(root->left);
  printf("\n data is %c\n", root->data);
  inorder(root->right);
}

void mirror ( struct binaryTree *root) {


   if (root )  {

   mirror(root->left);
   mirror(root->right);

   struct binaryTree *node = root->left;
   root->left = root->right;
   root->right = node;
  } 

   return ;
}

struct binaryTree * getnode(char data) {
   
    struct binaryTree *newnode;
    newnode =  getmemoryspace();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct binaryTree * getmemoryspace() {

   return (struct binaryTree*)malloc(sizeof (struct binaryTree));
}

