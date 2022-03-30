#include<bits/stdc++.h>
using namespace std;

stack<char> stk;
vector<double> v;

int pri(char c)
{
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    else return 0;
}

int main(){

    string s;
    cin >> s;

    for(int i=0;s[i];i++)
    {
        if((s[i] >= '0' && s[i] <= '9') || s[i]=='.')
        {
            double num=s[i]-'0';
            while(s[i+1] >='0' && s[i+1] <='9')
            {
                num*=10;
                num+=s[i+1]-'0';
                i++;
            }

            if(s[i+1]=='.')
            {
                i++;
                i++;
                double dec=0.1;
                num+=(s[i]-'0')*dec;
                while(s[i+1]>='0' && s[i+1] <='9')
                {
                    i++;
                    dec/=10;
                    num+=(s[i]-'0')*dec;
                }
            }
            v.push_back(num);
        }

        else if(s[i]=='(')
        {
            stk.push(s[i]);
        }

        else if(s[i]==')')
        {
            while(!stk.empty())
            {
                if(stk.top()=='(')
                {
                    stk.pop();
                    break;
                }
                v.push_back(-stk.top());
                stk.pop();
            }
        }

        else
        {

            while(!stk.empty())
            {
                if(pri(s[i]) <= pri(stk.top()))
                {
                    v.push_back(-stk.top());
                    stk.pop();
                }
                else break;
            }
            stk.push(s[i]);

        }
    }

    while(!stk.empty())
    {
        v.push_back(-stk.top());
        stk.pop();
    }

    stack<double> stk2;
    for(auto x:v)
    {
        if(x>=0)
        {
            stk2.push(x);
        }
        else
        {
            double a=stk2.top();
            stk2.pop();
            double b=stk2.top();
            stk2.pop();

            double c;
            if(-x=='+') c=b+a;
            else if(-x=='-') c=b-a;
            else if(-x=='*') c=b*a;
            else if(-x=='/') c=b/a;

            stk2.push(c);
        }
    }
    printf("%.3f",stk2.top());
}
