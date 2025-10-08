#include<stdio.h>

int ft_str_is_numeric(char *str)
{
    if(*str == 0)
        return (1);
    else
    {
        if (*str >= '0' && *str <= '9')
        {
            if (*(str + 1))
                return ft_str_is_numeric(str + 1);
            else
                return (1);
        }
        else
            return (0);   
    }
}

int main(void)
{
    printf("La string contient est %d\n", ft_str_is_numeric("125bla"));
    printf("La string contient est %d\n", ft_str_is_numeric(""));
    printf("La string contient est %d\n", ft_str_is_numeric("15"));
    return (0);
}