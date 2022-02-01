#include<bits/stdc++.h>
using namespace std;

int ans;
void rec(int p,int step)
{
    if(p==1)
    {
        ans=min(ans,step);
        return;
    }

    if(p>=2) rec(p/2,step+1+p%2);
    if(p>=3) rec(p/3,step+1+p%3);
}

int main(){

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x;
        scanf("%d",&x);

        ans=INT_MAX;
        rec(x,0);
        printf("%d\n",ans);
    }
}

