#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 20

void BinarySort(int *sort) {
  int i, sorted, temp, insert;
  int left, mid, right;

  for (sorted = 0; sorted < N; sorted++) {
    insert = sort[sorted];

    left = 0;
    right = sorted;
    while (left < right) {
      mid = (left + right) / 2;
      if (sort[mid] < insert) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    i = left;

    while (i < sorted) {
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

  BinarySort(sort);

  printf("\nafter:\n");
  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }
}