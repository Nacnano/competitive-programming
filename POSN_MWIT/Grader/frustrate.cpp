#include<bits/stdc++.h>
using namespace std;

int qs[100010];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        qs[i]=qs[i-1]+a;
    }

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",qs[b]-qs[a-1]);
    }
}

