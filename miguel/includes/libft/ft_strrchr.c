/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:00 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 15:01:46 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_ch;

	last_ch = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_ch = (char *)s;
		s++;
	}
	if (*s == (char)c)
		last_ch = (char *)s;
	return (last_ch);
}

/*

#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *str = "Hello, world! This is a test string.";
    int ch = 'o';

    // Test ft_strrchr
    char *result1 = ft_strrchr(str, ch);
    printf("ft_strrchr: Last occurrence of '%c' in \"%s\": %s\n",
	 ch, str, result1);

    // Test standard strrchr for comparison
    char *result2 = strrchr(str, ch);
    printf("strrchr: Last occurrence of '%c' in \"%s\": %s\n", ch, str, result2);

    return 0;
}

*/