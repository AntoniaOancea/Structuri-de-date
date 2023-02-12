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
int stramos(int x,int y,Tree *Root)
{
    if(x<Root->Data && y>Root->Data)
        return Root->Data;
    else
        if(x<Root->Data)
            return stramos(x,y,Root->Left);
        else
            return stramos(x,y,Root->Right);
}
int main()
{
    Tree* Root=new Tree;
    int n,i,p;
    cin>>n;
    cin>>p;
    Root->Data=p;
    Root->Left=NULL;
    Root->Right=NULL;
    for(i=0;i<n-1;i++)
    {
        cin>>p;
        inserare(p,Root);
    }
    int x,y;
    cin>>x;
    cin>>y;
    //x<=y
    if(x>y)
    {
        int aux=x;
        x=y;
        y=aux;
    }
    cout<<stramos(x,y,Root);
    return 0;
}
