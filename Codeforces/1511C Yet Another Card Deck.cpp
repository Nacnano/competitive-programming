#include<bits/stdc++.h>
using namespace std;

int pos[55];

int main(){

    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(!pos[x]) pos[x]=i;
    }

    while(q--)
    {
        int t;
        scanf("%d",&t);
        printf("%d ",pos[t]);
        for(int i=1;i<=50;i++)
        {
            if(pos[i]<pos[t])
                pos[i]++;

        }
        pos[t]=1;
    }
}
