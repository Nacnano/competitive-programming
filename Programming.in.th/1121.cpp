#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    while(n--)
    {
        char s[100010];
        scanf("%s",s);
        stack<char> stk;
        bool yes=1;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') stk.push(s[i]);
            else
            {
                if(stk.empty())
                {
                    yes=0;
                    break;
                }
                else if(s[i]==')' && stk.top()=='(') stk.pop();
                else if(s[i]==']' && stk.top()=='[') stk.pop();
                else if(s[i]=='}' && stk.top()=='{') stk.pop();
                else
                {
                    yes=0;
                    break;
                }
            }
        }
        if(!stk.empty()) yes=0;
        if(yes) printf("yes\n");
        else printf("no\n");

        while(!stk.empty()) stk.pop();
    }
}
