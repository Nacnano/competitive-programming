#include<bits/stdc++.h>
using namespace std;

int tmp[10];
bool used[10];
bool no[10];
int n,m;

void solve(int lv)
{
    if(lv==n)
    {
        for(int i=1;i<n;i++) printf("%d ",tmp[i]);
        for(int i=1;i<=n;i++) if(used[i]==0) printf("%d",i);
        printf("\n");
    }

    if(lv==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(no[i]==0)
            {
                tmp[lv]=i;
                used[i]=1;
                solve(lv+1);
                used[i]=0;
            }
        }
    }
    else
    for(int i=1;i<=n;i++)
    {

        if(used[i]==0)
        {
            used[i]=1;
            tmp[lv]=i;
            solve(lv+1);
            used[i]=0;
        }
    }
}

int main(){

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        no[x]=1;
    }

    solve(1);

}
