#include <stdio.h>
#include <stdlib.h>

int main()
{
    char szo[30];
    int i;
    FILE *f;
    f = fopen("input.txt", "rt");
    fscanf(f, "%s", szo);
    i = szo;
    printf("%i", i);

    fclose(f);
    return 0;
}
