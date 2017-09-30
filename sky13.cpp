#include<iostream>
using namespace std;
struct space{
    long long int height,loc;
}stk[100010];
long long int len[100010];
int stktop;

void jpush(long long int h,long long int l)
{
    stk[stktop].height=h;
    stk[stktop++].loc=l;
}
int jpop()
{
    return --stktop;
}
int gettop()
{
    return stktop-1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n,tmp,jarea,marea,lloc;
    while(cin>>n)
    {
        marea=0;
        stktop=1;
        stk[0].height=-1;
        stk[0].loc=0;
        for(int i=1;i<=n;i++)
            cin>>len[i];
        for(int i=1;i<=n;i++)
        {
            if(stk[gettop()].height<len[i])
                jpush(len[i],i);
            else
            {
                while(stk[gettop()].height>len[i])
                {
                    tmp=jpop();
                    lloc=stk[tmp].loc;
                    jarea=stk[tmp].height*(i-stk[tmp].loc);
                    if(jarea>marea)
                        marea=jarea;
                }
                if(stk[gettop()].height<len[i])
                    jpush(len[i],lloc);
            }

        }
        while(stktop!=0)
        {
            tmp=jpop();
            jarea=stk[tmp].height*(n+1-stk[tmp].loc);
            if(jarea>marea)
                marea=jarea;
        }
        cout<<marea<<endl;
    }
    return 0;
}
