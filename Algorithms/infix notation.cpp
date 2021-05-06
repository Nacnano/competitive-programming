#include<bits/stdc++.h>
using namespace std;

stack<char> stk;
vector<int> v;

int pri(char c)
{
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    else return 0;
}

int main(){

    string s;
    cin >> s;

    //Infix to Postfix
    //Convert Operator to negative of itself is required for the case that the value in the vector is equal to ASCII of the operator.
    //For Example, '+' is 43 in ASCII. Therefore, the value -43 is push_backed in the the vector.
    for(int i=0;s[i];i++)
    {
        if(s[i] >='0' && s[i] <= '9')
        {
            int num=s[i]-'0';
            while(s[i+1] >='0' && s[i+1] <='9')
            {
                num*=10;
                num+=s[i+1]-'0';
                i++;
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

    //Postfix Calculation

    stack<double> stk2;
    for(auto x:v)
    {
        if(-x!='+' && -x!='-' && -x!='*' && -x!='/')
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
    printf("%lf",stk2.top());
}
