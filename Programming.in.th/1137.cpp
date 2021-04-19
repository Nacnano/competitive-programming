#include<bits/stdc++.h>
using namespace std;

const int mxn=1000000;
long long a[mxn+5];
long long dp[mxn+5];

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    dp[0]=a[0];
    dp[1]=a[1];
    dp[2]=a[0]+a[1]+a[2];
    for(int i=3;i<n;i++) dp[i]=min(a[0]+a[i]+a[0]+a[i-1],a[0]+a[1]+a[i]+a[1]) + dp[i-2];
    printf("%lld",dp[n-1]);
}
