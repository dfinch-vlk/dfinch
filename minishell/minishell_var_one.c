#include "minishell.h"

char	*find_var_result(char *find)
{
	int		count;
	char	*str;

	count = find_var(find);
	if (!ft_strcmp("?", find))
		return (ft_itoa(g_var.ret));
	if (count == -1)
		return ("");
	str = ft_strchr(g_var.vars[count], '=');
	return (&str[1]);
}

char	*get_var(char *find)
{
	int		i;
	char	*str;

	if (!ft_strcmp("?", find))
		return (ft_itoa(g_var.ret));
	i = find_var(find);
	if (i == -1)
		return ("");
	str = ft_strchr(g_var.vars[i], '=');
	return (&str[1]);
}

int	find_var(char *find)
{
	int		len;
	int		count;
	char	*str;

	str = find;
	if (find[0] == '$')
		str = &find[1];
	len = ft_strlen(str) + 1;
	count = 0;
	str = ft_strjoin(str, "=");
	while (count < g_var.len_vars)
	{
		if (g_var.vars[count] && (!ft_strncmp(str, g_var.vars[count], len)))
		{
			free(str);
			return (count);
		}
		count++;
	}
	free(str);
	return (-1);
}

int	delite_var(char *find)
{
	char	*str;
	char	**change;
	int		count2;
	int		count1;

	str = find;
	if (find[0] == '$')
		str = &find[1];
	count1 = (count2 = 0);
	if (find_var(str) == -1)
		return (0);
	g_var.len_vars--;
	change = malloc(sizeof(char *) * g_var.len_vars);
	while (count1 < g_var.len_vars + 1)
	{
		if (count1 == find_var(str))
			count1++;
		if (count1 >= g_var.len_vars + 1)
			break ;
		change[count2++] = g_var.vars[count1++];
	}
	free(g_var.vars[find_var(str)]);
	free(g_var.vars);
	g_var.vars = change;
	return (0);
}

int	add_var(char *find)
{
	char	**change;
	char	*str;
	int		count;

	count = 0;
	if (!count_char(find, '='))
		return (0);
	check_dup_var(find);
	str = ft_strdup(find);
	change = malloc(sizeof(char *) * (g_var.len_vars += 1));
	while (count < g_var.len_vars - 1)
	{
		change[count] = g_var.vars[count];
		count++;
	}
	change[count] = str;
	free(g_var.vars);
	g_var.vars = change;
	return (0);
}
