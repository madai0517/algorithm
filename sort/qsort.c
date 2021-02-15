#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 20

int compare(const void *arg1, const void *arg2) {
  return (*((int *)arg1) - *((int *)arg2));
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

  qsort(sort, N, sizeof(sort[0]), compare);

  printf("\nafter:\n");

  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }

  return EXIT_SUCCESS;
}
