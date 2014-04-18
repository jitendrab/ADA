#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 500000
#define MAX_NUM 5000000
void GenerateDataAndInsert(int *array, int size){
  int i = 0;
  for(i = 0; i < size; i++){
    array[i] = i+1;
  }
}

int SearchSortedArray(int *array, int start, int end, int elem){
  if(start > end )
    return -1;
  if(elem == array[start])
    return start;
  else if(elem == array[end])
    return end;
  int mid = (start + end)/2;
  if(elem < array[mid]){
    return SearchSortedArray(array, start+1, mid, elem);
  }
  else if(elem > array[mid]){
    return SearchSortedArray(array, mid+1, end, elem);
  }
  else
    return mid;
}

main(int argc, char *argv[]){
  int array[MAX]; int i = 0;
  if(argc < 2){
    fprintf(stderr, "Usage: <binary> <size of array>\n");
    exit(0);
  }
  int size = atoi(argv[1]);
  GenerateDataAndInsert(array, size);
  int elem = -99;
  clock_t begin, end;
  double time_spent;
  begin = clock();
  int flag = 0;
  for(i = 0; i < 10000; i++)
    flag = SearchSortedArray(array, 0, size, elem);
  end = clock();
  time_spent = (end - begin) / CLOCKS_PER_SEC ;
  if(flag == -1){
    printf("search unsuccessful, size: %d \t time taken: %lf\n", size, time_spent);
  }
}
