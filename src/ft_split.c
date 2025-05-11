#include "ft.h"

static int	word_count(char *str, char sep)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (count);
}

static char	*word_dup(char *str, char sep)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	char	**arr;

	i = 0;
	arr = malloc(sizeof(char *) * (word_count(str, sep) + 1));
	if (!arr)
		return (NULL);
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
		{
			arr[i] = word_dup(str, sep);
			i++;
			while (*str && *str != sep)
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
