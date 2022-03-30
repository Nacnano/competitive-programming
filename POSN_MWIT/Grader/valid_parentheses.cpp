#include<bits/stdc++.h>
using namespace std;

char s[1000005];

int main(){


    stack<char> stk;
    scanf("%s",s);
    int len=strlen(s);
    if(len%2)
    {
        printf("NO");
        return 0;
    }

    bool yes=1;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') stk.push(s[i]);
        else
        {
            if(stk.empty())
            {
                yes=0;
                break;
            }
            else if(stk.top()!='(' && s[i]==')')
            {
                yes=0;
                break;
            }
            else if(stk.top()!='{' && s[i]=='}')
            {
                yes=0;
                break;
            }
            else if(stk.top()!='[' && s[i]==']')
            {
                yes=0;
                break;
            }
            stk.pop();
        }
    }
    if(yes) printf("YES");
    else printf("NO");
}
