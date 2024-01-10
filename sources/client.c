/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:39:41 by asanni            #+#    #+#             */
/*   Updated: 2024/01/10 19:34:58 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	is_num(char *c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (c[i])
	{
		if (ft_isdigit(c[i]) == 1)
			check = 1;
		else
			return (0);
		i++;
	}
	return (check);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error:\nThe input should be as "\
		"follow: ./client <PID number> Message");
	}
	else if (is_num(argv[1]) == 0)
		ft_printf("PID should be a number");
	else if (*argv[2] == 0)
		ft_printf("Message cannot be void");
}
