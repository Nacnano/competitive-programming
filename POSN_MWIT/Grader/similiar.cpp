#include<bits/stdc++.h>
using namespace std;

set<int> ss[105];

int main(){

    int n,st=INT_MAX;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ss[u].insert(v);
        ss[v].insert(u);
    }

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(ss[i].size()==1)
        {
            if(cnt==n-2)
            {
                printf("%d ",i);
                for(int j=1;j<=n;j++)
                {

                    if(ss[j].size()==1 && i!=j)
                    {
                        printf("%d",j);
                        break;
                    }
                }
                break;
            }

            cnt++;
            printf("%d ",i);
            ss[i].clear();
            for(int j=1;j<=n;j++) ss[j].erase(i);
        }
        if(i==n) i=1;
    }
}
