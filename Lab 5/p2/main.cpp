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
void StergereAux(Tree *&s, Tree *&Dreapta)
{
    //Dreapta - cautam nodul cel mai din dreapta
    //nodul este inlocuit de cel mai mare nod din subarborele stang
    if(s->Right)
        StergereAux(s ->Right , Dreapta);
    else
    {
        Dreapta->Data = s->Data;
        Tree * aux = s;
        s = s->Left;
        delete aux;
    }
}

void Stergere(Tree *&s , int x)
{
    if(s!=NULL)
    {
        if(s->Data == x)
        {
            // nodul trebuie șters
            if(s->Left == NULL && s->Right == NULL)//nodul e frunza
            {
                delete s;
                s = NULL;
            }
            else
                if(s->Right == NULL)//are doar fiu stang si nodul sters este inlocuit cu fiul stang
                {
                    Tree * aux = s;
                    s = s->Left;
                    delete aux;
                }
                else
                    if(s->Left == NULL)//are doar fiu drept si nodul sters este inlocuit cu fiul drept
                    {
                        Tree * aux = s;
                        s = s->Right;
                        delete aux;
                    }
                    else//are ambii fii
                        StergereAux(s->Left, s);
        }
        else//nu am gasit inca nodul cu val x
            if(s->Data > x)
                Stergere(s->Left , x);
            else
                Stergere(s->Right , x);
    }
    else
        cout<<"Nu exista nodul "<<x<<endl;
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
int main()
{
    Tree* Root=new Tree,*p;
    int n,i,x,y;
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
    RSD(Root);
    cout<<"Ce nod vrei sa stergi?\n";
    cin>>y;
    Stergere(Root,y);
    RSD(Root);
    return 0;
}
