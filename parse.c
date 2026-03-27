#include "push.h"

long	ft_atoi(const char *nptr, int *error)
{
	int	i;
	int	signe;
  long nb;

	signe = 1;
	i = 0;
	nb = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i] - '0';
		i++;
	}
  if (signe == 1 && nb > 2147483647)
    *error = 1;
  if (signe == -1 && nb > (long)2147483648)
    *error = 1;
	return (nb * signe);
}

int hdup(char **nums){
  int j = 0;
  int k;
  int error;
  while(nums[j]) {
    k = j + 1;
    while (nums[k]) {
			if (ft_atoi(nums[j], &error) == ft_atoi(nums[k], &error))
        return 1;
      k++;
    }
    j++;
  }
  return 0;
}

int verif(char **nums){
  int i = 0;
  int x = 0;

  while(nums[x]) {
    while (nums[x][i]) {
      if (i == 0 && (nums[x][i] == '+' || nums[x][i] == '-') )
        i++;
      else if (nums[x][i] < '0' || nums[x][i] > '9')
            return 1;
      else
        i++;
    }
    i = 0;
    x++;
  }
  return 0;
}

t_node *new_node(int value) {
  t_node *node = malloc(sizeof(t_node));
  if(!node){
    write(2, "erreur noeud\n", 13);
    return(NULL);
  }
  node->value = value;
  node->rank = -1;
  node->next = NULL;
    return (node);
}

void add_back(t_stack *stack, t_node *node) {
  t_node *tmp;

  if (stack->first == NULL) {
    stack->first = node;
    stack->size++;
    return;
  }
  tmp = stack->first;
  while(tmp->next != NULL){
    tmp = tmp->next;
  }
  tmp->next = node;
  stack->size++;
}

void pars(char **nums,  t_stack *stack) {
  int j;
  t_node *node;
  int error = 0;

  if (verif(nums)) {
    write(2, "Error\n", 6);
  exit(1);
  }
  if (hdup(nums)){
    write(2, "Error\n", 6);
  exit(1);
  }
  j=0;
  while(nums[j]) {
    node = new_node(ft_atoi(nums[j], &error));
    if(!node){
			write(1, "Error\n", 6);
    }
    if (error == 1){
      write(2, "Error\n", 6);
      exit(1);
    }
    add_back(stack, node);
    j++;
  }
}
