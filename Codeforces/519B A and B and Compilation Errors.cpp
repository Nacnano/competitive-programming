#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,x;
    scanf("%d",&n);
    long long sum0=0,sum1=0,sum2=0;
    for(int i=0;i<n;i++) scanf("%d",&x),sum0+=x;
    for(int i=0;i<n-1;i++) scanf("%d",&x),sum1+=x;
    for(int i=0;i<n-2;i++) scanf("%d",&x),sum2+=x;

    printf("%lld\n%lld",sum0-sum1,sum1-sum2);
}
