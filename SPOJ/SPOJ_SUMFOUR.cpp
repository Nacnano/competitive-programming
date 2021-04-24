#include<bits/stdc++.h>
using namespace std;

int a[2510],b[2510],c[2510],d[2510];
vector<int> v1,v2;

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) v1.push_back(a[i]+b[j]);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) v2.push_back(-c[i]-d[j]);

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    long long ans=0;
    int sz1=v1.size(),sz2=v1.size();
    int it1=0,it2=0;
    while(it1<sz1 && it2<sz2)
    {
        if(v1[it1] > v2[it2])
        {
            it2++;
            continue;
        }
        else if(v1[it1] < v2[it2])
        {
            it1++;
            continue;
        }

        int cnt1=1,cnt2=1;
        while(v1[it1+1] == v1[it1] && it1+1<sz1)
        {
            it1++;
            cnt1++;
        }
        while(v2[it2+1] == v2[it2] && it2+1<sz2)
        {
            it2++;
            cnt2++;
        }
        ans+=cnt1*cnt2;
        it1++;
        it2++;
    }
    printf("%lld",ans);
}
