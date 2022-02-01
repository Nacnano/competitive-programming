#include<bits/stdc++.h>
using namespace std;

int re[1010][1010];

int main(){

    int n,k;
    scanf("%d%d",&n,&k);

    if(2*k>n-1)
    {
        printf("-1");
        return 0;
    }

    printf("%d\n",n*k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1,cnt=0;j<=n && cnt<k;j++)
        {
            if(i==j || re[i][j]) continue;
            cnt++;
            re[i][j]=1;
            re[j][i]=1;
            printf("%d %d\n",i,j);
        }
    }
}
