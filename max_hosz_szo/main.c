#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* f;
    char szo[50], szo_max[50];
    int n, nr_max = 0;
    f = fopen("input.txt", "rt");
    fscanf(f, "%s", szo);
    n = atoi(szo);
    while (n > 0)
    {
        fscanf(f, "%s", szo);
        if (strlen(szo) > nr_max)
        {
            nr_max = strlen(szo);
            strcpy(szo_max, szo);
        }
        n--;
    }
    fclose(f);
    f = fopen("output.txt", "a");
    fprintf(f,"nr = %i, %s", nr_max, szo_max);
    return 0;
}
