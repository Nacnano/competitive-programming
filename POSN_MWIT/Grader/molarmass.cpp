#include<bits/stdc++.h>
using namespace std;



int main(){

    int q;
    scanf("%d",&q);

    while(q--)
    {
        char s[105];
        scanf("%s",s);
        stack <int> stk;

        for(int i=0;s[i];i++)
        {
            if(s[i]=='(')
            {
                int sum=0;
                i++;
                while(s[i]!='(' && s[i]!=')')
                {
                    if(s[i]=='H') sum++;
                    else if(s[i]=='O') sum+=16;
                    else if(s[i]=='C') sum+=12;
                    else if(s[i]>='2' && s[i]<='9')
                    {
                        if(s[i]=='H') sum+=(s[i]-'0'-1);
                        else if(s[i]=='O') sum+=16*(s[i]-'0'-1);
                        else if(s[i]=='C') sum+=12*(s[i]-'0'-1);
                    }
                    i++;
                }

                if(s[i]=='(')
                {
                    stk.push(sum);
                    i++;
                }
                else if(s[i]==')')
                {
                    i++;
                    int val=stk.top()*
                }
            }

        }
    }
}
