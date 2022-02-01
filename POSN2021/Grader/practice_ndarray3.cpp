#include<bits/stdc++.h>
using namespace std;

int a[205][205],b[205][205];

int main(){

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);

    for(int i=1;i<=m;i++) for(int j=1;j<=k;j++) scanf("%d",&b[i][j]);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            long long sum=0;
            for(int p=1;p<=m;p++) sum+=a[i][p]*b[p][j];
            printf("%lld ",sum);
        }
        printf("\n");
    }
}
