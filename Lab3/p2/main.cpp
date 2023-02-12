#include <iostream>

using namespace std;
struct Node{
    int Data;
    Node *Next;
    Node *Prev;
};
void printList(Node* p)
{
    while (p != NULL) {
        cout << p->Data << " ";
        p = p->Next;
    }
}
void lista(int p,Node *head,int v[])
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
int main()
{
    Node *head1=new Node;
    Node *head2=new Node;
    int n,a[100];
    int m,b[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    lista(n,head1,a);
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>b[i];
    lista(m,head2,b);
    int l1=0,l2=0;
    int p=1;
    while(head1!=NULL)
    {
        l1=head1->Data*p+l1;
        p*=10;
        head1=head1->Next;
    }
    p=1;
    while(head2!=NULL)
    {
        l2=head2->Data*p+l2;
        p*=10;
        head2=head2->Next;
    }
    cout<<l1+l2;
    return 0;
}
