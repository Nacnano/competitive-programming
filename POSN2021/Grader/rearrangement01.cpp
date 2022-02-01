#include<bits/stdc++.h>
using namespace std;
long long a[805],b[805];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++) scanf("%lld",&b[i]);

    sort(a,a+n);
    sort(b,b+n);

    long long sum=0;
    for(int i=0;i<n;i++) sum+=a[i]*b[i];
    printf("%lld",sum);
}
