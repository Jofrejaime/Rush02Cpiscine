#include "ft.h"

int	main(int ac, char **av)
{
	t_list	*dict;
	char	*nbr_str;
	int		first;

	first = 1;
	if (ac == 2)
		dict = handle_two_args(av[1], &nbr_str);
	else if (ac == 3)
		dict = handle_three_args(av[1], av[2], &nbr_str);
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!dict)
	{
		write(1, "Dict Error\n", 12);
		return (1);
	}
	ft_put_number_name(nbr_str, dict, &first);
	write(1, "\n", 1);
	free_dict(dict);
	free(nbr_str);
	return (0);
}
