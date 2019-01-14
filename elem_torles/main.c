#include <stdio.h>
#include <stdlib.h>



int main()
{
    int v[5] = { 5, 6, 2, 6, 3};
    int n = 5;
    int x = 2;
        int check = 0;
    for (int i = 0 ; i<=n-1; i++)
    {
        if (v[i] == x)
            check = i;
    }
    if (check !=0 )
    {
        for (int i=check; i<= n-2; i++)
            v[i]=v[i+1];
    }
    v[n-1] = 0;
    for (int i=0; i <= n-2 ;i++)
        printf("%d ", v[i]);

    return 0;
}
