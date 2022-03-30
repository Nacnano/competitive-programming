#include<bits/stdc++.h>
using namespace std;

map<long long,long long> mm;
int main(){

    long long n,x;
    scanf("%d%d",&n,&x);

    mm[0]=1;
    long long sum=0,ans=0;
    for(int i=0;i<(int)n;i++)
    {
        int a;
        scanf("%d",&a);
        sum+=a;
        if(mm.find(sum-x)!=mm.end()) ans+=mm[sum-x];
        mm[sum]++;
    }
    printf("%lld",ans);
}
