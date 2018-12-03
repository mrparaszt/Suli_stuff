#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n, x; float nr1=0, nr0=0, sum1=0, sum0=0;
    cout<<"n=";
    cin>>n;
    for (int i=0; i<n; i++)
    {
        x =(rand()%100);
        if (x % 2 == 0)
        {
            sum0 += x;
            nr0+=1;
        }
        else
        {
            sum1 += x;
            nr1 += 1;
        }
    }
    cout<<"Paratlanok atlaga="<<sum1/nr1<<"\nParosok atlaga="<<sum0/nr0;

    return 0;
}
