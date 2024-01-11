/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:39:41 by asanni            #+#    #+#             */
/*   Updated: 2024/01/11 19:37:05 by asanni           ###   ########.fr       */
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

int	verif_msg(int argc, char **argv)
{
	int	ctrl;

	ctrl = 0;
	if (argc != 3)
	{
		ft_printf("Error:\nThe input should be as "\
		"follow: ./client <PID number> Message");
	}
	else if (is_num(argv[1]) == 0)
		ft_printf("PID should be a number");
	else if (*argv[2] == 0)
		ft_printf("Message cannot be void");
	else
			ctrl = 1;
	return (ctrl);
}
//função para enviar a mensagem

// int	send_msg(int pid, char msg)
// {
// 	int	i;
// }
//criar o main para enviar a msg

int	main(int argc, char **argv)
{
	int	msg_check;
	int	pid_num;

	msg_check = verif_msg(argc, argv);
	if (msg_check == 1)
	{
		pid_num = ft_atoi(argv[1]);
		send_msg(pid_num, argv[2]);
	}
}
