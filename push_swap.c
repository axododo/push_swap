#include "stdio.h"

int *push_swap(int *a) {
  int i = 1;
  int *tmp;
  int *b;
  int max;
  while(a[i]) {
    if (a[i] < a[i-1]) {
      tmp[i] = a[i];
    }
    if (a[i] > a[i-1]) {
      tmp[i - i] = a[i];
    }
    i++;
  }
}

int main(int argc, char const *argv[]) {
  int *a = push_swap((int *)argv[1]);
  printf("%i\n", a);
  return 0;
}
