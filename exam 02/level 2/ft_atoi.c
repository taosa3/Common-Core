#include <stdio.h>

int	ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;

    result = 0;
    sign = 1;
    i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] >= 48 && str[i] <= 57)
    {
        result *= 10;
        result += str[i] - '0';
        i++;
    }
    return (result * sign);
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        if(argv[2][0] == '+')
            printf("%d", ft_atoi(argv[1]) + ft_atoi(argv[3]));
        else if(argv[2][0] == '-')
            printf("%d", ft_atoi(argv[1]) - ft_atoi(argv[3]));
        else if(argv[2][0] == '*')                           //You can use switch(argv[2]) cases too!!!!
            printf("%d", ft_atoi(argv[1]) * ft_atoi(argv[3]));
        else if(argv[2][0] == '/')
            printf("%d", ft_atoi(argv[1]) / ft_atoi(argv[3]));
        else if(argv[2][0] == '%')
            printf("%d", ft_atoi(argv[1]) % ft_atoi(argv[3]));
    }
    printf("\n");
}
