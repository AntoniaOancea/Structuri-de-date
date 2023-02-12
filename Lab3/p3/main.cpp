#include <iostream>
#include<math.h>
using namespace std;
struct Node{
    int Grade,Coef;
    Node *Next;
};
void polinom(int p,Node *head,int v[100][3])
{
    head->Grade=v[0][0];
    head->Coef=v[0][1];
    head->Next=NULL;
    for(int i=1;i<=p;i++)
    {
        Node *x=new Node;
        x->Grade=v[i][0];
        x->Coef=v[i][1];
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
void printList(Node* p)
{
    while (p != NULL) {
        cout << p->Grade <<" "<<p->Coef<< endl;
        p = p->Next;
    }
}
void polinom_3_1(Node *headp,int a)
{
    Node *mul=headp;
    while(headp!=NULL)
    {
        headp->Coef=headp->Coef*a;
        headp=headp->Next;
    }
    printList(mul);
}
void polinom_3_2(int x0,Node *headp)
{
    int rezultat=0;
    while(headp!=NULL)
    {
        rezultat=rezultat+headp->Coef*pow(x0,headp->Grade);
        headp=headp->Next;
    }
    cout<<rezultat<<endl;

}
void polinom_3_3(Node *headp,Node *headq,int n,int m)
{
    while(headp!=NULL && headq!=NULL)
    {
        if(headp->Grade>headq->Grade)
           {
            cout<<headp->Coef<<" x^"<<headp->Grade<<" ";
            headp=headp->Next;
           }
        else
            if(headp->Grade<headq->Grade)
            {
                cout<<headq->Coef<<" x^"<<headq->Grade<<" ";
                headq=headq->Next;
            }
        else
        {
            cout<<headp->Coef+headq->Coef<<" x^"<<headp->Grade<<" ";
            headp=headp->Next;
            headq=headq->Next;
        }
    }
}
int main()
{
    int n,m,i;
    int p[100][3],q[100][3];
    cin>>n;
    for(i=0;i<=n;i++)
        cin>>p[i][0]>>p[i][1];
    cin>>m;
    for(i=0;i<=m;i++)
        cin>>q[i][0]>>q[i][1];
    Node *headp=new Node;
    Node *headq=new Node;
    polinom(n,headp,p);
    polinom(m,headq,q);
    printList(headp);
    cout<<endl;
    printList(headq);
    cout<<endl;
    int a;
    cout<<"a=";
    cin>>a;
    polinom_3_1(headp,a);
    int x0;
    cout<<"x0=";
    cin>>x0;
    polinom_3_2(x0,headp);
    cout<<endl;
    polinom_3_3(headp,headq,n,m);
    return 0;
}
