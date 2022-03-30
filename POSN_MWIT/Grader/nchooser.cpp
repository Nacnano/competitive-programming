#include<bits/stdc++.h>
using namespace std;

int dp[10000];

int main(){

    int n,r,k;
    scanf("%d%d%d",&n,&r,&k);

    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=min(i,r);j>=0;j--)
        {
            dp[j]=dp[j]+dp[j-1];
            dp[j]%=k;
        }
    printf("%d",dp[r]);
}
