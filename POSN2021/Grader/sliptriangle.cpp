#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010];
int main(){

    int n;
    scanf("%d",&n);

    scanf("%d",&dp[1][1]);
    for(int i=2;i<=n;i++)
    {
        dp[i-1][0]=-1e9;
        dp[i-1][i]=-1e9;
        for(int j=1;j<=i;j++)
        {
            int x;
            scanf("%d",&x);
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+x;
        }
    }

    int ans=-1e9;
    for(int i=1;i<=n;i++) ans=max(ans,dp[n][i]);
    printf("%d",ans);
}
