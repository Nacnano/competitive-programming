#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);

    long long ans=0;
    for(int i=0;i<n/2;i++)  ans+=a[n-i-1]-a[i];
    printf("%lld",ans);
}
