#include<iostream>
using namespace std;
int T,N,man[1000000];
int stk[1000000],stktop;
void push(int x)
{
	stk[stktop++]=x;
}
int pop()
{
	return stk[--stktop];
}
int gettop()
{
	if(stktop==0)return 0;//avoid stktop<0
	return stk[stktop-1];
}
int main()
{
	int cand,nxt,points,cnt;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		points=0;
		cin>>N;
		cin>>cand;
		//cand=man[0];
		for(int j=1;j<N;j++)
		{
			cin>>nxt;
			cnt=0;
			if(nxt>=cand)
			{
				if(stktop!=0)
				{
					points++;
				}
				while(stktop!=0&&gettop()<nxt)
				{
					pop();
					points++;
				}
				while(stktop!=0&&gettop()==nxt)
				{
					cnt++;
					pop();
					points++;
				}
				if(stktop==0)
					points--;
				for(int k=0;k<cnt;k++)
				{
					push(cand);
				}
			}
			else
			{
				push(cand);
			}
			cand=nxt;
		}
		cout<<points+N-1<<endl;
	}
	return 0;
}
