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
int	free_tab(char **tab)
{
	int	y;

	y = 0;
  while (tab[y])
    free(tab[y++]);
  free(tab);
	return (0);
}

void free_stack(t_stack *stack)
{
    t_node *tmp;
    t_node *curr = stack->first;
    while (curr)
    {
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    stack->first = NULL;
    stack->size = 0;
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	size2;

	size2 = size;
	len = 0;
	i = 0;
	while (src[len])
	{
		len++;
	}
	if (size == 0)
	{
		return (len);
	}
	while (src[i] && i < size2 - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    **split_nums(int ac, char **av)
{
    if (ac == 2)
        return (ft_split(av[1], ' '));
    return (av + 1);
}
