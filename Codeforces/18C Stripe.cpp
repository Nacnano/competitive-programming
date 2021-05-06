#include<bits/stdc++.h>
using namespace std;

long long qs[100005];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        qs[i]=qs[i-1]+x;
    }

    int cnt=0;
    for(int i=1;i<=n-1;i++)
    {
        if(qs[i]-qs[0]== qs[n]-qs[i]) cnt++;
    }
    printf("%d",cnt);
}
