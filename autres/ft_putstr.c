#include<unistd.h>

void    ft_putstr(char *str)
{
    write(1, &*str, 1);
    if(*(str + 1))
        return ft_putstr(str + 1);
}

int main(void)
{
    char string[15] = "Il faut un mot";
    ft_putstr(string);
    return (0);
}