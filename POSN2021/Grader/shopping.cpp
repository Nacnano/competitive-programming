#include<bits/stdc++.h>
using namespace std;

const int mxn=1000000;
vector<int> v[mxn];
vector<int> shop;
int main(){

    int n;
    scanf("%d",&n);

    int s,t,it=0;
    scanf("%d%d",&s,&t);
    v[0].push_back(t);
    shop.push_back(s);
    n--;
    while(n--)
    {
        scanf("%d%d",&s,&t);

        if(s!=shop.back())
        {
            it++;
            shop.push_back(s);
        }
        v[it].push_back(t);
    }

    for(int i=shop.size()-1;i>=0;i--)
    {
        printf("%d ",shop[i]);
        for(auto x:v[i]) printf("%d ",x);
        printf("\n");
    }
}
