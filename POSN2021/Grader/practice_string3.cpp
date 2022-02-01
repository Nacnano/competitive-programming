#include<bits/stdc++.h>
using namespace std;

char s[2010];

int main(){

    cin >> s;
    int len=strlen(s);

    int q;
    cin >> q;
    while(q--)
    {
        char c;
        cin >> c;

        if(c=='I')
        {
            char add;
            int pos;
            cin >> pos >> add;
            len++;
            for(int i=len-1;i>=pos;i--) s[i]=s[i-1];

            s[pos-1]=add;
        }
        else
        {
            int pos;
            cin >> pos;
            for(int i=pos-1;i<len;i++) s[i]=s[i+1];
            len--;
        }
    }
    cout << s;
}
