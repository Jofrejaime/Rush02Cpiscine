#include "ft.h"

int	count_lines(char *buf)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	*extract_key(char *line)
{
	int		i;
	int		j;
	char	*key;

	i = 0;
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[j] >= '0' && line[j] <= '9')
		j++;
	key = malloc(j - i + 1);
	if (!key)
		return (NULL);
	j = 0;
	while (line[i] >= '0' && line[i] <= '9')
		key[j++] = line[i++];
	key[j] = '\0';
	return (key);
}

char	*extract_value(char *line)
{
	int		i;
	int		j;
	char	*val;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (line[i] == ':')
		i++;
	while (line[i] == ' ')
		i++;
	val = malloc(ft_strlen(line) + 1);
	if (!val)
		return (NULL);
	j = 0;
	while (line[i] && line[i] != '\n')
		val[j++] = line[i++];
	val[j] = '\0';
	return (val);
}
