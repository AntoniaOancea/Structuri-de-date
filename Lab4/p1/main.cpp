#include <iostream>
#include<stdlib.h>
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
void ultimul(Node*p,Node* &Rear)
{
    while (p != NULL) {
        Rear=p;
        p=p->Next;
    }
}
void lista(int p,Node* head,int v[])
{
    head->Data=v[0];
    head->Next=NULL;
    for(int i=1;i<p;i++)
    {
        Node *x=new Node;
        x->Data=v[i];
        x->Next=NULL;
        Node *y=head;
        Node *z;
        while(y!=NULL)
        {
            z=y;
            y=y->Next;
        }
        z->Next=x;
    }
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
void stergere(Node* &Front)
{
    Node*aux;
    aux=Front;
    if(aux==NULL)
        cout<<"Stiva goala";
    else
    {
        aux=Front;
        Front=Front->Next;
        delete aux;
    }
}
int main()
{
    Node* Front=new Node;
    Node* Rear=new Node;
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    lista(n,Front,a);
    ultimul(Front,Rear);
    printList(Front);
    //Stergere
    stergere(Front);
    printList(Front);
    //Inserare
    int x;
    cout<<"Ce sa inserez? ";
    cin>>x;
    inserare(x,Rear,Front);
    printList(Front);
    return 0;
}
