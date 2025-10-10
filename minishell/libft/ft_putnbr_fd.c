/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:40:53 by tafonso           #+#    #+#             */
/*   Updated: 2025/04/19 22:36:28 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(n);
	if (str == NULL)
		return ;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
	free(str);
}
