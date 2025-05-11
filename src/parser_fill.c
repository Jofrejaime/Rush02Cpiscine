#include "ft.h"

t_list	*fill_list(char **lines, int count, t_list *list)
{
	int		i;
	char	*key;
	char	*val;

	i = 0;
	while (i < count)
	{
		key = extract_key(lines[i]);
		val = extract_value(lines[i]);
		if (key && val)
		{
			list[i].nbr_str = ft_strdup(key);
			list[i].number_name = ft_strdup(val);
		}
		else
			list[i].number_name = NULL;
		free(key);
		free(val);
		i++;
	}
	list[i].number_name = NULL;
	return (list);
}
