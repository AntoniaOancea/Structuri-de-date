//Bubble Sort

#include <iostream>

using namespace std;
void bubblesort(int x[],int n)
{
    int i,j,aux;
    for (i=0;i<n-1;i++)
    {
        int ok=0;
        for(j=0;j<n-i-1;j++)
        {
            if (x[j]>x[j+1])
            {
                aux=x[j];
                x[j]=x[j+1];
                x[j+1]=aux;
                ok=1;
            }
        }
        if (ok==0)break;
    }
}
int main()
{

    int i,n,x[100];
    cin>>n;
    for (i=0;i<n;i++)
        cin>>x[i];
    bubblesort(x,n);
    for (i=0;i<n;i++)
        cout<<x[i]<<" ";
    return 0;
}
