#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 20

void BubbleSort(int* sort) {
  int i, j, flag, k;

  k = 0;
  do {
    flag = 0;
    for (i = 0; i < N - 1 - k; i++) {
      if (sort[i] > sort[i+1]) {
        flag = 1;
        j = sort[i];
        sort[i] = sort[i + 1];
        sort[i + 1] = j;
      }
    }
    k++;
  } while (flag == 1);
}

int main(void) {
  int sort[N];
  int i;

  srand((unsigned int)time(NULL));

  printf("before:\n");
  for (i = 0; i < N; i++) {
    sort[i] = rand() % 100;
    printf("%d ", sort[i]);
  }

  BubbleSort(sort);

  printf("\nafter:\n");

  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }

  return EXIT_SUCCESS;
}
