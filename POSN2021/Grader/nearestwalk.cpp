#include<bits/stdc++.h>
using namespace std;

char s[1005][1005];
int dis[1005][1005];
bool vis[1005][1005];

int d[5][3]={{1,0},{-1,0},{0,1},{0,-1} };

int main(){

    int q;
    scanf("%d",&q);

    int stx,sty;
    while(q--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for(int j=0;j<m;j++) if(s[i][j]=='A') stx=j,sty=i;
        }

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) dis[i][j]=INT_MAX;

        queue<pair<int,int> > q;
        q.push({stx,sty});
        dis[sty][stx]=0;

        int ans=INT_MAX;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+d[i][0];
                int ny=y+d[i][1];

                if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
                if(s[ny][nx]=='#') continue;
                else if(dis[ny][nx] > dis[y][x]+1 && s[ny][nx]!='B')
                {
                    dis[ny][nx]=dis[y][x]+1;
                    q.push({nx,ny});
                }

                if(s[ny][nx]=='B') ans=min(ans,dis[y][x]+1);
            }
        }

        if(ans==INT_MAX) printf("-1\n");
        else printf("%d\n",ans);
    }
}
