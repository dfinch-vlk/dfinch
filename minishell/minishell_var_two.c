#include "minishell.h"

void	writing_var_dop()
{
	var.vars[12] = ft_strjoin("PATH=", getenv("PATH"));
	var.vars[13] = ft_strjoin("PWD=", getenv("PWD"));
	var.vars[14] = ft_strjoin("LANG=", getenv("LANG"));
	var.vars[15] = ft_strjoin("ITERM_PROFILE=", getenv("ITERM_PROFILE"));
	var.vars[16] = ft_strjoin("XPC_FLAGS=", getenv("XPC_FLAGS"));
	var.vars[17] = ft_strjoin("XPC_SERVICE_NAME=", getenv("XPC_SERVICE_NAME"));
	var.vars[18] = ft_strjoin("SHLVL=", getenv("SHLVL"));
	var.vars[19] = ft_strjoin("HOME=", getenv("HOME"));
	var.vars[20] = ft_strjoin("COLORFGBG=", getenv("COLORFGBG"));
	var.vars[21] = ft_strjoin("LC_TERMINAL_VERSION=", getenv("LC_TERMINAL_VERSION"));
	var.vars[22] = ft_strjoin("ITERM_SESSION_ID", getenv("ITERM_SESSION_ID"));
	var.vars[23] = ft_strjoin("LESS=", getenv("LESS"));
	var.vars[24] = ft_strjoin("LOGNAME=", getenv("LOGNAME"));
	var.vars[25] = ft_strjoin("LC_TERMINAL=", getenv("LC_TERMINAL"));
	var.vars[26] = ft_strjoin("COLORTERM=", getenv("COLORTERM"));
	var.vars[27] = ft_strjoin("_=", getenv("_"));
}

void	writing_var()
{
	var.len_vars = 28;
	var.ret = 0;
	var.vars = malloc(sizeof(char *) * 28);
	var.vars[0] = ft_strjoin("TERM_PROGRAM=", getenv("TERM_PROGRAM"));
	var.vars[1] = ft_strjoin("TERM=", getenv("TERM"));
	var.vars[2] = ft_strjoin("SHELL=", getenv("SHELL"));
	var.vars[3] = ft_strjoin("TMPDIR=", getenv("TMPDIR"));
	var.vars[4] = ft_strjoin("TERM_PROGRAM_VERSION=", getenv("TERM_PROGRAM_VERSION"));
	var.vars[5] = ft_strjoin("TERM_SESSION_ID=", getenv("TERM_SESSION_ID"));
	var.vars[6] = ft_strjoin("ZSH=", getenv("ZSH"));
	var.vars[7] = ft_strjoin("USER=", getenv("USER"));
	var.vars[8] = ft_strjoin("SSH_AUTH_SOCK=", getenv("SSH_AUTH_SOCK"));
	var.vars[9] = ft_strjoin("__CF_USER_TEXT_ENCODING=", getenv("__CF_USER_TEXT_ENCODING"));
	var.vars[10] = ft_strjoin("PAGER=", getenv("PAGER"));
	var.vars[11] = ft_strjoin("LSCOLORS=", getenv("LSCOLORS"));
	writing_var_dop();
}