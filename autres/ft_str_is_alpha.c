#include<stdio.h>
int ft_str_is_alpha(char *str)
{
    if(!*str)
        return (1);
    else
    {
        if (*str >= ' ' || *str <= '~' + 1)
        {
            if (*(str + 1))
                return ft_str_is_alpha(str + 1);
            else
                return (1);
        }
        else
            return (0);   
    }
}

int main(void)
{
    printf("La string contient est %d\n", ft_str_is_alpha("Blabla"));
    printf("La string contient est %d\n", ft_str_is_alpha(""));
    printf("La string contient est %d\n", ft_str_is_alpha(" "));
    return (0);
}