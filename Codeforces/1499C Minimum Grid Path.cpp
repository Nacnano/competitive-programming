#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long long mn1=INT_MAX,mn2=INT_MAX,cnt1=0,cnt2=0;
        long long ans=1e18,sum=0;
        for(int i=1;i<=n;i++)
        {
            long long c;
            scanf("%lld",&c);
            sum+=c;
            if(i%2) mn1=min(mn1,c),cnt1++;
            else mn2=min(mn2,c),cnt2++;

            ans=min(ans,sum+mn1*(n-cnt1)+mn2*(n-cnt2));
        }
        printf("%lld\n",ans);
    }
}
