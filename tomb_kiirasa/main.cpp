#include <iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

void beolvas(const char *c,int *n, int *a);
void kiir(int *n, int *a);
void kiirv2(int n, int *a);
void kiirv3(int n, int *a);

int main()
{
    const char* c= "input.txt";
    int n=5, *a;
    a = (int*)malloc(n*sizeof(int));
    beolvas(c, &n, a);
    kiirv3(n, a);

    return 0;
}



void beolvas(const char *c,int *n, int *a)
{
    ifstream f;
    f.open(c);
    f >> *n;
    for (int i = 0 ; i< *n; ++i)
    {
            f >> a[i];
    }
    f.close();
}
void kiir(int *n, int *a)
{
    for (int i = 0; i < *n; ++i)
    {
            cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void kiirv2(int n, int *a)
{
    if (n == 1)
    {
        cout<<a[0];
        return ;
    }
    else
    {
        cout<<a[n-1]<<" ";
        return kiirv2(n-1, a);
    }
}

void kiirv3(int n, int *a)
{

    if (n != 1)
    {
        cout<<a[n-1]<<" ";
        return kiirv2(n-1, a);
    }
    else
    {
        cout<<a[0];
        return ;
    }
}




