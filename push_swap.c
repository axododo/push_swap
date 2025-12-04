#include "stdio.h"


size_t	ft_strlen(char *str)
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


int *push_swap(char *a) {
  int i = 1;
  int mid;
  mid = ft_strlen(a);
  printf("%i/ne", mid);
  return 0;
}

int main(int argc, char *argv[]) {
  //printf("%i\n", *argv[2]);
  int *a = push_swap(argv[1]);
  return 0;
}
