#include <iostream>
#include <stdlib.h>

using namespace std;
void matrixbe(int v[101][101], int n, int m);
void matrixki(int v[101][101], int n, int m);
void csigabe(int v[101][101], int n, int m);
void csigaki(int v[101][101], int b[101][101], int n1, int m1, int n2, int m2, int x, int y);

int main()
{
    int v[101][101], a[101][101],b[101][101],c[101][101];
    matrixbe(v, 101, 101);
    matrixki(v, 101, 101);
    cout<<"\n";
    csigaki(v,a, 101, 101, 42, 54, 13, 25);
    matrixki(a, 42, 54);
    cout<<"\n";
    csigaki(v,b, 101, 101, 22, 23, 24, 50);
    matrixki(b, 22, 23);
    cout<<"\n";
    csigaki(v,b, 101, 101, 41, 10, 5, 52);
    matrixki(b, 41, 10);
    cout<<"\n";

    return 0;
}


void matrixbe(int v[101][101], int n, int m)
{
    for (int i=0; i<n; ++i)
    {
        for (int j = 0; j<m; ++j)
        {
            v[i][j]= rand()%10;
        }
    }
}

void matrixki(int v[101][101], int n, int m)
{
    for (int i=0; i<n; ++i)
    {
        for (int j = 0; j<m; ++j)
        {
            cout<<v[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void csigabe(int v[101][101], int n, int m)
{
    int k = 0,l = 0;
    while(l < n && k < m)
    {
        for (int i=l; i < n; i++)
        {
            cout<<v[l][i]<<" ";
        }
        l += 1;
        for (int i = l; i < m; i++)
        {
            cout<<v[i][n-1]<<" ";
        }
        n -= 1;
        for (int i = n-1; i > k; i--)
        {
            cout<<v[m-1][i]<<" ";
        }
        m -= 1;
        for (int i = m; i > k; i--)
        {
            cout<<v[i][k]<<" ";
        }
        k += 1;
    }
}
void csigaki(int v[101][101],int b[101][101], int n1, int m1, int n2, int m2, int x, int y)
{
    int elemek = n2 * m2, osz1, sor1, osz2, sor2;
    //Nagy matrix sor/oszlop
    if ((n1+x) % 2 == 0)
    {
        osz1 = (n1+x) / 2 -1;
        sor1 = (m1+y) / 2;
    }
    else
    {
        osz1 = (n1+x) / 2;
        sor1 = (m1+y) / 2;
    }
    //Kis matrix sor/oszlop
    if (n2 % 2 == 0)
    {
        osz2 = n2 / 2 -1;
        sor2 = m2 / 2;
    }
    else
    {
        osz2 = n2 / 2;
        sor2 = m2 / 2;
    }

    int nr=0, bal=-1,le=1,jobb=2,fel=-2;

    b[osz2][sor2] = v[osz1][sor1];
    while(nr < elemek - 1)
    {
        for(int i=0;i > bal;i--){
            if (nr >= elemek - 1)break;
			sor1 -= 1;
			sor2 -= 1;
			b[osz2][sor2] = v[osz1][sor1];
			nr++;
		}

		for(int i=0;i < le;i++){
            if (nr >= elemek - 1)break;
			osz1 += 1;
			osz2 += 1;
			b[osz2][sor2] = v[osz1][sor1];
			nr++;
		}

		for(int i=0;i < jobb;i++){
            if (nr >= elemek - 1)break;
			sor1 += 1;
			sor2 += 1;
			b[osz2][sor2] = v[osz1][sor1];
			nr++;

		}

		for(int i=0;i > fel;i--){
            if (nr >= elemek - 1)break;
			osz1 -= 1;
			osz2 -= 1;
			b[osz2][sor2] = v[osz1][sor1];
			nr++;

		}

		bal -= 2;
		le += 2;
		jobb += 2;
		fel -= 2;


    }
}








