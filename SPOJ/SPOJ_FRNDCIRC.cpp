#include<bits/stdc++.h>
using namespace std;

map<string,string> mm;
map<string,int> cir;
string _find(string s)
{
    if(mm[s]==s) return s;
    else return mm[s]=_find(mm[s]);
}

void _union(string a,string b)
{
    string pa=_find(a);
    string pb=_find(b);
    if(pa!=pb)
    {
        mm[pa]=pb;
        cir[pb]+=cir[pa];
    }
    printf("%d\n",cir[pb]);
}

int main(){

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        while(n--)
        {
            string a,b;
            cin >> a >> b;
            if(a==b) continue;
            if(!cir[a])
            {
                mm[a]=a;
                cir[a]=1;
            }
            if(!cir[b])
            {
                mm[b]=b;
                cir[b]=1;
            }
            _union(a,b);
        }
        mm.clear();
        cir.clear();
    }
}
