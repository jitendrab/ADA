#include<stdio.h>

#define MAX 100000
main(){
  int i = 0;
  rand(time(NULL));
  for(i = 0; i < 1000; i++){
    printf("%d\n", rand()%MAX+1);
  }
}
