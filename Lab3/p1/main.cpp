#include <iostream>

using namespace std;
class Node{
public:
    int Data;
    Node *Next;
};
void printList(Node* p)
{
    while (p != NULL) {
        cout << p->Data << " ";
        p = p->Next;
    }
}
void Lista_1_1(int n,Node *head,int a[])
{
    head->Data=a[0];
    for(int i=1;i<n;i++)
    {
        Node *x=new Node;
        x->Data=a[i];
        x->Next=NULL;
        Node *y=head;
        Node *z;
        if(x->Data < y->Data)
        {
            x->Next=head;
            head=x;
        }
        else
        {
            while(y!=NULL && x->Data >= y->Data )
            {
                z=y;
                y=y->Next;
            }
            x->Next=y;
            if(z!=NULL)
               z->Next=x;
        }
    }
}
int Lista_1_3_verificare(int val,Node *p)
{
    int nr=0;
    while(p!=NULL)
    {
        nr++;
        if(p->Data==val)
            return nr-1;
        else
            if(p->Data > val)
                return 0;
        p=p->Next;
    }
    return 0;
}
void Lista_1_3_stergere(int val,Node *p)
{
    while(p!=NULL)
    {
        if(p->Next->Data==val)
        {
            Node *temp=p->Next;
            p->Next=p->Next->Next;
            delete temp;
            break;
        }
        p=p->Next;
    }
}
void Lista_1_2(Node *head)
{
    Node *temp=new Node;
    while(head!=NULL)
    {
        temp=head;
        head=head->Next;
        delete temp;
    }
}
int main()
{
    int n;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    Node *head=new Node;
    //ex 1_1
    Lista_1_1(n,head,a);
    printList(head);
    cout<<endl;
    //ex 1_3
    int val;
    cin>>val;
    if( Lista_1_3_verificare(val,head)!=0 )
        {
            int nr=Lista_1_3_verificare(val,head);
            Lista_1_3_stergere(val,head);
            printList(head);
        }
    else
        cout<<val<<" nu exista in lista";
    cout<<endl;
    //ex 1_2
    Lista_1_2(head);
    return 0;
}
