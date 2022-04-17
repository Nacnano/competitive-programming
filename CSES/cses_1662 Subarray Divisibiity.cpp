#include<bits/stdc++.h>
using namespace std;
map<long long, long long> mm; 

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    long long n, x, sum=0, ans=0;
    cin >> n;
    x=n;
    mm[0]=1;
    while(n--)
    {
        long long a;
        cin >> a;
        a%=x;
        sum+=a;
        sum = ((sum%x)+x)%x;
        ans+=mm[((sum-x)%x+x)%x];
        mm[sum]++;
    }
    cout << ans;
}