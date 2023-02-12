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
void RSD(Tree *Root)
{
    if(Root!=NULL)
    {
        cout<<Root->Data<<" ";
        RSD(Root->Left);
        RSD(Root->Right);
    }
}
void SRD(Tree *Root)
{
    if(Root!=NULL)
    {
        SRD(Root->Left);
        cout<<Root->Data<<" ";
        SRD(Root->Right);
    }
}
void SDR(Tree *Root)
{
    if(Root!=NULL)
    {
        SDR(Root->Left);
        SDR(Root->Right);
        cout<<Root->Data<<" ";
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
    //a
    RSD(Root);
    cout<<endl;
    //b
    SRD(Root);
    cout<<endl;
    //c
    SDR(Root);
    cout<<endl;
    return 0;
}
