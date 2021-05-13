#include<bits/stdc++.h>
using namespace std;

int qs[505][505];

int main(){

    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            scanf("%d",&x);
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+x;
        }
    }

    for(int i=r+1;i+r<=n;i++)
    {
        for(int j=r+1;j+r<=m;j++) printf("%d ",qs[i+r][j+r]-qs[i+r][j-r-1]-qs[i-r-1][j+r]+qs[i-r-1][j-r-1]);
        printf("\n");
    }
}
