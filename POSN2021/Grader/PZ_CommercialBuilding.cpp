#include<bits/stdc++.h>
using namespace std;

int a[100010];

int main(){

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        long long m;
        scanf("%d%lld",&n,&m);
        long long sum=0,ans=0;
        int last=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            while(sum>m)
            {
                sum-=a[last];

                last++;
            }
            ans+=i-last+1;
        }
        printf("%lld\n",ans);
    }
}
