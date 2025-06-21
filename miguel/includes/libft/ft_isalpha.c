/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:36:17 by anmiguel          #+#    #+#             */
/*   Updated: 2024/10/31 17:27:34 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*

#include <stdio.h>
#include <ctype.h>

// Declaração da função ft_isalpha
int ft_isalpha(int c);

int main() {
    // Array de caracteres para testar
    char test_chars[] = {'A', 'z', '1', '@', 'M', 'b', ' ', '0'};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Teste de ft_isalpha e comparação com isalpha:\n");
    printf("Caractere\tft_isalpha\tisalpha\n");
    printf("------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        char c = test_chars[i];
        printf("%c\t\t", c);
        printf("%d\t\t", ft_isalpha(c));   // Resultado da sua função
        printf("%d\n", isalpha(c));         // Resultado da função padrão
    }

    return 0;
}

*/