#include "ft.h"

static int	read_dict_file(char *filename, char *buf)
{
	int	fd;
	int	r;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	r = read(fd, buf, BUFFER_SIZE);
	close(fd);
	if (r <= 0)
		return (-1);
	buf[r] = '\0';
	return (r);
}

static t_list	*allocate_list(char *buf, char ***lines, int *count)
{
	*count = count_lines(buf);
	*lines = ft_split(buf, '\n');
	if (!*lines)
		return (NULL);
	return (malloc(sizeof(t_list) * (*count + 1)));
}

t_list	*create_list(char *filename)
{
	char	buf[BUFFER_SIZE + 1];
	char	**lines;
	t_list	*list;
	int		count;

	if (read_dict_file(filename, buf) == -1)
		return (NULL);
	list = allocate_list(buf, &lines, &count);
	if (!list)
		return (NULL);
	list = fill_list(lines, count, list);
	ft_free_split(lines);
	return (list);
}

void	free_dict(t_list *list)
{
	int	i;

	i = 0;
	while (list[i].number_name)
	{
		free(list[i].nbr_str);
		free(list[i].number_name);
		i++;
	}
	free(list);
}
