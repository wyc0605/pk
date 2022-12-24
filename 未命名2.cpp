#include <bits/stdc++.h>
using namespace std;
int n,m,root,dep[40005],f[40005][20];
vector<int> ve[40005];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for(int i=1;i<=log2(dep[u]);i++)
	{
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=0;i<ve[u].size();i++)
	{
		if(ve[u][i]!=fa)
		{
			f[ve[u][i]][0]=u;
			dfs(ve[u][i],u);
		}
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])
	{
		swap(u,v);
	}
	for(int i=log2(n);i>=0;i--)
	{
		if(dep[f[u][i]]>=dep[v])
		{
			u=f[u][i];			
		}
	}
	if(u==v)
	{
		return u;
	}
	for(int i=log2(n);i>=0;i--)
	{
		if(f[u][i]!=f[v][i])
		{
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(b==-1)
		{
			root=a;
		}
		else
		{
			ve[a].push_back(b);
			ve[b].push_back(a);
		}
	}
	dfs(root,0);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,ans;
		cin>>x>>y;
		ans=lca(x,y);
		if(ans==x)
		{
			cout<<1<<endl;
		}
		else if(ans==y)
		{
			cout<<2<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
