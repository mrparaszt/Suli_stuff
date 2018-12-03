#include <iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

void beolvas1(const char *c,int *n, int *a);
void kiir1(int *n, int *a);
void beolvas2(const char *c,int *n,int *m, int **a);
void kiir2(int *n,int *m, int **a);

int main()
{
    const char *c = "beolvas.txt";
    const char* c2= "beolvas2.txt";
    int n, *a=0,**b, n2, m2;
    a = (int*)malloc(50*sizeof(int));
    b = (int**)malloc(50*sizeof(int*));
    for (int i = 0; i< 50; i++)
    {
        b[i] = (int*)malloc(50*sizeof(int));
    }
    beolvas1(c, &n, a);
    kiir1(&n, a);
    beolvas2(c2, &n2, &m2, b);
    kiir2(&n2, &m2, b);
    free(a);
    for (int i = 0; i< n2; ++i)
        free(b);
    free(b);
    return 0;
}

void beolvas1(const char *c,int *n, int *a)
{
    ifstream f;
    f.open(c);
    f >> *n;
    //a = (int*)malloc(*n*sizeof(int));

    for (int i=0; i<*n; ++i)
    {
        f >> a[i];
    }
    f.close();
}

void kiir1(int* n, int *a)
{
    for (int i = 0; i< *n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void beolvas2(const char *c,int *n,int *m, int **a)
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

void kiir2(int *n,int *m, int **a)
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





