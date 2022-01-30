#include<bits/stdc++.h>
using namespace std;

int main(){

    while(1)
    {
        int n,a[1005];
        scanf("%d",&n);
        if(!n) break;

        for(int i=0;i<n;i++) scanf("%d",&a[i]);

        int now=1;
        stack<int> stk;
        bool chk=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==now) now++;
            else
            {
                while(!stk.empty() && stk.top()==now)
                {
                    stk.pop();
                    now++;
                }
                if(a[i]==now) now++;
                else if(stk.empty() || stk.top()> a[i]) stk.push(a[i]);
                else chk=0;
            }
        }
        if(chk) printf("yes\n");
        else printf("no\n");
    }

}
