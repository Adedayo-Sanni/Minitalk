/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:06:24 by asanni            #+#    #+#             */
/*   Updated: 2024/01/20 16:23:57 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

//criar função para receber e imprimir a mensagem do client
//elá vai receber 1 bit por por vez do client ate formar um char
//depois que receber 1 byte(8 bits) ela imprime o char e vai 
//retornar a comunicação pro client para saber qual sera a nova 
//sequencia de bits a receber

//a função para receber/imprimir o bit vai funcionar igual a print num
// o sinal vai literalmente enviar 1 e 0

//estudar communicação com binarios em char

int	g_received_bit = 0;

//not using the context variable so i casted it as void 
//to not trigger the CFlags warnings

static void	print_msg(int signal, siginfo_t *siginfo, void *context)
{
	static unsigned char	letter;

	(void)context;
	if (signal == SIGUSR1)
		letter += 0 << g_received_bit;
	else if (signal == SIGUSR2)
		letter += 1 << g_received_bit;
	g_received_bit ++;
	if (g_received_bit == 8)
	{
		ft_putchar_fd(letter, 1);
		letter = 0;
		g_received_bit = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc != 1)
		ft_printf("Error:\nThe input should be as follow:./server");
	pid = getpid();
	ft_printf("Server PID: %i \n", pid);
	sa.sa_sigaction = print_msg;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

//sa_handler specifies the action to be associated with signum and 
//may be SIG_DFL for the default action, 
//SIG_IGN to ignore this signal, or a pointer to a signal handling function.  
//This function receives the signal number as its only argument.
// diff entre sa handler and sa sigaction é a qntd de info que eu quero
// ou preciso passar, a sigaction passa o num do sinal, as flas e etc..
// a handler passa só o int do sinal.

//SA_SIGINFO - centraliza as infos do sinal
