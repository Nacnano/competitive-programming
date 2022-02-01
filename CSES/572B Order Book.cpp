#include<bits/stdc++.h>
using namespace std;

int mm[2][100005];
stack<int> stk;

int main(){

    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        char d;
        int p,q;
        cin >> d;
        scanf("%d%d",&p,&q);
        mm[d=='S'][p] += q;
    }
    for(int i=0,cnt=0;i<=100000 && cnt<k;i++) if(mm[1][i]) stk.push(i),cnt++;
    while(!stk.empty()) printf("S %d %d\n",stk.top(),mm[1][stk.top()]),stk.pop();

    for(int i=100000,cnt=0;i>=0 && cnt<k;i--) if(mm[0][i]) printf("B %d %d\n",i,mm[0][i]),cnt++;
}
