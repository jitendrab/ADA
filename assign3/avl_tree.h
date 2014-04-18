#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  int h;
  struct Node *left, *right;
}node;

//function prototypes
node* insert(node *root, int data);
int balance_factor(node *root);
int max(int a, int b);
void is_balanced(node *root);
node* rotate_left(node *z);
node* rotate_right(node *y);
void print_inorder(node *root);
int height(node *root);
#endif
