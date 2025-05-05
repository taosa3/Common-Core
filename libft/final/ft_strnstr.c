/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:09:51 by tafonso           #+#    #+#             */
/*   Updated: 2025/04/19 22:04:40 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelen;
	size_t	i;
	size_t	k;

	needlelen = ft_strlen(needle);
	i = 0;
	if (needlelen == 0)
		return ((char *)haystack);
	while (i + needlelen <= len && haystack[i])
	{
		k = 0;
		while (k < needlelen && haystack[i + k] == needle[k])
			k++;
		if (k == needlelen)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
