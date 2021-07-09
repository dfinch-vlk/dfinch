#include "philo.h"

int	main(int argc, char **argv)
{
	t_pars			pars;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	int				ret;

	ret = 0;
	if (argc < 5 || argc > 6 || !check_args(argc, argv, &pars))
	{
		printf("Error: arguments!\n");
		return (1);
	}
	if (!pars.nb_meals)
	{
		printf("Last argument must be greater than zero!\n");
		return (0);
	}
	forks = init_forks(&pars);
	pthread_mutex_init(&print, NULL);
	if (!forks || !launch_threads(&pars, forks, &print))
		ret = 1;
	destroy_forks(forks, &pars);
	pthread_mutex_destroy(&print);
	return (ret);
}
