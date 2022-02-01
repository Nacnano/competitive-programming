#include<bits/stdc++.h>
using namespace std;

int d[150005];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);

    int a,k;
    scanf("%d%d",&a,&k);
    while(k--) a=d[a];

    printf("%d",d[a]);
}
