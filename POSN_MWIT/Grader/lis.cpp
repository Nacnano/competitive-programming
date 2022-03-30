#include<bits/stdc++.h>
using namespace std;

vector<int> lis;

int main(){

    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        auto it=lower_bound(lis.begin(),lis.end(),x);
        if(it==lis.end()) lis.push_back(x);
        else *it=x;

    }
    printf("%d",lis.size());
}
