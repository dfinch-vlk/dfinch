#include "minishell.h"

int command_echo_hard(int i)
{
	int fd;
	int count;
	int status;
	int flag;
	int count1;

	count = (flag = (count1 = 0));
	status = -1;
	while (count < var.shell[i].len_arg)
	{
		if (!strcmp("-n", var.shell[i].arg[count]))
			flag = 1;
		if (!strcmp(">", var.shell[i].arg[count]))
		{
			status = 1;
			break ;
		}
		if (!strcmp(">>", var.shell[i].arg[count]))
		{
			status = 2;
			break ;
		}
		count++;
	}
	open(var.shell[i].arg[++count], O_CREAT);
	printf("status == %d | str = %s\n", status, var.shell[i].arg[count]);
	if (status == 1)
		fd = open(var.shell[i].arg[count], O_RDWR, O_TRUNC);
	else
		fd = open(var.shell[i].arg[count], O_RDWR);
	while (count1 < count - 1)
	{
		if (strcmp("-n", var.shell[i].arg[count1]))
		{
			write(fd, var.shell[i].arg[count1], ft_strlen(var.shell[i].arg[count1]));
			write(fd, " ", 1);
		}
		count1++;
	}
	count++;
	if (flag == 0)
		write(fd, "\n", 1);
	return (0);
}

int command_echo(int i)
{
	int count;
	int flag;

	count = (flag = 1);
	while (count < var.shell[i].len_arg)
	{
		if (!strcmp("<", var.shell[i].arg[count]) \
			|| !strcmp(">", var.shell[i].arg[count]) \
			|| !strcmp("<<",var.shell[i].arg[count]) \
			|| !strcmp(">>", var.shell[i].arg[count]))
			return (command_echo_hard(i));
		if (!strcmp("-n", var.shell[i].arg[count]))
			flag = 2;
		count++;
	}
	count = 1;
	while (count < var.shell[i].len_arg)
	{
		if (strcmp("-n", var.shell[i].arg[count]))
		{
			// write(0, " ", 1);
			write(0, var.shell[i].arg[count], ft_strlen(var.shell[i].arg[count]));
		}
		count++;
	}
	if (flag == 1)
		printf("\n");
	var.ret = 0;
	return (0);
}

void read_file(char *file)
{
	int fd;
	char buf[0];

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		var.ret = 1;
		printf("cat: %s: No such file or directory\n", file);
		return ;
	}
	else
		var.ret = 0;
	while (read(fd, buf, 1))
		write(0, buf, 1);
}

int command_cat(int count)
{
	int count1;
	
	count1 = 1;
	while (count1 < var.shell[count].len_arg)
	{
		read_file(var.shell[count].arg[count1]);
		count1++;
	}
	return (0);
}