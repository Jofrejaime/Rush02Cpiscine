#include "ft.h"

static void	init_add_vars(t_add *v, char *a, char *b)
{
	int	len_a;
	int	len_b;
	int	max;

	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	if (len_a > len_b)
		max = len_a;
	else
		max = len_b;
	v->i = len_a - 1;
	v->j = len_b - 1;
	v->k = max;
	v->carry = 0;
	v->res = malloc(max + 2);
	if (v->res)
		v->res[max + 1] = '\0';
}

char	*str_add(char *a, char *b)
{
	t_add	v;

	init_add_vars(&v, a, b);
	if (!v.res)
		return (NULL);
	loop_add_digits(&v, a, b);
	return (clean_add_result(v.res));
}
