#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 20


void MergeSort(int n, int x[]) {
  int i, j, k, m;
  int buffer[N];

  if (n <= 1) {
    return;
  }
  m = n / 2;

  MergeSort(m, x);
  MergeSort(n - m, x + m);

  for (i = 0; i < m; i++) {
    buffer[i] = x[i];
  }

  j = m;
  i = k = 0;
  while (i < m && j < n) {
    if (buffer[i] <= x[j]) {
      x[k++] = buffer[i++];
    } else {
      x[k++] = x[j++];
    }
  }
  while (i < m) {
    x[k++] = buffer[i++];
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

  MergeSort(N, sort);

  printf("\nafter:\n");
  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }
}
