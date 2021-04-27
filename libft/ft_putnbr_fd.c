/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:58:11 by akezanna          #+#    #+#             */
/*   Updated: 2019/10/31 16:05:22 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int num;

	if (n == 0)
		ft_putchar_fd(0 + '0', fd);
	if (n != 0 && n / 10 != 0)
	{
		ft_putnbr_fd(n / 10, fd);
		if (n > 0)
			ft_putchar_fd(n % 10 + '0', fd);
		else
		{
			num = n * -1;
			ft_putchar_fd(num % 10 + '0', fd);
		}
	}
	else if (n != 0 && (n / 10 == 0) && (n % 10 != 0) && (n > 0))
		ft_putchar_fd(n % 10 + '0', fd);
	else if (n != 0 && (n / 10 == 0) && (n % 10 != 0) && (n < 0))
	{
		num = n * -1;
		ft_putchar_fd('-', fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}
