#include <iostream>
using namespace std;
struct Tree{
    string Data;
    Tree *Left;
    Tree *Right;
};
void inserare(string x,Tree *Root)
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
void DRS(Tree *Root)
{
    if(Root!=NULL)
    {
        DRS(Root->Right);
        cout<<Root->Data<<" ";
        DRS(Root->Left);
    }
}
int main()
{
    Tree* Root=new Tree,*p;
    int n,i;
    string x;
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
    DRS(Root);
    return 0;
}
