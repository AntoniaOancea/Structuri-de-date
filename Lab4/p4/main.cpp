#include <iostream>
//#include<fstream>
using namespace std;
//ifstream f("f.in");
struct Node{
    int Data;
    int linie;
    int coloana;
    Node *Next;
};
void printList(Node* p)
{
    while (p != NULL) {
        cout << p->Data << " ";
        p = p->Next;
    }
    cout<<endl;
}
void inserare(int val,Node* &Rear,Node* &Front,int i,int j)
{
    Node* aux;
    if(i+j==0)
    {
        Front=new Node;
        Front->Data=val;
        Front->linie=i;
        Front->coloana=j;
        Front->Next=NULL;
        Rear=Front;
    }
    else
    {
        aux=new Node;
        Rear->Next=aux;
        aux->Data=val;
        aux->linie=i;
        aux->coloana=j;
        Rear=aux;
        Rear->Next=NULL;
    }
}
int main()
{
    int m,a[100][100],x;
    cin>>m;
    Node* Front=new Node;
    Node* Rear=new Node;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
           {
               cin>>x;
               inserare(x,Rear,Front,i,j);
           }
    printList(Front);
    Node* aux;
    aux=Front;
    int k=1;
    while(aux)
    {
        if(aux->Data==1)
        {
            int i=aux->linie;
            int j=aux->coloana;
            if(a[i-1][j]!=0 && i!=0)
                a[i][j]=a[i-1][j];
            else
                if(a[i][j-1]!=0 && j!=0)
                    a[i][j]=a[i][j-1];
            else
            {
                k++;
                a[i][j]=k;
            }
        }
        aux=aux->Next;
    }
    aux=Front;
    while(aux)
    {
        if(aux->Data!=0)
        {
            int i=aux->linie;
            int j=aux->coloana;
            if(a[i-1][j]!=a[i][j] && i!=0 && a[i-1][j])
                if(a[i][j]<a[i-1][j])
                    a[i-1][j]=a[i][j];
                else
                    a[i][j]=a[i-1][j];
            else
            if(a[i][j-1]!=a[i][j] && i!=0 && a[i][j-1])
                if(a[i][j]<a[i][j-1])
                    a[i][j-1]=a[i][j];
                else
                    a[i][j]=a[i][j-1];
        }
        aux=aux->Next;
    }
    for(int i=0;i<m;i++)
    {for(int j=0;j<m;j++)
        cout<<a[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}
