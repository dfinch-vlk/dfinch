#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define TRUE 1

# define FALSE 0

typedef struct s_push_swap
{
	int			number;
	int			position;
	short int	check_b;
}	t_numbers;

void	function_pb(t_numbers *array, int len, int write_no);
void	function_pa(t_numbers *array, int len, int write_no);
void	function_rra(t_numbers *array, int len, int write_no);
void	function_rrb(t_numbers *array, int len, int write_no);
void	function_rb(t_numbers *array, int len, int write_no);
void	function_ra(t_numbers *array, int len, int write_no);
void	function_sa(t_numbers *array, int len, int write_no);
void	algoritm_three(t_numbers *array, int len);
int		position_number_max(t_numbers *array, int len, int flag);
int		position_number_min(t_numbers *array, int len, int flag);
int		count_steck(t_numbers *array, int len, int flag);
void	algoritm_small(t_numbers *array, int len);
int		number_min(t_numbers *array, int len, int flag);
int		number_max(t_numbers *array, int len, int flag);
int		find_number_position(t_numbers *array, int len, int pos, int flag);
void	algoritm_main(t_numbers *array, int len);
int		count_steck(t_numbers *array, int len, int flag);
void	function_sb(t_numbers *array, int len, int write_no);
void	algoritm_main_end(t_numbers *array, int len);
int		count_space(const char *str);
void	check_numbers(int argc, const char *argv[]);
void	error(t_numbers *array);
int		ft_atoi(const char *str, t_numbers *array);
int		check_chanks_numbers(int number, int *chanks, int len_chanks);
int		**distribution_chanks(int min, int len, int count_chanks);
void	algoritm_main_end1(t_numbers *array, int len, int pos);
void	dop1(t_numbers *array, int len);
void	dop2(t_numbers *array, int len, const char **argv);

#endif