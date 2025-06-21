/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:54:17 by anmiguel          #+#    #+#             */
/*   Updated: 2024/10/31 17:27:27 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*

#include <stdio.h>
#include <ctype.h>

// Declaração da função ft_isdigit
int ft_isdigit(int c);

int main() {
    // Array de caracteres para testar
    char test_chars[] = {'0', '5', '9', 'a', 'Z', '!', '3', ' '};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Teste de ft_isdigit e comparação com isdigit:\n");
    printf("Caractere\tft_isdigit\tisdigit\n");
    printf("------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        char c = test_chars[i];
        printf("%c\t\t", c);
        printf("%d\t\t", ft_isdigit(c));   // Resultado da sua função
        printf("%d\n", isdigit(c));         // Resultado da função padrão
    }

    return 0;
}

*/