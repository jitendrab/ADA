#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int front = 0, rear = 0;
//isEmpty()
int isEmpty(int *Q){
  if(front == rear && front == 0){
    return 1;
  }
  return 0;
}
// isFull()
int isFull(int *Q){
  if(front == rear && front == MAX){
    fprintf(stderr, "queue is Full\n");
    return 1;
  }
  return 0;
}

// enqueue()
void Enqueue(int *Q, int elem){
  if(isFull(Q)){
    return;
  }
  Q[front] = elem;
  front++;
}
// dequeue
int Dequeue(int *Q){
  if(isEmpty(Q)){
    return;
  }
  int temp = Q[rear];
  rear++;
  return temp;
}

// print Queue
void print(int *Q){
  if(isEmpty(Q)){
    printf("Error: Empty Queue\n");
    return;
  }
  int i = 0;
  for(i = front-1; i >= rear; i--){
    printf("[%d] ", Q[i]);
  }
}

void call(int *Q){  
  printf("Enter\n 1 : Enqueue\t 2 : Dequeue\t 3 : print Queue\t 4 : to exit\n");
  int check = 0;
  scanf("%d", &check);
  if(check == 1){
    int elem = 0;
    printf("enter element:");
    scanf("%d", &elem);
    Enqueue(Q, elem);
    call(Q);
  }
  else if(check == 2){
    if(!isEmpty(Q)){
      int elem = Dequeue(Q);
      printf("elem dequeued: %d\n", elem);
    }
    else
      printf("Error: Empty Queue\n");
    call(Q);
  }
  else if(check == 3){
    print(Q);
    call(Q);
  }
  else if(check == 4){
    exit(0);
  }
  else {
    printf("Error: enter correct value\n");
    call(Q);
  }
}

main(){
  int Q[MAX];
  call(Q);
}

