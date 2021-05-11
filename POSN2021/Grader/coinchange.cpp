#include<bits/stdc++.h>
using namespace std;

int dp[1000005];
int a[15];

int main(){

    int n,c;
    scanf("%d%d",&n,&c);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=c;i++)
    {
        dp[i]=1e9;
        for(int j=0;j<n;j++)
        {
            if(i-a[j]<0) continue;
            if(dp[i-a[j]]!=1e9) dp[i]=min(dp[i-a[j]]+1,dp[i]);
        }
    }

    if(dp[c]!=1e9) printf("%d",dp[c]);
    else printf("0");
}
