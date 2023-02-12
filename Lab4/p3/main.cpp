#include <iostream>

using namespace std;
struct Node{
    int Data;
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
void inserare(int val,Node* &Rear,Node* &Front)
{
    Node *aux;
    if(Front==NULL)
    {
        Front=new Node;
        Front->Data=val;
        Front->Next=NULL;
        Rear=Front;
    }
    else
    {
        aux=new Node;
        Rear->Next=aux;
        aux->Data=val;
        Rear=aux;
        Rear->Next=NULL;
    }
}
void stergere(Node* &Front,Node* &Rear)
{
    Node*aux;
    aux=Front;
    if(aux==NULL)
        cout<<"Stiva goala";
    else
    {
        while((aux->Next)!=Rear)
        {
            aux=aux->Next;
        }
        aux->Next=NULL;
        Rear=aux;
    }
}
int main()
{
    int i,n,x;
    Node* Rear=new Node;
    Node* Front=new Node;
    cin>>n;
    Front=Front->Next;
    for(i=0;i<n;i++)
        {
            cin>>x;
            if(Rear->Data==x)
               {
                   if(Front==Rear)
                    Front=NULL;
                   else
                    stergere(Front,Rear);
               }
            else
            {
                inserare(x,Rear,Front);
            }
        }
    //printList(Front);
    if(Front)
        cout<<"configuratie invalida";
    else
        cout<<"configuratie valida";
    return 0;
}
