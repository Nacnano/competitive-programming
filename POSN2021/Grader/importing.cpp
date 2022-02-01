#include<bits/stdc++.h>
using namespace std;

int a[200010];
int main(){

    int n,k,s;
    scanf("%d%d%d",&n,&k,&s);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    int loss=0;
    priority_queue<int> pq;
    for(int i=1;i<=n;i++)
    {
        pq.push(-a[i]);

        while(pq.size()>k)
        {
            loss-=pq.top()/10;
            pq.pop();
        }
        if(loss>s)
        {
            printf("%d",i-1);
            break;
        }
    }
}
