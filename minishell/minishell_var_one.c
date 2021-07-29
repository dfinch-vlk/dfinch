#include "minishell.h"

char *find_var_result(char *find)
{
	int count;

	count = find_var(find);
	if (!strcmp("?", find))
		return (ft_itoa(var.ret));
	if (count == -1)
		return ("");
	char *str = ft_strchr(var.vars[count], '=');
	return (&str[1]);
}

char *get_var(char *find)
{
	int i;
	char *str;

	if (!strcmp("?", find))
		return (ft_itoa(var.ret));
	i = find_var(find);
	if (i == -1)
		return ("");
	str = ft_strchr(var.vars[i], '=');
	return (&str[1]);
}

int find_var(char *find)
{
	int len;
	int count;
	char *str;

	str = find;
	if (find[0] == '$')
		str = &find[1];
	len = ft_strlen(str) + 1;
	count = 0;
	str = ft_strjoin(str, "=");
	while (count < var.len_vars)
	{
		if (!strncmp(str, var.vars[count], len))
		{
			free(str);
			return (count);
		}
		count++;
	}
	free(str);
	return (-1);
}

int delite_var(char *find)
{
	char *str;
	char **change;
	int count2;
	int point;
	int count1;

	str = find;
	if (find[0] == '$')
		str = &find[1];
	count1 = (count2 = 0);
	point = find_var(str);
	if (point == -1)
		return (0);
	var.len_vars--;
	change = malloc(sizeof(char *) * var.len_vars);
	while (count1 < var.len_vars + 1)
	{
		if (count1 == point)
			count1++;
		if (count1 >= var.len_vars + 1)
			break ;
		change[count2++] = var.vars[count1++];
	}
	free(var.vars[point]);
	free(var.vars);
	var.vars = change;
	return (0);
}

int add_var(char *find)
{
	char **change;
	char *str;
	int count;

	count = 0;
	if (!count_char(find, '='))
		return (0);
	check_dup_var(find);
	str = strdup(find);
	change = malloc(sizeof(char *) * (var.len_vars += 1));
	while (count < var.len_vars - 1)
	{
		change[count] = var.vars[count];
		count++;
	}
	change[count] = str;
	free(var.vars);
	var.vars = change;
	return (0);
}