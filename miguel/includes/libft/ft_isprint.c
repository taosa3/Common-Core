/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:44:24 by anmiguel          #+#    #+#             */
/*   Updated: 2024/10/31 17:30:13 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*

#include <stdio.h>
#include <ctype.h>

// Declaração da função ft_isprint
int ft_isprint(int c);

int main() {
    // Array de caracteres para testar
    char test_chars[] = {'A', ' ', '1', '!', '\n', '\t', 127, 128, 'z', 'M'};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Teste de ft_isprint e comparação com isprint:\n");
    printf("Caractere\tft_isprint\tisprint\n");
    printf("--------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        int c = (unsigned char)test_chars[i]; // Converte para unsigned char
        printf("%c\t\t", test_chars[i]);
        printf("%d\t\t", ft_isprint(c));   // Resultado da sua função
        printf("%d\n", isprint(c));         // Resultado da função padrão
    }

    return 0;
}


*/