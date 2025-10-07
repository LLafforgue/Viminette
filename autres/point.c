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
    int max ;
    int i;
    
    if (size <= 1)
        return ;
    i = 1;
    max = *buff;
    while (i < size)
    {
        if (max < *(buff + i))
        {
            max = *(buff + i);
            *(buff + i) = *buff;
            *buff = max;
        }
        i ++;
    }
    ft_sort_tab(buff + 1, size - 1);
}

int main(void)
{
    int tab[5] = {5, 12, 11, 1, 18};
    ft_sort_tab(tab, 5);
    ft_print(tab, 5);
}