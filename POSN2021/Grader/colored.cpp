#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b;
    scanf("%d%d",&a,&b);
    int k=a+b;
    k--;
    long long ans=1;
    while(k--)
    {
        ans*=2;
        ans= ans %1000000007;
    }
    printf("%lld",ans);
}
