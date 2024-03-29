/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:27:36 by asanni            #+#    #+#             */
/*   Updated: 2023/10/31 20:19:08 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_lower(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 15)
		i += ft_puthex_lower(n / 16);
	i += write(1, &HEX_LOW[n % 16], 1);
	return (i);
}
