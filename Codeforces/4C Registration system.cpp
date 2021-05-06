#include<bits/stdc++.h>
using namespace std;

map<string,int> mm;

int main(){

    int n;
    scanf("%d",&n);
    while(n--)
    {
        string s;
        cin >> s;
        if(!mm[s]) printf("OK\n");
        else cout << s << mm[s] << "\n";
        mm[s]++;
    }
}


