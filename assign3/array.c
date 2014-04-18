#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 500000
#define MAX_NUM 5000000
void GenerateDataAndInsert(int *array, int size){
  // generate random data and insert into array
  int i = 0;
  rand();  
  for(i = 0; i < size; i++){
    int num = rand() % MAX_NUM;
    array[i] = num;
  }
}

int SearchArray(int *array, int size, int elem){
  int i = 0;
  for(i = 0; i < size; i++){
    if(array[i] == elem){
      return i;
    }
  }
  return -1;
}

main(int argc, char *argv[]){
  int array[MAX]; int i = 0;
  if(argc < 2){
    fprintf(stderr, "Usage: <binary> <size of array>\n");
    exit(0);
  }
  int size = atoi(argv[1]);
  GenerateDataAndInsert(array, size);
  //for(i = 0; i < size; i++)
    //printf("%d ", array[i]);
  
  int elem = -99;
  clock_t begin, end;
  double time_spent;
  begin = clock();
  int flag = 0;
  for(i = 0; i < 10000; i++)
    flag = SearchArray(array, size, elem);
  end = clock();
  time_spent = (end - begin) / CLOCKS_PER_SEC ;
  if(flag == -1){
    printf("search unsuccessful, size: %d \t time taken: %lf\n", size, time_spent);
  }
}

