#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;
    scanf("%d",&t);
    for(int q=1;q<=t;q++)
    {
        vector<int> col (1010,-1);
        vector<int> g[1010];
        int n,m;
        scanf("%d%d",&n,&m);
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool bi=1;
        for(int i=1;i<=n;i++)
        {
            if(col[i]==-1)
            {
                col[i]=0;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    for(auto v:g[u])
                    {
                        if(col[v]==-1)
                        {
                            col[v]=1^col[u];
                            q.push(v);
                        }
                        else bi &= col[u]!=col[v];
                    }

                }
            }
            if(bi==0)
            {
                printf("Scenario #%d:\n",q);
                printf("Suspicious bugs found!\n");
                break;
            }
        }
        if(bi)
        {
            printf("Scenario #%d:\n",q);
            printf("No suspicious bugs found!\n");
        }
    }
}
