#include<bits/stdc++.h>
using namespace std;

int a[305];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    int q,len=n;
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        for(int i=r+1;i<=len;i++)
        {
            a[l+i-r-1]=a[i];
            a[i]=0;
        }
        len-=r-l+1;

    }
    for(int i=1;i<=len;i++) printf("%d ",a[i]);
}
