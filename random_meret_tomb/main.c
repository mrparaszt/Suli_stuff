#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    int a[1] = {0};
    unsigned int n, l=1, teszt=0;

    f = fopen("input.txt", "rt");
    fscanf(f, "%d", &n);
    l = l << n;

    printf("%d\n", l);
    teszt = teszt | l;
    printf("%d\n", teszt);
    int nr = 0;
    while (teszt % 2 == 0)
    {
        teszt >> 2;
        printf("%d", teszt);
        nr++;
    }
    printf("%d", nr);





    fclose(f);


    return 0;
}
