#include "ft.h"

char	*find_word(char *nbr, t_list *dict)
{
	int	i;

	i = 0;
	while (dict[i].number_name)
	{
		if (ft_strcmp_numbers(dict[i].nbr_str, nbr) == 0)
			return (dict[i].number_name);
		i++;
	}
	return (NULL);
}

char	*get_biggest_magnitude(char *nbr, t_list *dict)
{
	int		i;
	char	*best;

	i = 0;
	best = NULL;
	while (dict[i].number_name)
	{
		if (ft_strcmp_numbers(dict[i].nbr_str, nbr) <= 0)
		{
			if (!best || ft_strcmp_numbers(dict[i].nbr_str, best) > 0)
				best = dict[i].nbr_str;
		}
		i++;
	}
	return (best);
}

void	print_word_if_found(char *nbr, t_list *dict, int *first)
{
	char	*word;

	word = find_word(nbr, dict);
	if (word)
	{
		if (*first == 0)
			write(1, " ", 1);
		ft_putstr(word);
		*first = 0;
	}
}

void	process_recursive_part(char *nbr, t_list *dict, int *first)
{
	char	*mag;
	char	*quot;
	char	*rest;

	mag = get_biggest_magnitude(nbr, dict);
	divide_str_number(nbr, mag, &quot, &rest);
	if (ft_strcmp_numbers(mag, "100") >= 0)
		ft_put_number_name(quot, dict, first);
	print_word_if_found(mag, dict, first);
	if (ft_strcmp_numbers(rest, "0") != 0)
	{
		write(1, " ", 1);
		ft_put_number_name(rest, dict, first);
	}
	free(quot);
	free(rest);
}

void	ft_put_number_name(char *nbr, t_list *dict, int *first)
{
	if (ft_strcmp_numbers(nbr, "0") == 0)
	{
		print_word_if_found("0", dict, first);
		return ;
	}
	process_recursive_part(nbr, dict, first);
}
