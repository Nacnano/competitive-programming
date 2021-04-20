#include<bits/stdc++.h>
using namespace std;

const int mx=1000000;
int cnt[mx+10];

int main(){

    int q;
    scanf("%d",&q);

    for(int i=1;i<=mx;i++)
        for(int j=i;j<=mx;j+=i)
            cnt[j]++;

    while(q--)
    {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        int ans=0;
        for(int i=a;i<=b;i++) if(cnt[i]==k) ans++;
        printf("%d\n",ans);
    }

}
