#include<bits/stdc++.h>
using namespace std;

vector<int> g[6];
int vis[6];
int path[6];
vector<int> ans;

void dfs(int u,int lv)
{

    bool chk=0;
    for(int i=0;i<lv;i++) if(u==path[i]) chk=1;
    if(chk) return;

    for(auto v:g[u])
    {
        if(v==2)
        {
            int sum=0;
            for(int i=0;i<=lv;i++)
            {

                sum+=path[i];
                sum*=10;
            }
            ans.push_back(sum+2);
            continue;
        }

        bool chk=0;
        for(int i=0;i<lv;i++) if(v==path[i]) chk=1;

        if(chk)continue;

        path[lv+1]=v;
        dfs(v,lv+1);
    }
}

int main(){

    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    path[0]=2;
    dfs(2,0);
    sort(ans.begin(),ans.end());
    for(auto x: ans)printf("%d\n",x);
}
