#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    scanf("%d",&n);

    long long a,b;
    scanf("%lld%lld",&a,&b);

    int ans=1;
    long long mna=a,mnb=b,mn=b;
    for(int i=2;i<=n;i++)
    {
        scanf("%lld%lld",&a,&b);
        if(b*mna < a*mnb)
        {
            ans=i;
            mna=a;
            mnb=b;
        }
        if(b*mna == a*mnb)
        {
            if(b<mn)
            {
                ans=i;
                mn=b;
            }
        }
    }
    printf("%d",ans);
}

