#include<bits/stdc++.h>
using namespace std;

int di[4][2]={{1,0},{-1,0},{0,1},{0,-1} };
char s[25][25];
char f[105];
int n,m;
bool used[25][25];
vector<pair<int,int> > st[255];
pair<int,int> ans[150];
bool con=0;

bool dfs(int x,int y,int lv)
{
    if(!f[lv])
    {
        for(int i=0;i<lv;i++)
        {
            printf("%d %d\n",ans[i].second+1,ans[i].first+1);
        }
        con=1;
        return 1;
    }

    for(int i=0;i<4;i++)
    {
        int nx=x+di[i][0];
        int ny=y+di[i][1];

        if(nx<0 || ny<0 || nx>=m || ny>=n) continue;

        if(s[ny][nx]==f[lv] && used[ny][nx]==0)
        {

            used[ny][nx]=1;
            ans[lv]={nx,ny};
            dfs(nx,ny,lv+1);
            used[ny][nx]=0;
        }

    }
    if(con==1) return 1;
    return 0;
}


int main(){


    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",&s[i]);
        for(int j=0;j<m;j++)
        {
            st[s[i][j]].push_back({j,i});
        }
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {

        scanf("%s",f);

        bool yes=0;
        for(auto v :st[f[0]])
        {
            int x=v.first;
            int y=v.second;

            used[y][x]=1;
            ans[0]={x,y};
            if(dfs(x,y,1))
            {
                yes=1;
                break;
            }
            used[y][x]=0;

            for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) used[i][j]=0;
        }
        if(!yes) printf("No Matching Word\n");
    }
}
