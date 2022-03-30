#include<bits/stdc++.h>
using namespace std;

int dp[505][505];


int main(){

    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<=n;i++) dp[i][0]=INT_MAX;
    for(int i=0;i<=n;i++) dp[i][m+1]=INT_MAX;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            scanf("%d",&x);
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]))+x;
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=m;i++) ans=min(ans,dp[n][i]);
        printf("%d",ans);
}
