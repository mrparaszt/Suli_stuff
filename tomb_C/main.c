#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char szo[30];
    int i, n;
    float t;
    FILE *f;
    f = fopen("input.txt", "rt");
    fscanf(f, "%s", szo);
    n = atoi(szo);
    int m = n;
    i = 0;
    char nevek[n][50];
    for (int j=0; j < n; j++)
        strcpy(nevek[j], "");
    double media[n];
    while (n > 0)
    {
        fscanf(f, "%s", szo);
        t = atof(szo);
        if (t == 0.0)
        {
            strcat(nevek[i], szo);
            strcat(nevek[i], " ");
            //printf("nevek:%s\n", nevek[i]);
        }
        else
        {
            media[i] = atof(szo);
           // printf("media:%f\n", media[i]);
            n--;
            i++;
        }
    }

    double temp_m;
    char temp_n[50];
    for (i = 0; i < m; i++)
    {
        for (int j = i+1; j < m; j++)
        {
            if (media[i] > media[j])
            {
                temp_m = media[i];
                strcpy(temp_n, nevek[i]);
                //printf("%f, %s", temp_m, temp_n);
                media[i] = media[j];
                media[j] = temp_m;
                strcpy(nevek[i], nevek[j]);
                strcpy(nevek[j], temp_n);
            }
        }
    }
    fclose(f);

    f = fopen("output.txt", "a");
    for (i = 0; i < m; i++)
    {
        fprintf(f, "%s: ", nevek[i]);
        fprintf(f, "%f\n", media[i]);
    }
    fclose(f);
    return 0;
}
