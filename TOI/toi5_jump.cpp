#include<bits/stdc++.h>
using namespace std;

int a[30010];

int main(){

    int n,k;
    scanf("%d%d",&n,&k);

    int ans=0;
    scanf("%d",&a[1]);
    int j=1;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
        while(a[i]-a[j]>k) j++;
        ans=max(ans,i-j);
    }

    while(a[n]-a[j]>k) j++;
    ans=max(ans,n-j);
    printf("%d",ans);
}
