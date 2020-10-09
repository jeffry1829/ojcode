#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
#define abs(x) (((x)<0)?(-(x)):(x))
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x){return mrand()%x;}
ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
inline int pmod(int x, int d){int m = x%d;return m+((m>>31)&d);}
#define y1 ojsapogjahg
#define prev ojaposjdas
#define rank oiajgpowsdjg
#define left aijhgpiaejhgp
//#define end aononcncnccc
//head
const int _n=1510;
int t,n,m,e,u,v;
VI G[_n];
int mat[_n],vis[_n];
bool dfs(int u,int T){
  for(int v:G[u])if(vis[v]!=T){
    vis[v]=T;if(mat[v]==-1 or dfs(mat[v],T)){mat[v]=u;return 1;}
  }return 0;
}
int main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m>>e;rep(i,1,e+1){cin>>u>>v;G[u].pb(n+v);}
  memset(mat,-1,sizeof mat);
  int T=0,cnt=0;rep(i,1,n+1)if(dfs(i,++T))cnt++;
  cout<<cnt<<'\n';
  return 0;
}