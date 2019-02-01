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
void levelordertransversal(struct binaryTree *root);

struct  binaryTree * queue[100];
int rear=-1, front=-1;


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

 levelordertransversal(root);

}

void levelordertransversal(struct binaryTree *root) {


    if (root == NULL)
       return;

 
    queue[0] = root;
    front = rear = 0;

    
    
    while ( rear >= front) {


      struct binaryTree* deque = queue[front];

     printf("\n data is %c\n", deque->data);

      if (deque->left != NULL )
        queue[++rear] = deque->left;

 
      if (deque->right != NULL)
        queue[++rear] = deque->right;

     
       front++;
     }    




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

