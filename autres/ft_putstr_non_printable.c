#include<unistd.h>
#include<stdio.h>

void ft_hex(char str)
{
    int     dec;
    int     i;
    char    hex[2];

    dec = str;
    i = 0;
    write(1, "\\", 1);
    while (i < 2)
    {
        if (dec % 16 > 9)
            hex[i++] = 'a' + (dec % 16) - 10;
        else
            hex[i++] = '0' + dec % 16;
        dec /= 16;
    }
    write(1, &hex[1], 1);
    write(1, &hex[0], 1);
}

int ft_word_is_printable(char str)
{


    if (str >= 32 && str <= 126)
            return (1);
    else
    {
        ft_hex(str); 
        return (0);
    }

}

void    ft_putstr_non_printable(char *str)
{
    int i;

    i = 0;
    while (*(str + i) != 0)
    {
        if (ft_word_is_printable(*(str + i)) != 1)
            i ++;
        else
            write(1, &str[i++], 1);
    }
}

int main(void)
{
    char string[17] = "Il faut un mot\n";
    ft_putstr_non_printable(string);
    return (0);
}