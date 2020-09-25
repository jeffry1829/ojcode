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
#define abs(x) ((x<0)?(-x):(x))
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
const int _n=2e5+10,MAXB=19;
int n,m,k,a,b,dep[_n],fa[_n][MAXB],u,v;
VI G[_n];
void dfs(int v,int faa,int d){
  dep[v]=d;fa[v][0]=faa;
  rep(i,0,SZ(G[v]))if(faa!=G[v][i])dfs(G[v][i],v,d+1);
}
void bfa(){
  rep(j,1,MAXB)rep(i,1,n+1)if(~fa[i][j-1])
    fa[i][j]=fa[fa[i][j-1]][j-1];
}
int lca(int a,int b){
  if(dep[a]<dep[b])swap(a,b);
  per(j,0,MAXB)if(~fa[a][j] and dep[fa[a][j]]>=dep[b])a=fa[a][j];
  if(a==b)return a;
  per(j,0,MAXB)if(~fa[a][j] and fa[a][j]!=fa[b][j])a=fa[a][j],b=fa[b][j];
  return fa[a][0];
}
<<<<<<< HEAD
=======
bool cmp(const int& a,const int& b){return dep[a]<dep[b];}
>>>>>>> bcb82c2e43f4a4977aac2be34685c656cf819d48
main(void) {cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>n>>m;rep(i,0,n-1){cin>>u>>v;G[u].pb(v),G[v].pb(u);}
  dfs(1,-1,0);rep(i,1,n+1)rep(j,1,MAXB)fa[i][j]=-1; bfa();
  while(m--){
<<<<<<< HEAD
    cin>>k;VI cnt(0,k+1);rep(i,0,k){
      cin>>v;
      if(!cnt[dep[v]])cnt[dep[v]]=v;
      
    }
=======
    cin>>k;VI ks;rep(i,0,k){cin>>v;ks.pb(v);}
    rep(i,0,k)ks[i]=(fa[ks[i]][0]==-1?1:fa[ks[i]][0]);
    sort(all(ks),cmp);
    rep(i,1,k)if(lca(ks[i-1],ks[i])!=ks[i-1]){cout<<"NO\n";goto A;}
    cout<<"YES\n";
    A:;
>>>>>>> bcb82c2e43f4a4977aac2be34685c656cf819d48
  }
  return 0;
}
