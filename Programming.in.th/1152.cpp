#include<bits/stdc++.h>
using namespace std;

priority_queue<int> pq[2010];
int a[1005][1005];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            pq[i+j].push(a[i][j]);
        }
    }

    int ans=0;
    for(int t=2*n-1;t>=2;t--)
    {
        int v=-1,del;
        for(int j=t+1;j<=2*n;j++)
        {
            if(pq[j].empty()) continue;
            if(pq[j].top() > v)
            {
                v=pq[j].top();
                del=j;
            }
        }
        pq[del].pop();
        ans+=v;
    }
    printf("%d",ans);
}
