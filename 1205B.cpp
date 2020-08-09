#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
//#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x){return mrand()%x;}
ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
#define rank oiajgpowsdjg
const int N = 100;
int parent[N], rank[N];
inline void dsinit(int n) {for (int i = 0; i < n; i++)parent[i] = i;memset(rank, 0, sizeof rank);}
inline int dsfind(int e) {return parent[e] == e ? e : parent[e] = dsfind(parent[e]);}
inline void dsunion(int s1, int s2) {if (rank[s1] < rank[s2])swap(s1, s2);parent[s2] = s1;if (rank[s1] == rank[s2]) rank[s1]++;}
//head

const int _n=1e5+10;
int n;
ll a[_n];
VI G[500];
//bool vis[500];
int flag[_n],dis[300][300],mp[300][300];
main(void) {cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>n;rep(i,0,n)cin>>a[i];
  for(ll i=1ll;i<=(1ll<<60ll);i<<=1ll){
    int cnt=0;rep(j,0,n)if(a[j]&i)cnt++,flag[j]++;
    if(cnt>=3){cout<<3<<'\n';return 0;}
  }
  for(ll i=1ll;i<=(1ll<<60ll);i<<=1ll){
    rep(j,0,n)if(a[j]&i)flag[j]++;
  }
  int cnt=0;rep(i,0,n)if(flag[i]>=2)a[cnt++]=a[i];
  //floyd
  rep(i,0,cnt)rep(j,0,cnt)mp[i][j]=1e9;
  rep(i,0,cnt-1)rep(j,i+1,cnt)if(a[i]&a[j])mp[i][j]=mp[j][i]=1;
  rep(i,0,cnt)mp[i][i]=0;
  rep(i,0,cnt)rep(j,0,cnt)dis[i][j]=mp[i][j];
  int minn=1e9;rep(k,0,cnt){
    rep(i,0,k-1)rep(j,i+1,k)minn=min(minn,1ll*dis[i][j]+1ll*mp[i][k]+1ll*mp[k][j]);
    rep(i,0,cnt)rep(j,0,cnt)dis[i][j]=min(dis[i][j],1ll*dis[i][k]+1ll*dis[k][j]);
  }
  /*rep(i,0,cnt-1)rep(j,i+1,cnt)if(a[i]&a[j])G[i].pb(j),G[j].pb(i);
  int minn=1e9+7;rep(u,0,cnt)rep(j,0,SZ(G[u])){
    int v=G[u][j];
    queue<PII> q;q.push({u,0});memset(vis,0,sizeof vis);
    while(!q.empty()){
      while(!q.empty() and vis[q.front().fi])q.pop();
      if(q.empty())break;
      PII now=q.front();q.pop();vis[now.fi]=1;
      if(now.fi==v){minn=min(minn,now.se+1);break;}
      rep(i,0,SZ(G[now.fi]))if(!vis[G[now.fi][i]])
        if(!(now.fi==u and G[now.fi][i]==v))q.push({G[now.fi][i],now.se+1});
    }
  }*/
  if(minn==(int)1e9)minn=-1;
  cout<<minn<<'\n';
  return 0;
}