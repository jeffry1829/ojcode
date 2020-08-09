#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+50;
const int mod =1e9+7;
typedef long long ll;
vector<int>G[maxn];
int fa[maxn];
int sz[maxn];
map<int,int>mp;
void init()
{
	for(int i=0;i<maxn;i++) fa[i] = i;
}
int findset(int x)
{
	if(x==fa[x])  return x;
	else return fa[x] = findset(fa[x]);
} 
void unin(int x,int y)
{
	int fx = findset(x); 	int fy = findset(y);
	fa[fx] = fy;
	sz[fy] +=sz[fx]; 
}
void addedge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m;
	cin>>n>>m;	
	init();
	for(int i=1;i<=m;i++) 
	{
		int u,v; cin>>u>>v;
		addedge(u,v);
	}
	vector<int>gp;
	for(int i=1;i<=n;i++)
	{
		sz[i] = 1;
		mp.clear();
		int tot = 0; 
		//cout<<i<<endl;
		for(int j=0;j<G[i].size();j++)
		{
			int v = G[i][j];
			if(v>=i) continue;
			int fv = findset(v);
			//cout<<v<<" -> "<<fv<<endl;
			mp[fv]++;
		}
		for(int j=0;j<gp.size();j++)
		{
			int t = findset(gp[j]);
			int q = findset(i);
			if(t==q) continue;
			if(sz[t]>mp[t])
			{
				unin(i,t);
			}
		}
		int fx = findset(i);
		if(fx==i) gp.push_back(fx);
	}
	int cnt =0;
	for(int i=1;i<=n;i++)
	{
		 if(fa[i]==i) cnt++;
	} 
	cout<<cnt-1<<endl;
	return 0;
}