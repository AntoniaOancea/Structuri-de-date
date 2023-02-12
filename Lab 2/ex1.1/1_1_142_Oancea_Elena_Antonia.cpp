//Merge Sort
#include <iostream>

using namespace std;
void interclasare(int v[],int s,int m,int d)
{
    int l1= m-s+1;
    int l2=d-m;
    int a[l1],b[l2];

    //formam 2 vectori cu cele 2 jumatati ce le vom interclasa
    for(int i=0; i<l1; i++)
        a[i]=v[s+i];
    for(int i=0; i<l2; i++)
        b[i]=v[m+i+1];
    int i=0,j=0,k=s;

    //interclasarea celor 2 vectori
    while(i<l1 && j<l2)
    {
        if(a[i]<=b[j])
        {
            v[k]=a[i];
            i++;
        }
        else
        {
            v[k]=b[j];
            j++;
        }
        k++;
    }

    //in unul dintre vectori a ramas cel putin 1 element neinterclasat
    while(i<l1)
    {
        v[k]=a[i];
        i++;
        k++;
    }

    while(j<l2)
    {
        v[k]=b[j];
        j++;
        k++;
    }
}
void mergeSort(int v[],int s,int d)
{
    //impartim vectorul si efectuam interclasarea pe ramuri
    if(s>=d)
        return;
    int m=(s+d)/2;
    mergeSort(v,s,m);
    mergeSort(v,m+1,d);
    interclasare(v,s,m,d);
}
int main()
{
    int n,v[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    mergeSort(v,0,n-1);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}
