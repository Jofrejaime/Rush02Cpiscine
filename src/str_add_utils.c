#include "ft.h"

void	handle_add_digit(t_add *v, char *a, char *b)
{
	int	d_a;
	int	d_b;
	int	sum;

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
	sum = d_a + d_b + v->carry;
	v->res[v->k] = (sum % 10) + '0';
	v->carry = sum / 10;
	v->k--;
}

void	loop_add_digits(t_add *v, char *a, char *b)
{
	while (v->k >= 0)
		handle_add_digit(v, a, b);
}

char	*clean_add_result(char *res)
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
