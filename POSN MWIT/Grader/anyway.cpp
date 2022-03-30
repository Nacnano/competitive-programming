#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
bool have[1005][1005];

int main(){

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    while(k--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        have[x+1][y+1]=1;
    }
    dp[1][1]=1;
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=m+1;j++)
        {
            if(i==1 && j==1) continue;
            if(!have[i][j]) dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=1000000;
        }
    printf("%d",dp[n+1][m+1]);
}
