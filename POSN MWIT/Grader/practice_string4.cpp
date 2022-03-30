#include<bits/stdc++.h>
using namespace std;

string s[2005];
int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin >> s[i];

    while(n--)
    {
        int x;
        scanf("%d",&x);
        cout << s[x];
    }
}
