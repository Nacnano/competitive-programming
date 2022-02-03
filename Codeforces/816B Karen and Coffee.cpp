#include<bits/stdc++.h>
using namespace std;

int cnt[200005];
int qs[200005];

int main(){

    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        cnt[a]++;
        cnt[b+1]--;
    }

    int now=0;
    for(int i=1;i<=200000;i++)
    {
        qs[i]=qs[i-1];
        now+=cnt[i];
        if(now>=k) qs[i]++;
    }

    while(q--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",qs[b]-qs[a-1]);
    }
}
