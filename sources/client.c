/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:39:41 by asanni            #+#    #+#             */
/*   Updated: 2024/01/13 19:19:34 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

//Função que da free na msg_copy printa msg de erro e da exit
void	error(char *msg)
{
	free(msg);
	ft_printf("Error:\nFail to communicate");
	//encerrar communicação
	exit(EXIT_FAILURE);
	
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
void	send_msg(int pid, char msg)
{
	static char	*msg_copy = 0;
	static int	bit = -1;
	static int	server_pid = 0;

	if (msg)
		msg_copy = ft_strdup(msg);
	if (!msg_copy)
		error (0); 
	if (pid)
		server_pid = pid;
	if (msg_copy[++bit / 8])
	{
		/* code */
	}
	
}

	// i = 7;
	// while (i >= 0)
	// {
	// 	bit = (msg >> i) & 1;
	// 	if (bit == 1)
	// 		ft_printf("1");
	// 	else
	// 		ft_printf("0");
	// --i;
	// }
	// ft_printf("\n");

//criar o main para enviar a msg
int	main(int argc, char **argv)
{
	int	msg_check;

	msg_check = verif_msg(argc, argv);
	if (msg_check == 1)
	{
	/* 	signal(SIGUSR1, handler_sigusr);//TODO funcao para manipular sinais
		signal(SIGUSR2, handler_sigusr); */
		send_msg(ft_atoi(argv[1]), argv[2][0]);
	}
	else
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
