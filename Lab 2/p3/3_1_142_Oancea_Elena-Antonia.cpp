//interclasare
#include <iostream>

using namespace std;
void inserare(int a[],int na,int x,int poz)
{
    for(int k=na;k>poz;k--)
        a[k]=a[k-1];
    a[poz]=x;
}
int main()
{
    int i,j,na,nb,a[100],b[100];
    cin>>na;
    for(i=0;i<na;i++)
        cin>>a[i];
    cin>>nb;
    for(i=0;i<nb;i++)
        cin>>b[i];
    i=nb-1;
    j=na-1;
    while(i>=0 && j>=0)
    {
        if (a[j]<b[i])
            {
                inserare(a,na,b[i],j+1);//insereaza pe b[i] pe pozitia j+1
                na++;
                i--;
            }
        else j--;
    }
    for(int k=i;k>=0;k--)
        {inserare(a,na,b[k],0);na++;}

    for(i=0;i<na;i++)
        cout<<a[i]<<" ";
    return 0;
}
