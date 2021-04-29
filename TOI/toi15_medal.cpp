#include<bits/stdc++.h>
using namespace std;

int a[500010],b[500010],c[500010];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++) c[i]=a[i]+b[n-i-1];

    sort(c,c+n);
    printf("%d",abs(c[n-1]-c[0]));
}
