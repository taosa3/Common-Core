#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int main() {
    int n = 20;
	unsigned int nb = 255;
	char *str = "Ola tudo?";
	char c = 'A';
	void *ptr;
	ptr = 0;
	int len = 0;
    
	printf("\033[1;33m===== %%c =====\033[0m\n");
	len = ft_printf("Checking characters: %c\n", c);
	ft_printf("Length of the string: %d\n", len);

	len = 0;

	printf("\033[1;33m===== %%s =====\033[0m\n");
	len = ft_printf("Checking strings: %s\n", str);
	ft_printf("Length of the string: %d\n", len);

	len = 0;

	printf("\033[1;33m===== %%p =====\033[0m\n");
	len = ft_printf("Checking pointers: %p\n", ptr);
	ft_printf("Length of the string: %d\n", len);
    len = 0;
    len = printf(" %p %p \n", ptr, ptr);
    printf("Length of the string: %d\n", len);
    
	len = 0;

	printf("\033[1;33m===== %%d and %%i =====\033[0m\n");
	len = ft_printf("Checking %%d and %%i: %d %i\n", n, n);
	ft_printf("Length of the string: %d\n", len);

	len = 0;

	printf("\033[1;33m===== %%u =====\033[0m\n");
	len = ft_printf("Checking %%u: %u\n", nb);
	ft_printf("Length of the string: %d\n", len);

	len = 0;

	printf("\033[1;33m===== %%x and %%X =====\033[0m\n");
	len = ft_printf("Checking %%x and %%X: %x %X\n", nb, nb);
	ft_printf("Length of the string: %d\n", len);

	len = 0;

	printf("\033[1;33m===== %%%% =====\033[0m\n");
	len = ft_printf("Checking %%%%\n");
	ft_printf("Length of the string: %d\n", len);
}