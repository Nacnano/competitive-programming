#include<bits/stdc++.h>
using namespace std;

int n;
long long a[1<<20+5], x;
vector<long long> v1, v2;
map<long long, long long> mm1, mm2;

void gen1(int lv,int sum)
{
    if(lv==(int)n/2) return;
    gen1(lv+1,sum);
    sum+=a[lv];
    v1.push_back(sum);
    gen1(lv+1,sum);
}

void gen2(int lv,int sum)
{
    if(lv==n) return;
    gen2(lv+1,sum);
    sum+=a[lv];
    v2.push_back(sum);
    gen2(lv+1,sum);
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> a[i];
    gen1(0,0);
    gen2((int)n/2+n&1,0);

    mm1[0]=1, mm2[0]=1;
    for(auto tmp:v1) mm1[tmp]++;
    for(auto tmp:v2) mm2[tmp]++;

    long long ans=0;
    for(auto tmp:mm1)
    {
        if(mm2.find(x-tmp.first)!=mm2.end())
        {
            ans+=(long long)tmp.second*mm2[x-tmp.first];
        }
    }
    cout << ans;
}