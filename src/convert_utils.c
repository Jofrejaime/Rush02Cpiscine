#include "ft.h"

static void	subtract_loop_until_less(char *nbr, char *divisor,
				char **quot, char **rest)
{
	char	*tmp;
	char	*count;
	char	*old;
	char	*old_count;

	count = ft_strdup("0");
	tmp = ft_strdup(nbr);
	while (ft_strcmp_numbers(tmp, divisor) >= 0)
	{
		old = tmp;
		tmp = str_subtract(tmp, divisor);
		free(old);
		old_count = count;
		count = str_add(count, "1");
		free(old_count);
	}
	*quot = count;
	*rest = tmp;
}

void	divide_str_number(char *nbr, char *divisor, char **quot, char **rest)
{
	subtract_loop_until_less(nbr, divisor, quot, rest);
}
