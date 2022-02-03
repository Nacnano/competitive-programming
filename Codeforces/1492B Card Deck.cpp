#include<bits/stdc++.h>
using namespace std;

stack<int> stk;
vector<int> ans[1005];

int main(){

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int mx=-1;
        while(n--)
        {
            int x;
            scanf("%d",&x);
            if(x>mx)
            {
                mx=x;

                while(!stk.empty())
                {
                    ans[t].push_back(stk.top());
                    stk.pop();
                }
            }
            stk.push(x);
        }

        while(!stk.empty())
        {
            ans[t].push_back(stk.top());
            stk.pop();
        }

        for(int i=ans[t].size()-1;i>=0;i--) printf("%d ",ans[t][i]);
        printf("\n");
    }

}
