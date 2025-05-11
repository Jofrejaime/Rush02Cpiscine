#include "ft.h"

int	ft_strcmp_numbers(char *a, char *b)
{
	int	i;
	int	len_a;
	int	len_b;

	while (*a == '0')
		a++;
	while (*b == '0')
		b++;
	len_a = 0;
	len_b = 0;
	while (a[len_a])
		len_a++;
	while (b[len_b])
		len_b++;
	if (len_a != len_b)
		return (len_a - len_b);
	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
