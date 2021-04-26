#include<bits/stdc++.h>
using namespace std;

int tmp[100005];
pair<int,int> c[100005];
int a[100005];
long long qs[100005];
long long sum=0;

void mer(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    mer(l,mid);
    mer(mid+1,r);

    qs[l-1]=0;
    for(int i=l;i<=r;i++) qs[i]=qs[i-1]+a[i];
    int it1=l,it2=mid+1;
    for(int i=l;i<=r;i++)
    {
        if(it1>mid) tmp[i]=a[it2++];
        else if(it2>r) tmp[i]=a[it1++];
        else if(a[it1]<=a[it2]) tmp[i]=a[it1++];
        else if(a[it1]>a[it2])
        {
            tmp[i]=a[it2];
            sum+=(mid+1-it1)*a[it2++]+qs[mid]-qs[it1-1];
        }
    }

    for(int i=l;i<=r;i++) a[i]=tmp[i];

}

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,b;
        scanf("%d%d",&x,&b);
        a[b-1]=x;
    }
    mer(0,n-1);
    printf("%lld",sum);
}
