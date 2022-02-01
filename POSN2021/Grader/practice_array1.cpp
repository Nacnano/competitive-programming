#include<bits/stdc++.h>
using namespace std;

long long a[2010];

int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);

    while(m--)
    {
        for(int i=0;i<n;i++) printf("%lld ",a[i]);
        printf("\n");
    }
}
