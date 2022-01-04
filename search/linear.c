#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_FOUND (-1)
#define N (10)

int linear_search(int x, int *a, int num) {
  int n = 0, t;

  t = a[num-1];
  a[num-1] = x;

  while (a[n] != x) {
    n++;
  }

  a[num-1] = t;
  if ((n < num-1) || x == t) {
    return n;
  }

  return NOT_FOUND;
}

int main (void) {
  int i, r, array[N];

  srand((unsigned int)time(NULL));

  printf("array: ");
  for (i = 0; i < N; i++) {
    array[i] = rand() % 100;
    printf("%d ", array[i]);
  }

  printf("\n探す値を入力してください: ");
  scanf("%d", &i);

  r = linear_search(i, array, N);

  if (r == NOT_FOUND) {
    printf("%dはありません\n", i);
  } else {
    printf("%dは配列の%d番目にあります\n", i, r+1);
  }

  return EXIT_SUCCESS;
}