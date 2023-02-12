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
    //cautam pentru fiecare elem al lui b pozitia corespunzatoare in a
    //while(j>=0)
    //{
        while(i>=0 && j>=0)
        {
            if (a[j]<b[i])
                {
                    inserare(a,na,b[i],j+1);//insereaza pe b[j] pe pozitia i
                    na++;
                    i--;
                   // break;//am gasit si inserat elem
                }
            else j--;
           // i--;
        }
        for(int k=j;k>=0;k--)
            inserare(a,na,b[k],0);
        //j--;
    //}
    for(i=0;i<na;i++)
        cout<<a[i]<<" ";
    return 0;
}
