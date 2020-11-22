//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int _n=1010;
int t,n,m,cnt;
char mp[_n][_n];
bool vis[_n][_n],row[_n],col[_n];
void dfs(int x,int y){
  vis[x][y]=1,row[x]=1,col[y]=1;
  if(mp[x][y+1]=='#' and !vis[x][y+1])dfs(x,y+1);
  if(mp[x][y-1]=='#' and !vis[x][y-1])dfs(x,y-1);
  if(mp[x+1][y]=='#' and !vis[x+1][y])dfs(x+1,y);
  if(mp[x-1][y]=='#' and !vis[x-1][y])dfs(x-1,y);
}
main(void) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;rep(i,1,n+1)cin>>(mp[i]+1);
  rep(i,1,n+1){
    bool z=0,zz=0;
    rep(j,1,m+1){
      if(z and mp[i][j]=='.')zz=1;
      if(mp[i][j]=='#')z=1;
      if(z and zz and mp[i][j]=='#'){cout<<"-1\n";return 0;}
    }
  }
  rep(j,1,m+1){
    bool z=0,zz=0;
    rep(i,1,n+1){
      if(z and mp[i][j]=='.')zz=1;
      if(mp[i][j]=='#')z=1;
      if(z and zz and mp[i][j]=='#'){cout<<"-1\n";return 0;}
    }
  }
  rep(i,1,n+1)rep(j,1,m+1)if(mp[i][j]=='#' and !vis[i][j])dfs(i,j),cnt++;
  rep(i,1,n+1)if(!row[i]){
    int c=0;
    rep(j,1,m+1)if(!col[j])c++;
    if(!c){cout<<"-1\n";return 0;}
  }
  rep(j,1,m+1)if(!col[j]){
    int c=0;
    rep(i,1,n+1)if(!row[i])c++;
    if(!c){cout<<"-1\n";return 0;}
  }
  cout<<cnt<<'\n';
  return 0;
}