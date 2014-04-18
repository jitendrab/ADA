#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
typedef struct Node{
  int data;
  struct Node *next;
}node;

node *stackHead = NULL;
node *listHead = NULL;

// isEmpty()
int isEmpty(){
  if(stackHead == NULL){
    //fprintf(stderr, "error: stack is empty\n");
    return 1;
  }
  return 0;
}
  
//push into the stack
void push(int elem){
  if(isEmpty()){
    listHead = (node *) malloc(sizeof(node *));
    listHead->data = elem;
    stackHead = listHead;
    listHead->next = NULL;
    return;
  }
  node *temp = (node *)malloc(sizeof(node *));
  temp->data = elem;
  temp->next = NULL;
  stackHead->next = temp;
  stackHead = temp;
}

int pop(){
  if(listHead == stackHead){
    int data = listHead->data;
    listHead = NULL;
    stackHead = NULL;
    return data;
  }
  node *temp = listHead;
  while(temp->next != NULL && temp->next->next != NULL){
    temp = temp->next;
  }
  int data = temp->next->data;
  temp->next = NULL;  
  stackHead = temp;
  return data;
}

void print(){
  node *temp = listHead;
  if(isEmpty()){
    printf("Error: stack is Empty\n");
    return;
  }
  while(temp != NULL){
    printf("[%d]-->", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
    
void call(){
  printf("Enter\n 1 : to push\t 2 : to pop\t 3 : to print stack\t 4 : to exit\n");
  int check = 0;
  scanf("%d", &check);
  if(check == 1){
    int elem = 0;
    printf("enter element:");
    scanf("%d", &elem);
    push(elem);
    call();
  }
  else if(check == 2){
    if(!isEmpty()) {
      int elem = pop();
      printf("elem popped: %d\n", elem);
    }
    else{
      printf("Error: Stack is Empty\n");
    }
    call();
  }
  else if(check == 3){
    print();
    call();
  }
  else if(check == 4){
    exit(0);
  }
  else{
    call();
  }
}

main(){  
  call();
}
