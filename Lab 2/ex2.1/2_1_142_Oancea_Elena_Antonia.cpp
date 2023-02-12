//Heap Sort-max heap
#include <iostream>

using namespace std;
void interschimbare(int &x,int &y)
{
    int aux=x;
    x=y;
    y=aux;
}
void max_heap(int v[],int n,int i)
{
    int j=i;
    int s=2*i+1;//fiul stang
    int d=2*i+2;//fiul drept
    //cautam fiul care are o valoare mai mare decat parintele sau
    if(s<n && v[s]>v[j])
        j=s;
    if(d<n && v[d]>v[j])
        j=d;
    //in cazul in care gasim ii interschimbam
    if(j!=i)
    {
        interschimbare(v[i],v[j]);
        max_heap(v,n,j);
    }
}
void heapSort(int v[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        max_heap(v,n,i);
    for(int i=n-1;i>=0;i--)
    {
        interschimbare(v[0],v[i]);
        max_heap(v,i,0);
    }
}
int main()
{
    int i,n,v[100];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>v[i];
    heapSort(v,n);
    for(i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}
