#include<bits/stdc++.h>
using namespace std;

double dist(double x1,double y1,double x2, double y2)
{
    return (double)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool cmp(const pair<double,double> a, const pair<double,double> b)
{
    return a.first<b.first;
}

int main(){

    int w;
    scanf("%d",&w);
    while(w--)
    {
        pair<double,double> t[100005];
        int n,r,d;
        scanf("%d%d%d",&n,&r,&d);
        for(int i=0;i<n;i++) scanf("%lf%lf",&t[i].first,&t[i].second);

        sort(t,t+n,cmp);

        set<pair<double,double> > ss;
        double mn=INT_MAX;
        for(int i=0,j=0;i<n;i++)
        {
            while(j<i && t[i].first-t[j].first>=mn)
            {
                ss.erase({t[j].second,t[j].first});
                j++;
            }

            for(auto it=ss.lower_bound({t[i].second-mn,t[i].first-mn});it!=ss.end();it++)
            {
                if((*it).first-t[i].second > mn) break;
                mn=min(mn,dist((*it).second,(*it).first,t[i].first,t[i].second));
            }

            ss.insert({t[i].second,t[i].first});
        }
        if(mn-2*r>=d) printf("Y\n");
        else printf("N\n");
    }
}
