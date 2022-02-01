#include<bits/stdc++.h>
using namespace std;

set<int> ss;
map<int,int> l,r;
int main(){

    int n,m;
    scanf("%d%d",&n,&m);

    r[1]=n;
    l[n]=1;

    r[n]=n;
    l[1]=1;
    ss.insert(1);

    while(m--)
    {
        int q,x;
        scanf("%d%d",&q,&x);

        if(q==0)
        {
            auto it=ss.lower_bound(x);
            int st=*it;
            int ed=r[st];

            ss.insert(x+1);
            r[st]=x;
            l[st]=st;

            r[x+1]=ed;
            l[x+1]=x+1;

            l[ed]=x+1;
            r[ed]=ed;

            l[x]=st;
            r[x]=x;
            printf("st %d ed %d\n",st,ed);
        }
        else if(q==1)
        {
            int st=l[x];
            int ed=r[x+1];

            l[st]=st;
            r[st]=ed;

            l[ed]=st;
            r[ed]=ed;

            l[x]=0;
            r[x]=0;

            l[x+1]=0;
            r[x+1]=0;
            ss.erase(x+1);
        }
        for(int i=1;i<=n;i++) printf("MM %d : %d %d\n",i,l[i],r[i]);
        printf("\n");
    }



    int now=1;
    int ans=0;
    while(now!=n)
    {
        int next=r[now]+1;
        printf("%d %d\n",now,next);
        ans=max(ans,next-now);
        now=next;

    }
    printf("%d",ans);
}

