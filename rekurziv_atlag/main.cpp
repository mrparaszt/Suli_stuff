#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
float atlag(int n, int *a, int nr);
void beolvas(const char *c,int *n, int *a);
void kiir(int *n, int *a);
int mina(int n, int *a);
int lnko(int a, int b);
int sumo(int a);
int minx(int a);
void kiirx(int x);

int main()
{
    const char *c = "input.txt";
    int n=5, *a;
    a = (int*) malloc (n * sizeof(int));
    beolvas(c, &n, a);
    kiir(&n, a);
    cout<<"Atlag:"<<atlag(n, a, 0)<<"\n";
    cout<<"minimum"<<mina(n, a)<<"\n";
    cout<<"lnko"<<lnko(15, 5)<<"\n";
    cout<<"sum:"<<sumo(15)<<"\n";
    cout<<"min_szj:"<<minx(5447)<<"\n";
    kiirx(175);


    free(a);
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
float atlag(int n, int *a, int nr)
{
    if (nr == 0)
        return (atlag(n, a, nr+1) + a[nr]) / n;
    if (n > nr+1)
        return atlag(n, a, nr+1) + a[nr];
    else
            return a[n-1];
}
int mina(int n, int *a)
{
    if (n > 1)
    {
        int x;
        x = a[n-1];
        if (mina(n-1, a) > x)
            return x;
        else
            return mina(n-1, a);
    }
    if (n == 1)
        return a[0];
}
int lnko(int a, int b)
{
    if (a == b)
        return a;
    else
    {
        if (a > b)
            return lnko(a-b, b);
        else
            return lnko(a, b-a);
    }
}
int sumo(int a)
{
    if (a % 10 == 0)
        return a;
    else
        return sumo(a/10)+a % 10;
}
int minx(int a)
{
    if (a % 10 == 0)
        return a;
    else
        {
            if (a % 10 < minx(a / 10))
                return a % 10;
            else
                return a / 10 % 10;
        }
}
void kiirx(int x)
{
    if (x % 100 == 0)
    {
        cout<<x<<"\n";
        return ;
    }
    else
    {
        cout<<x% 10<<"\n";
        return kiirx(x / 10);
    }
}






