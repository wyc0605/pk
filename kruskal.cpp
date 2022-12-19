#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,w;
}e[10005];
int n,m,g[105][105],cn,f[105],ans;
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int findf(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    return f[x]=findf(f[x]);
}
void merge(int a,int b)
{
    int u=findf(a);
    int v=findf(b);
    if(u!=v)
    {
        f[u]=f[v];
    }
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		cn++;
		e[cn].x=x;
		e[cn].y=y;
		e[cn].w=w;
		cn++;
		e[cn].x=y;
		e[cn].y=x;
		e[cn].w=w;
	}
	sort(e+1,e+cn+1,cmp);
	for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=cn;i++)
    {
        if(findf(e[i].x)!=findf(e[i].y))
        {
            ans+=e[i].w;
            merge(e[i].x,e[i].y);
        }
    }
    cout<<ans<<endl;
	return 0;
}
