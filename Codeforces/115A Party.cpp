#include<bits/stdc++.h>
using namespace std;

vector<int> g[2010];
vector<int > st;

int ans=0;
void dfs(int u,int lv)
{
    if(g[u].size()==0) ans=max(ans,lv);
    for(auto v:g[u])
    {
        dfs(v,lv+1);
    }
}
int main(){

    int n;
    scanf("%d",&n);

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==-1)
        {
            st.push_back(i);
            continue;
        }
        g[x].push_back(i);
    }

    for(auto x:st)
    {
        dfs(x,1);
    }
    printf("%d",ans);


}
