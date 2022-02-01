#include<bits/stdc++.h>
using namespace std;

int we[1335*1335];

int main(){

    int n,p,q;
    scanf("%d%d%d",&n,&p,&q);

    int all=n*n*p*p*q*q;
    for(int i=1;i<=all;i++)
    {
        int a,b,c,x,y,z,w;
        scanf("%d%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z,&w);
        we[1331*(121*a+11*b+c)+121*x+11*y+z]=w;
    }

    int k;
    scanf("%d",&k);

    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int prev=1331*(121*a+11*b+c);

    long long ans=0;
    k--;
    while(k--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int now=121*a+11*b+c;
        ans+=we[prev+now];
        prev=now*1331;
    }
    printf("%lld",ans);
}
