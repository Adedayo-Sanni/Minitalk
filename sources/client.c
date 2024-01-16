/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:39:41 by asanni            #+#    #+#             */
/*   Updated: 2024/01/16 20:29:35 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

// a variavel global apos cada char (8 bits) para ela poder 
// enviar de nova ela está funcionado como um "index"
// pq uma var global ao inves de um index normal????
//	pq ela vai ser resetada apos 8 rotações(dps de imprimir um char) 
//	das funçoes enquanto que um index a cada 1 passagem, não completando o byte

int	g_send_bit = 0;

void	send_signal(int signal)
{
	if (signal == SIGUSR1)
		g_send_bit = 1;
}

//Função que da free na msg_copy printa msg de erro e da exit
void	error(char *msg)
{
	free(msg);
	ft_printf("Error:\nFail to communicate");
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
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		g_send_bit = 0;
		bit = (msg >> i & 1);
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
	--i;
		while (g_send_bit != 0)
			;
	}
	ft_printf('\n');
}

//criar o main para enviar a msg
int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					msg_check;
	int					pid_num;
	int					i;

	i = 0;
	msg_check = verif_msg(argc, argv);
	if (msg_check == 1)
	{
		pid_num = ft_atoi(argv[1]);
		sa.sa_handler = send_signal;
		sa.sa_flags = 0;
		sigaction(SIGUSR1, &sa, NULL);
		while (argv[2][i] != '\0')
		{
			send_msg(pid_num, argv[2][i]);
			i++;
		}
	}
	return (0);
}
