#include<stdio.h>

int ft_str_is_uppercase(char *str)
{
    if(*str == 0)
        return (1);
    else
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            if (*(str + 1))
                return ft_str_is_uppercase(str + 1);
            else
                return (1);
        }
        else
            return (0);   
    }
}

int main(void)
{
    printf("La string contient est %d\n", ft_str_is_uppercase("125bla"));
    printf("La string contient est %d\n", ft_str_is_uppercase("BOU"));
    printf("La string contient est %d\n", ft_str_is_uppercase("BouBa"));
    return (0);
}