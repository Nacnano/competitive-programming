#include<bits/stdc++.h>
using namespace  std;

const int mxn=10000;
set<int> g[mxn+5];
int deg[mxn+5];


int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++;
        deg[v]++;
    }

    int odd=0,oddvertex;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]%2)
        {
            odd++;
            oddvertex=i;
        }
    }

    if(odd%2==0)
    {
        if(odd==2) printf("Eulerian Path: ");
        else printf("Eulerian Circuit: ");
        stack<int> cpath;
        stack<int> epath;

        cpath.push(oddvertex);
        while(!cpath.empty())
        {
            int u = cpath.top();
            if(g[u].empty())
            {
                epath.push(u);
                cpath.pop();
            }
            else
            {
                int v=*g[u].begin();
                cpath.push(v);
                g[u].erase(v);
                g[v].erase(u);
            }
        }

        while(!epath.empty())
        {
            printf("%d ",epath.top());
            epath.pop();
        }
    }
    else
    {
        //No Eulerian Path nor Circuit
        printf("-1");
    }
}
