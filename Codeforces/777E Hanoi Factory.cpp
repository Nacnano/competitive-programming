#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,long long> > > v;
operator bool cmp(pair<int,pair<int,long long> > a,pair<int,pair<int,long long> > b)
{
    if(a.first < b.first) return 1;
    else if(a.first == b.first) return a.second.first < b.second.first;
    return a.second.second > b.second.second;
}

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        long long h;
        scanf("%d%d%lld",&a,&b,&h);
        v.push_back({a,{b,h}});
    }

    sort(v.begin(),v.end(),cmp);

    for(auto x: v)
    {
        printf("%d %d %d\n",x.first,x.second.first,x.second.second);
    }

    stack<pair<int,pair<int,long long> >> stk;
    int ans=0, sum=0;
    for(int i=0;i<n;i++)
    {
        if(stk.empty() || stk.top().first < v[i].second.first)
        {
            sum+=v[i].second.second;
            stk.push(v[i]);
        }
        else
        {
            while(!stk.empty() && stk.top().first >= v[i].second.first)
            {
                sum-=stk.top().second.second;
                stk.pop();
            }
            stk.push(v[i]);
            sum+=v[i].second.second;
        }
        ans=max(ans,sum);
    }
    printf("%d",ans);

}
