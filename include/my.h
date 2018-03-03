/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** header
*/

char *get_next_line(int fd);

int	my_printf(char *, ...);

void	my_putchar(char);

int	my_isneg(int);

int	my_put_nbr(int);

void	my_swap(int*, int*);

int	my_putstr(char const*);

int	my_strlen(char const*);

int	my_getnbr(char const*);

void	my_sort_int_array(int*, int);

int	my_compute_power_rect(int, int);

int	my_compute_square_root(int);

int	my_is_prime(int);

int	my_find_prime_sup(int nb);

char	*my_strcpy(char*, char const*);

char	*my_strncpy(char*, char const*, int);

char	*my_revstr(char*);

char	*my_strstr(char*, char const*);

int	my_strcmp(char const*, char const*);

int	my_strncmp(char const*, char const*, int);

char	*my_strupcase(char*);

char	*my_strlowcase(char*);

char	*my_strcapitalize(char*);

int	my_str_isalpha(char const*);

int	my_str_isnum(char const*);

int	my_str_islower(char const*);

int	my_str_isupper(char const*);

int	my_str_isprintable(char const*);

int	my_showstr(char const*);

int	my_showmem(char const*, int);

char	*my_strcat(char*, char const*);

char	*my_strncat(char*, char const*, int);

char	*my_strdup(char const *);

char *my_calloc(int);

int    my_count_char(char *str, char c);

char *my_get_str_from_nbr(int nb);

char **my_str_split(char *str, char c);

void	free_strdarray(char **darray);

int	my_streqstr(char *str1, char *str2);

int	my_count_word_array_args(char **word_array);
