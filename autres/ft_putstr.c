#include<unistd.h>

void    ft_putstr(char *str)
{
    write(1, &*str, 1);
    if(*(str + 1))
        return ft_putstr(str + 1);
}

int main(int argc, char *argv[])
{
    char string[15] = "Il faut un mot";
    if (argc != 2)
    {
        ft_putstr(string);
        return (1);
    }
    else
    {
        ft_putstr(*(argv + 1));
        return (0);
    }
}