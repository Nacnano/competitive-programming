#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	
	double x=0,y=0;
	while(1)
	{
		string s,q;
		cin >> s;
		if(s=="*") break;
		
		int i=0, cnt=0;
		while(s[i]>='0' && s[i]<='9') cnt=cnt*10+s[i++]-'0';
		while(s[i]>='A' && s[i]<='Z') q+=s[i++];
		
		if(q=="N") y+=cnt;
		else if(q=="S") y-=cnt;
		else if(q=="E") x+=cnt;
		else if(q=="W") x-=cnt;
		else if(q=="NE") x+=cnt/sqrt(2), y+=cnt/sqrt(2);
		else if(q=="SE") x+=cnt/sqrt(2), y-=cnt/sqrt(2);
		else if(q=="SW") x-=cnt/sqrt(2), y-=cnt/sqrt(2);
		else if(q=="NW") x-=cnt/sqrt(2), y+=cnt/sqrt(2);
	}
	cout << fixed << setprecision(3) << x << " " << y << endl;
	cout << sqrt(x*x + y*y);
}
