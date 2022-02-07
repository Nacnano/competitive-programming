#include<bits/stdc++.h>
using namespace std;

stack<int> stk;
queue<int> q;

int main(){
	
	string s;
	cin >> s;
	for(int i=0;s[i];i++)
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			q.push(20);
		}
		else if(s[i]>='1' && s[i]<='3')
		{
			while(!stk.empty())
			{
				if(stk.top()=='[' || stk.top()<s[i]-'0') break;
				q.push(stk.top());
				stk.pop();
			}
			stk.push(s[i]-'0');
		}
		else if(s[i]=='[')
		{
			stk.push(s[i]);
		}
		else if(s[i]==']')
		{
			while(!stk.empty())
			{
				if(stk.top()=='[')
				{
					stk.pop();
					break;
				}
				q.push(stk.top());
				stk.pop();		
			}
		}
	}
	
	while(!stk.empty())
	{
		q.push(stk.top());
		stk.pop();
	}
	
//	while(!q.empty())
//	{
//		printf("%d ",q.front());
//		q.pop();
//	}
//	return 0;
	
	while(!q.empty())
	{
		if(q.front()>=1 && q.front()<=3)
		{
			int a=stk.top();
			stk.pop();
			int b=stk.top();
			stk.pop();
			
			int val=a+b;
			if(q.front()==1) val+=4*(a+b)/100; 
			if(q.front()==2) val+=8*(a+b)/100; 
			if(q.front()==3) val+=16*(a+b)/100; 
			stk.push(val);
			q.pop();
		}
		else
		{
			stk.push(q.front());
			q.pop();
		}
	}
	printf("%d",stk.top());
}
