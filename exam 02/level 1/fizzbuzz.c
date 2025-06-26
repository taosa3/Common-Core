#include <unistd.h>

void putnbr(int n)
{
    if (n > 9)
        putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

int main()
{
    int n;

    n = 1;
    while (n < 101)
    {
        if (n % 3 == 0 && n % 5 == 0)
            write(1, "fizzbuzz", 9);
        else if (n % 3 == 0)
            write(1, "fizz", 5);
        else if (n % 5 == 0)
            write(1, "buzz", 5);
        else
            putnbr(n);
        n++;
        write(1, "\n", 1);
    }
}