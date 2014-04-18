#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node *left, *right;
}node;

void preorder(node *head){
  if(head == NULL)
    return;
  printf("%d ", head->data);
  preorder(head->left);
  preorder(head->right);
}

void inorder(node *head){
  if(head == NULL)
    return;
  inorder(head->left);
  printf("%d ", head->data);
  inorder(head->right);
}

void postorder(node *head){
  if(head == NULL)
    return;
  postorder(head->left);
  postorder(head->right);
  printf("%d ", head->data);
}

node* search(node *head, int data){
  if(head == NULL)
    return NULL;
  if(head->data == data)
    return head;
  else if(data > head->data)
    return search(head->right, data);
  else if(data < head->data)
    return search(head->left, data);
}

void insert(node **head, int data){
  if(*head == NULL){
    *head = (node *)malloc(sizeof(node *));
    (*head)->data = data;
    (*head)->left = NULL;
    (*head)->right = NULL;
    return;
  }
  if(data > (*head)->data)
    insert(&(*head)->right, data);
  else 
    insert(&(*head)->left, data);
}

void call(node *head){
  int value = 0;
  printf("\nTo Search Enter value\t Enter -1 to Exit(): ");
  scanf("%d", &value);
  if(value == -1){
    exit(0);
  }
  node *temp = search(head, value);
  if(temp == NULL){
    printf("no\n");
  }
  else{
    printf("yes\n");
  }
  call(head);
}
main(int argc, char *argv[]){
  //printf("%d\n", argc);
  if(argc > 3 || argc == 1){
    fprintf(stderr, "Usage: <binary> <input file> <s to search(optinoal)>\n");
    exit(0);
  }
  FILE *infile;
  int value = 0;
  node *head = NULL;
  infile = fopen(argv[1], "r");
  if(infile == NULL){
    fprintf(stderr, "Error: unable to open file\n");
    exit(0);
  }
  while(fscanf(infile, "%d", &value) != EOF){    
    //printf("v: %d\n", value);
    insert(&head, value);
  }
  //print preorder , inorder, postorder
  printf("pre: ");
  preorder(head);
  printf("\n");
  
  printf("in: ");
  inorder(head);
  printf("\n");

  printf("post: ");
  postorder(head);
  printf("\n");

  //search for a number
  if(argc == 3 && *argv[2] == 's'){
    call(head);
  }
}
    
