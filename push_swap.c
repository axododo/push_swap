#include "stdio.h"


size_t	ft_strlen(int *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
    str[i] -= '0';
		i++;
	}
	return (i);
}


int *push_swap(int *a) {
  int i = 1;
  int mid;
  mid = ft_strlen(a);
  printf("%i/ne", mid);
  return a;
}

int main(int argc, char *argv[]) {
//  printf("%i\n", *argv[2]);
  int *a = push_swap((int *)argv[1]);
  return 0;
}
