#include<bits/stdc++.h>
using namespace std;

int in[100010],out[100010];
int val[100010];

int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        in[a]++;
        out[b+1]++;
    }

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=in[i];
        cnt-=out[i];
        val[i]=cnt;
    }

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",val[x]);
    }
}
