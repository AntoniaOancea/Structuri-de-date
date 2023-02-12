//Quick Sort-descrescator
#include <iostream>

using namespace std;
void interschimbare(int &x,int &y)
{
    int aux;
    aux=x;
    x=y;
    y=aux;
}
int partitii(int v[],int s,int d)
{
    //luam ca si pivot elementul cel mai din dreapta
    int pivot;
    pivot=v[d];
    int i=s-1;
    for(int j=s;j<d;j++)
    {
        //aducem elem mai mari decat pivotul in fata lui prin interschimbare
        if(v[j]>=pivot)
        {
            i++;
            interschimbare(v[i],v[j]);
        }
    }
    interschimbare(v[i+1],v[d]);
    return i+1;

}
void quickSort(int v[],int s,int d)
{
    if(s<d)
    {
        int p;
        p=partitii(v,s,d);
        quickSort(v,s,p-1);
        quickSort(v,p+1,d);
    }
}
int main()
{
    int n,v[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    quickSort(v,0,n-1);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}
