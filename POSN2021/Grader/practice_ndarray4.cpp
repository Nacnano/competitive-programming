#include<bits/stdc++.h>
using namespace std;

long long a[205][205],b[205][205],tmp[205][205];
long long pr=1000000007;

int main(){

    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]),b[i][j]=a[i][j];

    m--;
    while(m--)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                long long sum=0;
                for(int k=1;k<=n;k++) sum+=(a[i][k]*b[k][j])%pr,sum%=pr;
                tmp[i][j]=sum;
            }
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=tmp[i][j];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) printf("%lld ",a[i][j]);
        printf("\n");
    }
}
