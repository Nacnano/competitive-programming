#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    n--;

    int x;
    scanf("%d",&x);
    int mn=x,ans=0;
    while(n--)
    {
        scanf("%d",&x);
        if(mn<x)
        {
            ans+=(x-mn);
            mn=x;
        }
        else mn=x;
    }
    printf("%d",ans);
}

