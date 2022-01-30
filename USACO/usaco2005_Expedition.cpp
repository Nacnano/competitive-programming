#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> a,const pair<int,int> b)
{
    return a.first>b.first;
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);

        pair<int,int> pos[10005];
        for(int i=0;i<n;i++) scanf("%d%d",&pos[i].first,&pos[i].second);

        int l,p;
        scanf("%d%d",&l,&p);

        sort(pos,pos+n,cmp);


        priority_queue<int> pq;
        pq.push(p);

        int pos_now=0,ans=0,far=l;
        while(!pq.empty() && far>0)
        {
            far-=pq.top();
            ans++;
            pq.pop();

            while(pos_now<n && pos[pos_now].first >= far)
            {
                pq.push(pos[pos_now].second);
                pos_now++;
            }
        }

        if(far>0) printf("-1\n");
        else printf("%d\n",ans-1);
    }
}
