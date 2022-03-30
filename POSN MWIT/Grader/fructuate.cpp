#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    int last=INT_MAX;
    int ans=0;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        if(x<last) last=x;
        else ans=max(ans,x-last);
    }
    printf("%d",ans);
}
