#include <iostream>
#include<cstring>
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
    char s[103];
    cin.getline(s,100);
    Node* Front=new Node;
    Node* Rear=new Node;
    int n;
    n=strlen(s);
    Front=NULL;
    //lista(n,Front,s);
    //ultimul(Front,Rear);
    //printList(Front);
    int i=0;
    int nrm=0;//numarul de -
    int okm=0;
    while(i<n)
    {
        int p=i;
        int a=0;//numar de format
        if(s[i]=='-' && s[i+1]=='(')
            nrm++;
        if(s[i]==')')
            nrm--;
        if(s[i]=='-' && s[i+1]>='0' && s[i+1]<='9')
           {
               okm=1;
           }
        while(s[i]>='0' && s[i]<='9')
            {
                a=a*10+s[i]-48;
                i++;
            }
        if(i!=p)i--;
        if((nrm+okm)%2!=0)
            a=-a;
        if(a)okm=0;
        if(a)
            inserare(a,Rear,Front);
        i++;
    }
    //printList(Front);
    int r=0;
    Node* p;
    p=Front;
    while(p!=NULL)
        {r=r+p->Data;p=p->Next;}
    cout<<r;
    return 0;
}
