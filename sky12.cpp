#include<iostream>
#include<string.h>
using namespace std;
char stk[1000001];
int top;

char pop()
{
	if(top!=0)
		return stk[--top];
	return 'e'; //for error
}

void push(char c)
{
	stk[top]=c;
	top++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool gg,snow;
	int len;
	char tmp,instring[1000001];
	while(cin>>instring)
	{
		top=0;
		gg=0;
		snow=0;
		len=strlen(instring);
		for(int i=0;i<len&&!gg;i++)
		{
			if(snow==1)
			{
				if(instring[i]!='m')
					gg=1;
				snow=0;
			}
			else if(instring[i]=='('||instring[i]=='['||instring[i]=='{')
				push(instring[i]);
			else if(instring[i]=='s')
				snow=1;
			else
			{
				tmp=pop();
				if((instring[i]==')'&&tmp!='(')||(instring[i]==']'&&tmp!='[')||(instring[i]=='}'&&tmp!='{'))
					gg=1;
			}
		}
		if(!gg&&pop()=='e')
			cout<<"SM"<<endl;
		else
			cout<<"MS"<<endl;
	}
	return 0;
}	
