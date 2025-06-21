/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:08:51 by anmiguel          #+#    #+#             */
/*   Updated: 2024/10/31 17:27:30 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*

#include <stdio.h>
#include <ctype.h>

// Declaração da função ft_isascii
int ft_isascii(int c);

int main() {
    // Valores para testar
    int test_values[] = {0, 65, 127, 128, 200, -1, 10, 'A', 'a', '9', '!'};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Teste de ft_isascii e comparação com isascii:\n");
    printf("Valor\tft_isascii\tisascii\n");
    printf("------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        int c = test_values[i];
        printf("%3d\t", c);
        printf("%d\t\t", ft_isascii(c));   // Resultado da sua função
        printf("%d\n", isascii(c));         // Resultado da função padrão
    }

    return 0;
}

*/