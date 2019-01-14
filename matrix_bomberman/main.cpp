#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n, m;
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    int v[n][m];
    for (int i=0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = (rand()%10);
        }
    }

     for (int i=0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<v[i][j]<<"\t";
        }
        cout<<"\n";
    }
    int x,y;
    x = 0;
    y = 0;
    while (x < n && y < m)
    {
        for ( int i = y; i < m; ++i)
        {
            cout<<v[x][i]<<" ";
        }
        x++;
        for ( int i = x; i < n; i++)
        {
            cout<<v[i][m - 1]<<" ";
        }
        m--;
        if ( x < n)
        {
            for (int i = m-1; i >= y; --i)
            {
                cout<<v[n-1][i]<<" ";
            }
            n--;
        }
        if (y < m)
        {
            for (int i = n-1; i >= x; --i)
            {
                cout<< v[i][y]<<" ";
            }
            y++;
        }
    }

    return 0;
}
