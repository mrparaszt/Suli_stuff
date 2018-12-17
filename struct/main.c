#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct cim
    {
        char utca[30], varos[30];
        int hazszam;
    };
    typedef struct{
        char nev[50];
        struct cim c;
    }Diak;
    Diak d[10];
    d[2].c.hazszam = 5;
    printf("%i", d[2].c.hazszam);
    strcpy(d[2].c.utca, "Nay");
    printf("%s", d[2].c.utca);
    return 0;
}
