#include<bits/stdc++.h>
using namespace std;

vector<int> v[5];
int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            v[2*(i%2)+j%2].push_back(x);
        }
    }
    for(int i=0;i<4;i++) sort(v[i].begin(),v[i].end());

    long long ans=0;
    for(int i=0;i<(int)v[0].size();i++)
    {
        int sum=1;
        for(int j=0;j<4;j++)
            sum*=v[j][i];
        ans+=sum;
    }
    printf("%lld",ans);
}
