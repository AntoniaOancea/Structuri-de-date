//Căutarea lui 5 în (15 16 19 20 25 1 3 4 5 7 10 14)
#include <iostream>
#include<cstring>
using namespace std;
int char_to_int(char s[],int j)
{
    int b=0;
    for(int i=j;i<strlen(s);i++)
        if(s[i]>='0' && s[i]<='9')
            b=b*10+s[i]-48;
    return b;
}
int main()
{
    char s[100];
    int ok=0,ok2=0;
    int x,y,n=-1;
    while(cin>>s && ok2==0)
    {
        if ((s[0]>='0' && s[0]<='9')||s[0]=='(' )
            if(ok==0)
            {
                x=char_to_int(s,0);
                ok=1;
            }
            else
               {
                   if(s[0]=='(')
                {
                    y=char_to_int(s,1);
                    if(y==x)ok2=1;
                    n++;

                }
                else
                {
                    y=char_to_int(s,0);
                    if(y==x)ok2=1;
                    n++;
                }
               }
    }
    if(ok2==1)
        cout<<n;
    else
        cout<<"nu exista";
    return 0;
}
