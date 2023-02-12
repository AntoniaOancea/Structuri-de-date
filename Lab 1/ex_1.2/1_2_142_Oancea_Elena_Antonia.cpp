//Insertion Sort

#include <iostream>

using namespace std;
void inserare(int a[],int p,int q)
{
    int x,k;
    x=a[p];
    for(k=p-1;k>q;k--)
        a[k+1]=a[k];
    a[q+1]=x;
}
void insertion_sort(int a[],int n)
{
    int i,j;
    for (i=1;i<n;i++)
        if(a[i]<a[i-1])
            for (j=i-1;j>=0;j--)
                if(a[i]>a[j])
                {
                    inserare(a,i,j);
                    break;
                }
                else
                    if(j==0)
                    {
                        inserare(a,i,-1);
                        break;
                    }
}
int main()
{
    int n,i,a[100];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    insertion_sort(a,n);
    for (i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
