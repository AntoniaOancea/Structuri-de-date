//Selection Sort

#include <iostream>

using namespace std;
int minim(int p,int q,int &poz,int x[])
{
    int j,min1;
    for (j=p;j<=q;j++)
        if(x[j]<min1)
            {
                poz=j;
                min1=x[j];
            }
    return min1;
}
int main()
{
    int x[100],n,i,poz,min2;
    cin>>n;
    for (i=0;i<n;i++)
        cin>>x[i];
    poz=-1;
    i=0;
    while(i<n)
    {
        int j,min1=9999;
        for (j=i;j<n;j++)
            if(x[j]<min1)
            {
                poz=j;
                min1=x[j];
            }
        if(poz!=i)
        {
           x[poz]=x[i];
           x[i]=min1;
        }
        i++;
    }
    for(i=0;i<n;i++)
        cout<<x[i]<<" ";
    return 0;
}
