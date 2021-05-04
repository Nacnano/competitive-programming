#include<bits/stdc++.h>
using namespace std;

long long dp[1005];

int main(){

    int n;
    scanf("%d",&n);
    dp[0]=1,dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
            dp[i]%=10001;
        }
    }
    printf("%lld",dp[n]);
}
