#include<bits/stdc++.h>
using namespace std;

deque<int> dq;

int main(){

    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        dq.push_back(x);
    }

    int q;
    scanf("%d",&q);
    while(q--)
    {
        char c;
        int x;
        scanf("%s %d",&c,&x);
        if(c=='B') dq.push_back(x);
        else if(c=='F') dq.push_front(x);
    }

    while(!dq.empty())
    {
        printf("%d ",dq.front());
        dq.pop_front();
    }
}
