#include<bits/stdc++.h>
using namespace std;

int pos[200005];
bool chk[200005];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            pos[x]=i;
        }

        int r=1,l=n;
        for(int i=1;i<=n;i++)
        {
            r=max(r,pos[i]);
            l=min(l,pos[i]);
            if(r-l==i-1)
            {
                printf("1");
            }
            else printf("0");
        }
        printf("\n");
    }
}
