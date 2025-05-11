#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4096

// Estruturas

typedef struct s_list
{
	char	*nbr_str;
	char	*number_name;
}	t_list;

typedef struct s_add
{
	int		i;
	int		j;
	int		k;
	int		carry;
	char	*res;
}	t_add;

typedef struct s_sub
{
	int		i;
	int		j;
	int		k;
	int		borrow;
	char	*res;
}	t_sub;

// Conversão
char	*get_biggest_magnitude(char *nbr, t_list *dict);
char	*find_word(char *nbr, t_list *dict);
void	ft_put_number_name(char *nbr, t_list *dict, int *first);
void	print_word_if_found(char *nbr, t_list *dict, int *first);
void	process_recursive_part(char *nbr, t_list *dict, int *first);
void	divide_str_number(char *nbr, char *div, char **quot, char **rest);
char	*str_add(char *a, char *b);
char	*str_subtract(char *a, char *b);
int		ft_strcmp_numbers(char *a, char *b);

// Aritmética auxiliar
void	handle_add_digit(t_add *v, char *a, char *b);
void	loop_add_digits(t_add *v, char *a, char *b);
char	*clean_add_result(char *res);

// Dicionário
t_list	*create_list(char *filename);
void	free_dict(t_list *list);
t_list	*fill_list(char **lines, int count, t_list *list);
int		count_lines(char *buf);
char	*extract_key(char *line);
char	*extract_value(char *line);

// Utils
char	*ft_strdup(char *src);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	**ft_split(char *str, char sep);
void	ft_free_split(char **arr);
int	ft_strlen(char *str);
// String para número
int		is_valid_number(char *str);

// Argumentos (main)
t_list	*handle_two_args(char *arg, char **nbr_str);
t_list	*handle_three_args(char *dict_name, char *number, char **nbr_str);

#endif
