#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("n erteke :");
    scanf(" %d", &n);
    int num = 0;
    for (int i = 0; num < n; i++)
    {
        for (int j = 0; j < i+1 && num < n; j++)
        {
            printf("%d ", j+1);
            ++num;
        }
    }


    return 0;
}
