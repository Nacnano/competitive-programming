#include<bits/stdc++.h>
using namespace std;

int st[600000];

void update(int l,int r,int idx,int pos,int val)
{
    if(l==r)
    {
        st[idx]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) update(l,mid,2*idx,pos,val);
    else update(mid+1,r,2*idx+1,pos,val);

    st[idx]=max(st[2*idx],st[2*idx+1]);
}

int query(int l,int r,int idx,int left,int right)
{
    if(r<left || l>right) return INT_MIN;
    if(left <=l && r <=right) return st[idx];
    int mid=(l+r)/2;
    return max( query(l,mid,2*idx,left,right), query(mid+1,r,2*idx+1,left,right) );
}

int main(){

    int n,q;
    cin >> n >> q;
    while(q--)
    {
        char t;
        int a,b;
        cin >> t >> a >> b;
        if(t=='U') update(1,n,1,a,b);
        else printf("%d\n",query(1,n,1,a,b));
    }
}
