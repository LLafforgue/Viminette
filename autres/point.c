#include <stdio.h>

void ft_print(int *buff, int size)
{
    if (size == 0)
        return ;
    printf("%d\n", *buff);
    return ft_print(buff + 1, size-1);
}

void ft_sort_tab(int *buff, int size)
{
    int min ;
    int i;
    
    if (size <= 1)
        return ;
    i = 1;
    min = *buff;
    while (i < size)
    {
        if (min > *(buff + i))
        {
            min = *(buff + i);
            *(buff + i) = *buff;
            *buff = min;
        }
        i ++;
    }
    ft_sort_tab(buff + 1, size - 1);
}

int main(void)
{
    int tab[6] = {4, 2, 4, 2, 8, 4};
    ft_sort_tab(tab, 6);
    ft_print(tab, 6);
}