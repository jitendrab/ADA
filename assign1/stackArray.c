#include<stdio.h>
#include<stdlib.h>
// implementation of stack using array
// functions - push(), pop(), isEmpty(), isFull(), print()
#define MAX 10000
int head = 0;

int isEmpty(int *S){
  if(head == 0)
    return 1;
  return 0;
}

int isFull(int *S){
  if(head == MAX){
    return 1;
  }
  return 0;
}

//push into stack
void push(int *S, int elem){
  if(isFull(S)){
    fprintf(stderr, "Error: Stack is Full\n");
    return;
  }
  S[head] = elem;
  head++;
}
//pop from the stack 
int pop(int *S){  
  int temp = S[head-1];
  S[head-1] = 0;
  head--;
  return temp;
}

void print(int *S){
  if(!isEmpty(S)){
    int i = 0;
    for(i = 0; i < head; i++)
      printf("%d ", S[i]);
    printf("\n");
  }
  else
    printf("Error: Stack is Empty\n");
}

void call(int *S){  
  printf("Enter\n 1 : to push\t 2 : to pop\t 3 : to print stack\t 4 : to exit\n");
  int check = 0;
  scanf("%d", &check);
  if(check == 1){
    int elem = 0;
    printf("enter element:");
    scanf("%d", &elem);
    push(S, elem);
    call(S);
  }
  else if(check == 2){
    if(!isEmpty(S)){
      int elem = pop(S);
      printf("elem popped: %d\n", elem);
    }
    else
      printf("Error: Stack is Empty\n");
    call(S);
  }
  else if(check == 3){
    print(S);
    call(S);
  }
  else{
    exit(0);
  }
}

main(){
  int S[MAX];
  call(S);
}
  
