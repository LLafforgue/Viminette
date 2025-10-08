#include<stdio.h>

int ft_str_is_lowercase(char *str)
{
    if(*str == 0)
        return (1);
    else
    {
        if (*str >= 'a' && *str <= 'z')
        {
            if (*(str + 1))
                return ft_str_is_lowercase(str + 1);
            else
                return (1);
        }
        else
            return (0);   
    }
}

int main(void)
{
    printf("La string contient est %d\n", ft_str_is_lowercase("125bla"));
    printf("La string contient est %d\n", ft_str_is_lowercase("BOU"));
    printf("La string contient est %d\n", ft_str_is_lowercase("BouBa"));
    return (0);
}