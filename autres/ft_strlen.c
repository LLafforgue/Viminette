#include<stdio.h>

int ft_leng(char *str, int lg)
{
    if (*str)
        return ft_leng(str + 1, lg + 1);
    else
        return lg;
}

int ft_strlen(char *str)
{
    return ft_leng(str, 0);
}

int main(int argc, char *argv[])
{
    char string[15] = "Il faut un mot";
    if (argc != 2)
    {
        printf("%s a une longuer de :\n", string);
        printf("%d\n", ft_strlen(string));
        return (1);
    }
    else
    {
        printf("%s a une longuer de :\n", *(argv + 1));
        printf("%d\n", ft_strlen(*(argv + 1)));
        return (0);
    }
}