/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:00:53 by anmiguel          #+#    #+#             */
/*   Updated: 2024/10/31 17:27:38 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| ((c >= 48 && c <= 57)))
		return (1);
	else
		return (0);
}

/*

#include <stdio.h>
#include <ctype.h>

// Declaração da função ft_isalnum
int ft_isalnum(int c);

int main() {
    // Array de caracteres para testar
    char test_chars[] = {'A', 'z', '1', '!', 'M', 'b', '9', ' ', '0', '-'};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Teste de ft_isalnum e comparação com isalnum:\n");
    printf("Caractere\tft_isalnum\tisalnum\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        char c = test_chars[i];
        printf("%c\t\t", c);
        printf("%d\t\t", ft_isalnum(c));   // Resultado da sua função
        printf("%d\n", isalnum(c));         // Resultado da função padrão
    }

    return 0;
}

*/