//Cautarea secventiala

#include <iostream>

using namespace std;
int cautare_elem(int x,int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        if (a[i]==x)
            return 1;
    return 0;
}
int main()
{
    int n,a[100],x;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>x;
    if(cautare_elem(x,a,n))
        cout<<x<<" se gaseste in sir";
    else
        cout<<x<<" nu se gaseste in sir";
    return 0;
}
