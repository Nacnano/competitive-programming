#include<bits/stdc++.h>
using namespace std;

vector<int> v[26];
void add(char c,int w)
{

    if(v[c-'A'].empty())
    {
        v[c-'A'].push_back(w);
        return;
    }

    int sum=v[c-'A'].back()+w;
    v[c-'A'].push_back(sum);
}

int main(){

    int n;
    scanf("%d",&n);
    while(n--)
    {
        char c;
        int w;
        scanf("%s %d",&c,&w);
        add(c,w);
    }

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(x>0) printf("%d\n",v['R'-'A'][x-1]);
        else if(x<0) printf("%d\n",v['L'-'A'][-x-1]);

        if(y>0) printf("%d\n",v['U'-'A'][y-1]);
        else if(y<0) printf("%d\n",v['D'-'A'][-y-1]);

        if(z>0) printf("%d\n",v['F'-'A'][z-1]);
        else if(z<0) printf("%d\n",v['B'-'A'][-z-1]);

        if(x==0 && y==0 && z==0) printf("0\n");
    }
}
