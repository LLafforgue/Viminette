#include<stdio.h>

int ft_str_is_printable(char *str)
{
    if(*str == 0)
        return (1);
    else
    {
        if (*str >= 32 && *str <= 126)
        {
            if (*(str + 1))
                return ft_str_is_printable(str + 1);
            else
                return (1);
        }
        else
            return (0);   
    }
}

int main(void)
{
    printf("La string contient est %d\n", ft_str_is_printable("125bla"));
    printf("La string contient est %d\n", ft_str_is_printable("BOU"));
    printf("La string contient est %d\n", ft_str_is_printable("BouBa"));
    return (0);
}