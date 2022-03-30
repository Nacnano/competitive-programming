#include<bits/stdc++.h>
using namespace std;

int n,lv;
int a[1000010];

bool dfs(int x,int fl)
{
    if(fl==lv) return 1;

    if(a[2*x] < a[x] && a[x] < a[2*x+1])
    {
        return dfs(2*x,fl+1)&&dfs(2*x+1,fl+1);
    }

    return 0;
}

int main(){

    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(lv=1;lv<=25;lv++)
    {
        if(1<<lv == n+1) break;
        else if(1<<lv > n+1)
        {
            printf("NO");
            return 0;
        }
    }

    if(dfs(1,1)) printf("CHING");
    else printf("NO");

}
