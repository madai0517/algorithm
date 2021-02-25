#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 20

int sort[N];

void InsertSort(int *sort) {
  int i, sorted, temp, insert;

  for (sorted = 0; sorted < N - 1; sorted++) {
    insert = sort[sorted + 1];

    for (i = 0; i <= sorted; i++) {
      if (sort[i] > insert) {
        break;
      }
    }

    while (i <= sorted + 1) {
      temp = sort[i];
      sort[i] = insert;
      insert = temp;
      i++;
    }
  }
}

int main(void) {
  int i;
  int sort[N];
  
  srand((unsigned int)time(NULL));

  printf("before:\n");
  for (i = 0; i < N; i++) {
    sort[i] = rand() % 100;
    printf("%d ", sort[i]);
  }

  InsertSort(sort);

  printf("\nafter:\n");
  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }
}