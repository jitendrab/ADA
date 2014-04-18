#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
  struct Node *next;
  int data;
}node;

node *front = NULL, *rear = NULL;
//front for insertion 
// rear for deletion   
//   rear as HEAD pointer
int isEmpty(){
  if(front == rear && front == NULL)
    return 1;
  return 0;
}

void Enqueue(int elem){
  if(isEmpty()){
    front = (node *)malloc(sizeof(node *));
    front->data = elem;
    front->next = NULL;
    rear = front;
    return;
  }
  front->next = (node *)malloc(sizeof(node *));
  front->next->data = elem;
  front->next->next = NULL;
  front = front->next;  
}

int Dequeue(){
  //dequeue from rear pointer
  if(front == rear && front != NULL){
    //delete single node
    int data = rear->data;
    rear = NULL;
    front = NULL;
    return data;
  }
  node *t = rear;
  int data = rear->data;
  rear = rear->next;  
  return data;
}

void print(){
  if(isEmpty()){
    printf("Empty Queue\n");
    return;
  }
  node *t = rear;
  printf("[rear]-->");
  while(t){
    printf("[%d]-->", t->data);
    t = t->next;
  }
  printf("[front]");
  printf("\n");
}

void call(){
  printf("Enter\n 1 : Enqueue\t 2 : Dequeue\t 3 : print\t 4 : exit\n");
  int check = 0;
  scanf("%d", &check);
  if(check == 1){
    int elem = 0;
    printf("enter element:");
    scanf("%d", &elem);
    Enqueue(elem);
    call();
  }
  else if(check == 2){
    if(!isEmpty()) {
      int elem = Dequeue();
      printf("elem dequeued: %d\n", elem);
    }
    else{
      printf("Error: Empty Queue\n");
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
