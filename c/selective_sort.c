#include <stdio.h>
#include <stdlib.h>

void     select_sort(int *a, int size)
{
    int i;
    int j;
    int aux;

    aux = 0;
    i = 0;
    j = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size - 1)
        {
            if (a[j] < a[i])
            {
                aux = a[j];
                a[j] = a[i];
                a[i] = aux;
            }
            j++;
        }
        i++;
    }
}

int     main(void)
{
    int a[] = { 1, 3, 5, 6, 2, 8, 4, 7};
    int len = sizeof(a) / sizeof(a[0]);
    int i = 0;

    select_sort(a, len);
    while (i < len)
    {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
    return (0);
}
