#include <iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;
void beolvas(const char *c,int *n, int *a);
int minr(int n, int *a);

int main()
{
    const char* c= "input.txt";
    int n=5, *a;
    a = (int*)malloc(n*sizeof(int));
    beolvas(c, &n, a);
    cout<<minr(n, a);
    return 0;
}

int minr(int n, int *a)
{
    if (n == 1)
        return a[0];
    int t = minr(a+1, n-1);
    return a[0] < t ? a[0]:t;
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

