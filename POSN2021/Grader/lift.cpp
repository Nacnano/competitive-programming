#include<bits/stdc++.h>
using namespace std;

bitset<45010> hsh;

int main(){

    int n;
    scanf("%d",&n);
    hsh[0]=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
        for(int i=45010;i-x>=0;i--) if(hsh[i-x]) hsh[i]=1;
    }

    int mn=INT_MAX;
    int ans1,ans2;
    for(int i=0;i<=45010;i++)
    {
        if(hsh[i])
        {
            if(abs(sum-i-i) < mn)
            {
                mn=abs(sum-i-i);
                ans1=sum-i;
                ans2=i;
            }
        }
    }

    if(ans1 > ans2) swap(ans1,ans2);
    printf("%d %d",ans1,ans2);
}
