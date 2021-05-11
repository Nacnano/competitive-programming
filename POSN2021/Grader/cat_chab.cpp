#include<bits/stdc++.h>
using namespace std;

deque<int> dq;

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char s[10];
        scanf("%s",s);
        if(s[0]=='B') dq.push_front(i);
        else dq.push_back(i);
    }

    while(!dq.empty())
    {
        printf("%d ",dq.front());
        dq.pop_front();
    }

}
