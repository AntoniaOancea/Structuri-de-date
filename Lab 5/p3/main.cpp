#include <iostream>
using namespace std;
struct Tree{
    int Data;
    Tree *Left;
    Tree *Right;
};
void inserare(int x,Tree *Root)
{
    Tree *p1,*p;
    int d;
    p1=Root;
    p=Root;
    d=1;
    while((p!=NULL)&&(d!=0))
    {
        if(x<p->Data)
        {
            p1=p;
            p=p->Left;
            d=-1;
        }
        else
            if(x>p->Data)
            {
                p1=p;
                p=p->Right;
                d=1;
            }
            else
                d=0;
    }
    if(p==NULL)
    {
        //cout<<d<<" ";
        p=new Tree;
        p->Data=x;
        p->Left=NULL;
        p->Right=NULL;
        if(p1==NULL)
            Root=p1;
        else
            {
                if(d<0)
                    p1->Left=p;
                else
                    p1->Right=p;
            }
    }
}
void interval(int k1,int k2,Tree* Root)
{
    if(Root->Data>=k1 && Root->Data<=k2)
    {
            cout<<Root->Data<<" ";
            if(Root->Data>k1 && Root->Left)
                interval(k1,k2,Root->Left);
            if(Root->Data<k2 && Root->Right)
                interval(k1,k2,Root->Right);
    }
    else
    {
        if(Root->Data<k1)
            interval(k1,k2,Root->Right);
        else
            if(Root->Data>k2)
                interval(k1,k2,Root->Left);
    }
}
int main()
{
    Tree* Root=new Tree,*p;
    int n,i,x;
    cin>>n;
    cin>>x;
    Root->Data=x;
    Root->Left=NULL;
    Root->Right=NULL;
    for(i=0;i<n-1;i++)
    {
        cin>>x;
        inserare(x,Root);
    }
    int k1,k2;
    cin>>k1>>k2;
    interval(k1,k2,Root);
    return 0;
}
