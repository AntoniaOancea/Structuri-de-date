//Cautarea binara

#include <iostream>

using namespace std;
int cautare_binara(int a[],int p,int u,int x)
{
    if (p>u)
        return 0;
    int m=(p+u)/2;
    if (x==a[m])
        return 1;
    if (x>a[m])
        return cautare_binara(a,m+1,u,x);
    return cautare_binara(a,p,m-1,x);
}
int main()
{
    int n,i,x,a[100];
    cin>>n;
    for(i=0 ;i<n;i++)
        cin>>a[i];
    cin>>x;
    if(cautare_binara(a,0,n-1,x))
        cout<<x<<" se gaseste in sir";
    else
        cout<<x<<" nu se gaseste in sir";
    return 0;
}
