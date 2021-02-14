#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 20

void QuickSort(int bottom, int top, int *data) {
  int lower, upper, div, temp;
  if (bottom >= top) {
    return;
  }

  div = data[bottom];
  for (lower = bottom, upper = top; lower < upper;) {
    while (lower <= upper && data[lower] <= div) {
      lower++;
    }
    while (lower <= upper && data[upper] > div) {
      upper--;
    }

    if (lower < upper) {
      temp = data[lower];
      data[lower] = data[upper];
      data[upper] = temp;
    }
  }

  temp = data[bottom];
  data[bottom] = data[upper];
  data[upper] = temp;

  QuickSort(bottom, upper - 1, data);
  QuickSort(upper + 1, top, data);
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

  QuickSort(0, N - 1, sort);

  printf("\nafter:\n");

  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }

  return EXIT_SUCCESS;
}
