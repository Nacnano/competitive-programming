#include<bits/stdc++.h>
using namespace std;

int qs[505][505];

int main(){

    int q=2;
    while(q--)
    {
        int n,m;
        scanf("%d%d",&n,&m);

        int t;
        scanf("%d",&t);
        while(t--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            qs[x+1][y+1]=1;
        }

        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];

        int yes=1;
        for(int k=min(n,m);k>=0 && yes;k--)
            for(int i=0;i+k<=n && yes;i++)
                for(int j=0;j+k<=m && yes;j++)
                    if(qs[i+k][j+k]-qs[i][j+k]-qs[i+k][j]+qs[i][j] - (qs[i+k-1][j+k-1]-qs[i+k-1][j+1]-qs[i+1][j+k-1]+qs[i+1][j+1]) == 0)
                    {
                        printf("%d\n",k);
                        yes=0;
                    }

        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) qs[i][j]=0;
    }

}
