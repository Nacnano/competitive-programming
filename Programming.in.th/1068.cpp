#include<bits/stdc++.h>
using namespace std;

int a[105][105],b[105][105];

int main(){

    int n,k;
    scanf("%d%d",&n,&k);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
        for(int j=1;j<=n+1;j++) scanf("%d",&b[i][j]);
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[n+1][i]);

    vector<int> block;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int val=3*a[i][j]+5*b[i][j]-5*b[i][j+1]-3*a[i+1][j];
            block.push_back(val);
        }
    }

    sort(block.begin(),block.end());

    long long ans=0;
    for(int i=0;i<k;i++) ans+=block[i];
    printf("%lld",ans);
}
