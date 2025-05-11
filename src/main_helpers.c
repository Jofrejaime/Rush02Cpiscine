#include "ft.h"

t_list	*handle_two_args(char *arg, char **nbr_str)
{
	if (!is_valid_number(arg))
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	*nbr_str = ft_strdup(arg);
	return (create_list("numbers.dict"));
}

t_list	*handle_three_args(char *dict_name, char *number, char **nbr_str)
{
	if (!is_valid_number(number))
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	*nbr_str = ft_strdup(number);
	return (create_list(dict_name));
}
