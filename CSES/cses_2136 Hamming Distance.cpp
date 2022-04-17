#include<bits/stdc++.h>
using namespace std;

int val[200010];

int main(){

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        string str;
        cin >> str;
        for(int j=0;str[j];j++) val[i]+=(str[j]-'0')*(1<<j);
    }

    int ans=40;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) ans=min(ans,__builtin_popcount(val[i]^val[j]));
    cout << ans;

}