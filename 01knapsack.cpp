#include<bits/stdc++.h>
using namespace std;

int dp[10005];
int p,w;

int main(){

    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p,&w);

        for(int j=k;j>=0;j--)
        {
            if(j-w>=0) dp[j]=max(dp[j],dp[j-w]+p);
        }
    }

    int ans=0;
    for(int i=0;i<=k;i++) ans=max(ans,dp[i]);
    printf("%d",ans);
}
