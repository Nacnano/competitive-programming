#include<bits/stdc++.h>
using namespace std;

const int pr=1000000007;
long long dp[1000010];
int a[100010];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        vector<int> div;

        for(int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j==0 && j*j!=a[i]) div.push_back(j),div.push_back(a[i]/j);
            if(j*j==a[i]) div.push_back(j);
        }
        sort(div.begin(),div.end());
        for(int it=(int)div.size()-1;it>=0;it--)
        {
            int j=div[it];
            dp[j]=dp[j-1]+dp[j];
            dp[j]=dp[j]%pr;
        }
    }
    long long sum=0;
    for(int i=1;i<=n;i++) sum+=dp[i],sum%=pr;
    printf("%lld",sum);
}
