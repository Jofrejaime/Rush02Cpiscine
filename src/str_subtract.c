#include "ft.h"

static void	init_sub_vars(t_sub *v, char *a, char *b)
{
	int	len_a;

	len_a = ft_strlen(a);
	v->i = len_a - 1;
	v->j = ft_strlen(b) - 1;
	v->k = len_a - 1;
	v->borrow = 0;
	v->res = malloc(len_a + 1);
	if (v->res)
		v->res[len_a] = '\0';
}

static void	handle_sub_digit(t_sub *v, char *a, char *b)
{
	int	d_a;
	int	d_b;

	d_a = 0;
	if (v->i >= 0)
	{
		d_a = a[v->i] - '0';
		v->i--;
	}
	d_b = 0;
	if (v->j >= 0)
	{
		d_b = b[v->j] - '0';
		v->j--;
	}
	d_a -= v->borrow;
	if (d_a < d_b)
	{
		d_a += 10;
		v->borrow = 1;
	}
	else
		v->borrow = 0;
	v->res[v->k] = (d_a - d_b) + '0';
	v->k--;
}

static void	loop_sub_digits(t_sub *v, char *a, char *b)
{
	while (v->k >= 0)
		handle_sub_digit(v, a, b);
}

static char	*clean_sub_result(char *res)
{
	int		i;
	char	*final;

	if (!res)
		return (NULL);
	i = 0;
	while (res[i] == '0' && res[i + 1])
		i++;
	final = ft_strdup(res + i);
	free(res);
	return (final);
}

char	*str_subtract(char *a, char *b)
{
	t_sub	v;

	init_sub_vars(&v, a, b);
	if (!v.res)
		return (NULL);
	loop_sub_digits(&v, a, b);
	return (clean_sub_result(v.res));
}

