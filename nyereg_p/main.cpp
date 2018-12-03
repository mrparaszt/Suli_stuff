#include <iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

void kiir(int *n,int *m, int **a);
void beolvas(const char *c,int *n,int *m, int **a);
int nyereg(int *n, int *m, int *pont, int **a);


int main()
{
    const char* c = "beolvas.txt";
    int n, m, **b,*pontok, l;
    pontok = (int*)malloc(10*sizeof(int));
    b = (int**)malloc(50*sizeof(int*));
    for (int i = 0; i< 50; i++)
        b[i] = (int*)malloc(50*sizeof(int));
    beolvas(c, &n, &m, b);
    kiir(&n, &m, b);
    l = nyereg(&n, &m, pontok, b);
    if (l != 0)
    {
        for (int i = 0; i<l; ++i)
            cout<<pontok[i];
    }
    free(pontok);
    for (int i = 0 ;i< 50; ++i)
        free(b[i]);
    free(b);
    return 0;
}


void beolvas(const char *c,int *n,int *m, int **a)
{
    ifstream f;
    f.open(c);
    f >> *n;
    f >> *m;
    for (int i = 0 ; i< *n; ++i)
    {
        for (int j = 0; j< *m; ++j)
        {
            f >> a[i][j];
        }
    }
    f.close();
}
void kiir(int *n,int *m, int **a)
{
    for (int i = 0; i < *n; ++i)
    {
        for (int j = 0; j < *m; ++j)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int nyereg(int *n, int *m, int *pont, int **a)
{
    int y, minx,  miny, l=0;
    for (int i = 0; i < *n; i++)
    {
        minx = a[i][0];
        y = 0;
        for (int j = 1; j < *m; j++)
        {
            if (minx > a[i][j])
            {
                minx = a[i][j];
                y = j;
            }
        }

        for (int j = 0; j < *n-1; ++j)
        {
            miny = min(a[j][y], a[j+1][y]);
        }
        if (minx == miny)
        {
            pont[l] = minx;
            l++;
        }
    }
    return l;
}







