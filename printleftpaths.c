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
void printleafPaths( struct binaryTree *root);

void pushstack(char data);
void pop();
void displayStackElements();
void displayaddStackElements();

void printleafPathsSum(struct binaryTree *root);
int lengthBinaryTree(struct binaryTree *root);


int stack[100], top=-1;

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




 root1 = getnode('1');
 newnode = getnode('2');
 root1->left = newnode;

 newnode = getnode('3');
 root1->right  = newnode;

// newnode = getnode('4');
// root1->left->left = newnode;

// newnode = getnode('5');
// root1->left->right = newnode;

// newnode = getnode('6');
 //root1->right->left = newnode;

 //newnode = getnode('7');
 //root1->right->right = newnode;



int lengthTree = lengthBinaryTree(root1);



 printleafPathsSum(root1);


}

int lengthBinaryTree(struct binaryTree *root) {

  if (root == NULL )
   return 0;

  
   int lengthLeft = lengthBinaryTree(root->left);
   int lengthright = lengthBinaryTree(root->right);

   if ( lengthLeft >= lengthright)
    return lengthLeft + 1;
   else
    return lengthright + 1;

}


void printleafPathsSum(struct binaryTree *root) {

  if (root != NULL) {

    pushstack(root->data);
    printleafPathsSum(root->left);
    printleafPathsSum(root->right);


    if (root->left == NULL && root->right == NULL)
       displayaddStackElements();

    pop();

}


 return ;

}



void printleafPaths(struct binaryTree *root) {

  if (root != NULL) {

    pushstack(root->data);
    printleafPaths(root->left);
    printleafPaths(root->right);
    

    if (root->left == NULL && root->right == NULL)
       displayStackElements();

    pop();

}


 return ;

}


void pushstack(char data) {
   stack[++top] = data;
}


void pop() {
    top--;

}

 void displayStackElements() {

  int i = 0;

  printf("\n\n");

printf(" hello ");

  for( i=0;i <= top; i++ )
   printf("%c   ", stack[i]);

}



void displayaddStackElements() {


    int i = 0, total = 0;

  printf("\n\n");

  for( i=0;i <= top; i++ ) {
   printf("%c   ", stack[i]);
   total = total + (stack[i]-48);
     }

 printf(" and sum is %d\n", total);

}

struct binaryTree * getnode(char data) {
   
    struct binaryTree *newnode;
    newnode =  getmemoryspace();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


struct binaryTree * getnodeint(int data) {

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

