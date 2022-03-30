#include<bits/stdc++.h>
using namespace std;

int a[100010],b[100010],c[100010];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);

    sort(a,a+n);
    sort(b,b+n);

    int ans=-1;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,min(a[i],b[n-i-1]));
    }
    printf("%d",ans);
}
