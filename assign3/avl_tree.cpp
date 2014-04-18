#include "avl_tree.h"

int height(node *root){
  if(root == NULL)
    return 0;
  return root->h;
}

node* insert(node *root, int data){  
  if(root && root->data == data)
    return root;
  if(root == NULL){
    root = (node *)malloc(sizeof(node ));
    root->data = data;
    root->h = 1;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  printf("data: %d ", root->data);
  if(root->data < data){
    root->right = insert(root->right, data);
  }
  else{
    root->left = insert(root->left, data);
  }
  // update the height
  root->h = max(height(root->left), height(root->right)) + 1;
  
  //check if the root node is unbalanced
  // there can be four cases
  int bf = balance_factor(root);
  printf("bf is: %d\n", bf);
  if(bf == 2){
    if(balance_factor(root->left) == -1){
      //left-right case
      printf("left-right case..\n");
      root->left = rotate_left(root->left);
    }
    // left-left case
    printf("left-left case...\n");
    return rotate_right(root);
  }
  else if(bf == -2){
    if(balance_factor(root->right) == 1){
      //the right-left case
      printf("right-left case...\n");
      root->right = rotate_right(root->right);
    }
    // right-right case
    printf("right-right case...\n");
    return rotate_left(root);
  }
  // compiler would not tell you anything if you forget 
  // to write this return statement
  return root;
}

int balance_factor(node *root){
  int h = height(root->left) - height(root->right);
  return h;
}

node* rotate_left(node *z){
  node *y = z->right;
  node *T2 = y->left;
    
  // perform the rotation and update the parent pointers
  y->left = z;
  z->right = T2;
  
  z->h = max(height(z->left), height(z->right)) + 1;
  y->h = max(height(y->left), height(y->right)) + 1;
  return y;
}

node* rotate_right(node *y){
  node *x = y->left;
  node *T3 = x->right;  
  // perform the rotations 
  x->right = y;
  y->left = T3;
  
  //update the heights
  x->h = max(height(x->left), height(x->right)) + 1;
  y->h = max(height(y->left), height(y->right)) + 1;  
  return x;
}

int max(int a, int b){
  if(a > b)
    return a;
  return b;
}
void print_inorder(node *root){
  if(!root)
    return;
  print_inorder(root->left);
  printf("%d ", root->data);
  print_inorder(root->right);
  return;
}

int main(){
  node *root = NULL;
  int n = 0;
  int flag = 1;
  printf("-999: to quit\nEnter elements: \n");
  //  root = insert(root, 1);
  //root = insert(root, 5);
  //root = insert(root, 3, NULL);
  while(flag){
    scanf("%d", &n);
    if(n == -999)
      flag = 0;
    else
      root = insert(root, n);
  }
  
  print_inorder(root);
  printf("\n");
  printf("height of tree: %d\n", root->h);
  return 0;
}
