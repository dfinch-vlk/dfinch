#include "minishell.h"

int parsing_main_if1(int i, int q, int *count)
{
	int len;

	len = 0;
	while (var.str[*count + len] != ' ' && var.str[*count + len] && var.str[*count + len] != ';')
		len++;
	var.shell[i].arg[q] = malloc(sizeof(char) * len + 2);
	len = 1;
	var.shell[i].arg[q][0] = '1';
	while (var.str[*count] != ' ' && var.str[*count] && var.str[*count] != ';')
		var.shell[i].arg[q][len++] = var.str[count[0]++];
	var.shell[i].arg[q][len] = 0;
	if (var.str[*count] == 0 || var.str[*count] == ';')
		return (1);
	return (0);
}

int parsing_main_if2(int i, int q, int *count)
{
	char c;
	int len;

	len = 0;
	c = var.str[*count];
	count[0]++;
	while (var.str[*count + len] != c && var.str[*count + len])
		len++;
	var.shell[i].arg[q] = malloc(sizeof(char) * len + 2);
	len = 1;
	if (c == 34)
		var.shell[i].arg[q][0] = '1';
	else
		var.shell[i].arg[q][0] = '0';
	while (var.str[*count] != c && var.str[*count])
		var.shell[i].arg[q][len++] = var.str[count[0]++];
	var.shell[i].arg[q][len] = 0;
	if (var.str[*count] == 0)
		return (1);
	else
		count[0]++;
	return (0);
}

void parsing_main(int i)
{
	int count;
	char *clear;
	int q;

	count = (q = 0);
	var.shell[i].arg = malloc(sizeof(char *) * (var.shell[i].len_arg = count_arg()));
	while (var.str[count] != ';' && var.str[count])
	{	
		if (var.str[count] != ' ' && var.str[count] != 34 && var.str[count] != 39)
			if (parsing_main_if1(i, q++, &count))
				break ;
		if (var.str[count] == 34 || var.str[count] == 39)
			if (parsing_main_if2(i, q++, &count))
				break ;
		count++;
	}
	clear = var.str;
	var.str = strdup(&clear[++count]);
	parsing_final(i);
	free(clear);
}