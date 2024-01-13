/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:06:24 by asanni            #+#    #+#             */
/*   Updated: 2024/01/13 19:19:46 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

//criar função para imprimir mensagem
void	print_message(int msg)
{
}

int	sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
{
	struct sigaction
	{
		void (*sa_sigaction)(int, siginfo_t *, void *);
		sigset_t sa_mask;
		int sa_flags;
	}

}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 1)
		ft_printf("Error:\nThe input should be as follow:./server");
	else
	{
		pid = getpid();
		ft_printf("Server PID: %i", pid);
		//signal(SIGUSR1, print_message);
	}
	return (0);
}
