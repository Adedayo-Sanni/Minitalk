/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:39:46 by asanni            #+#    #+#             */
/*   Updated: 2024/01/10 18:10:38 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

//int	kill(char place, char holder);

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 1)
	{
		ft_printf("Please start only the server");
	}
	pid = getpid();
	ft_printf("%i", pid);
}
