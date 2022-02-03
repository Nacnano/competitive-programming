#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    while(t--)
    {
        priority_queue<int> pq;
        int n;
        scanf("%d",&n);
        while(n--) pq.push(n+1);
        printf("2\n");

        while(pq.size()>=2)
        {
            int a=pq.top();
            printf("%d ",a);
            pq.pop();
            int b=pq.top();
            printf("%d\n",b);
            pq.pop();
            pq.push((a+b+1)/2);
        }

    }
}
