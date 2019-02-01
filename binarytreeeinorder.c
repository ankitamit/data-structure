#include<stdio.h>
#include<stdlib.h>


struct binarytree {

 char c;
 struct binarytree *left;
 struct binarytree *right;
};

struct binarytree * getmemoryspace();
int getheightbinarytree(struct binarytree *root);
void printlevelorder(struct binarytree *root, int height);
void printNodesInorder(struct binarytree *root, int level);
void leftorderprintview(struct binarytree *root, int height);
void printleftview(struct binarytree *root, int level, int *);
void printrightsideview(struct binarytree *root, int level, int *);
void rightorderprintview(struct binarytree *root, int height);

int main() {

struct binarytree *root, *newnode, *newnoderight, *newnodeagain, *newnoderightagain;

root = getmemoryspace();
root->c = 'A';
root->left = NULL;
root->right = NULL;

newnode = getmemoryspace();
newnode->c = 'B';

root->left  = newnode;

newnoderight = getmemoryspace();
newnoderight->c = 'C';
newnoderight->left = NULL;
newnoderight->right = NULL;


root->right = newnoderight;


newnodeagain = getmemoryspace();
newnodeagain->c = 'D';
newnodeagain->left = NULL;
newnodeagain->right = NULL;

newnoderightagain = getmemoryspace();
newnoderightagain->c = 'E';
newnoderightagain->left = NULL;
newnoderightagain->right = NULL;



newnode->left  = newnodeagain;
newnode->right = newnoderightagain;



int getheight = getheightbinarytree(root);
printf("\n height of binary treee is %d\n\n", getheight);


printlevelorder(root, getheight);



leftorderprintview(root, getheight); 
rightorderprintview(root, getheight);

return 0;

}

void printlevelorder(struct binarytree *root, int height) {

     int i = 0;

  for(i = height; i>0; i--) {
    printNodesInorder(root, i);
}

}

void leftorderprintview(struct binarytree *root, int height) {

    int i = 0, j, status = 0;

    for(i = height; i>0; i--) {
      status = 1;
     printleftview(root, i,&status);
}
}


void rightorderprintview(struct binarytree *root, int height) {

    int i = 0, j, status = 0;

    for(i = 1; i<= height; i++) {
     status = 1;
     printrightsideview(root, i, &status);
}
}




void printleftview(struct binarytree *root, int level, int * status) {


    if(root == NULL || *status == 0)
        return ;

     if( level == 1  && *status == 1)  {
     printf(" left view node is %c\n", root->c);
     *status = 0;
    }
    else {
     printleftview(root->left, level-1, status );
     printleftview(root->right, level-1, status);
}




}

void printrightsideview(struct binarytree *root, int level, int *status) {
   
      if(root == NULL || *status == 0)
        return ;

     if( level == 1  && *status == 1)  {
     printf(" right view node is %c\n", root->c);
     *status = 0;
    }
    else {
     printrightsideview(root->right, level-1, status );
     printrightsideview(root->left, level-1, status);
}

}



void printNodesInorder(struct binarytree *root, int level) {


   if(root == NULL)
      return;

   if(level == 1)
   printf("\n Data is %c\n", root->c); 
  else {
  printNodesInorder(root->left, level-1);
  printNodesInorder(root->right, level-1);
}
}


int getheightbinarytree(struct binarytree *root) {


   if(root == NULL) {
       return 0;
}

  int leftheight = getheightbinarytree(root->left);
  int rheight = getheightbinarytree(root->right);

  if(leftheight > rheight)
   return leftheight+1;
  else
    return rheight+1;
   
}



struct binarytree * getmemoryspace() {

   return (struct binarytree *)malloc(sizeof(struct binarytree));

}




