#include<bits/stdc++.h>
using namespace std;

int qs[1010][1010];

int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    while(n--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        qs[y+1][x+1]++;
    }

    for(int i=1;i<=1001;i++) for(int j=1;j<=1001;j++) qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];

    while(m--)
    {
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        int x1=max(0,x-k);
        int y1=max(0,y-k);

        int x2=min(1001,x+1+k);
        int y2=min(1001,y+1+k);
        printf("%d\n",qs[y2][x2]-qs[y2][x1]-qs[y1][x2]+qs[y1][x1]);
    }
}
