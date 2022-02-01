#include<bits/stdc++.h>
using namespace std;

char s[1010][1010];
queue <pair<int,pair<int,int> > > q;
int dis[1010][1010];

int d[5][3] = {{1,0},{-1,0},{0,-1},{0,1}};

int main(){

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) dis[i][j]=INT_MAX;

    for(int i=0;i<n;i++)
    {
        scanf("%s",&s[i]);
        for(int j=0;s[i][j];j++)
            if(s[i][j]=='L')
            {
                q.push({0,{j,i}});
                dis[i][j]=0;
            }
    }

    while(!q.empty())
    {
        int w=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        q.pop();

        if(w==k) continue;

        for(int i=0;i<4;i++)
        {
            int nx=x+d[i][0];
            int ny=y+d[i][1];

            if(nx>=m || ny>=n || nx<0 || ny<0 || s[ny][nx]=='X') continue;
            if(dis[ny][nx] > dis[y][x]+1)
            {
                dis[ny][nx]=dis[y][x]+1;
                s[ny][nx]='L';
                q.push({dis[ny][nx],{nx,ny}});
            }

        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%c",s[i][j]);
        }
        printf("\n");
    }
}
