/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:37:24 by hbouchel          #+#    #+#             */
/*   Updated: 2024/05/16 15:47:33 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_contains(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (i);
		i++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_error(char **args, int ac)
{
	if (ac == 2)
	{
		ft_free(args);
		ft_error("error");
	}
	else
		ft_error("error");
}

void	ft_check_args(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			free_error(args, ac);
		if (ft_contains(tmp, args, i))
			free_error(args, ac);
		if (tmp < -2147483648 || tmp > 2147483647)
			free_error(args, ac);
		i++;
	}
	if (ac == 2)
		ft_free(args);
}
