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
#define y1 ojsapogjahg
#define prev ojaposjdas
#define rank oiajgpowsdjg
//#define end aononcncnccc
inline int pmod(int x, int d){int m = x%d;return m+((m>>31)&d);}
//head
const int _n=1010;
struct ele{int x,y,move;};
int t,n,m,s[11],p,mp[_n][_n],ans[11];
queue<ele> st[11],q; // queue必須宣告在外面
bool vis[_n][_n];
char c;
main(void) {cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>n>>m>>p;rep(i,1,p+1)cin>>s[i];
  cin.get();rep(i,1,n+1){rep(j,1,m+1){
    c=cin.get();int res=c;if(c=='.')res='0'+0;if(c=='#')res='0'+10;
    mp[i][j]=res-'0';
    if(mp[i][j]!=0 and mp[i][j]!=10)st[mp[i][j]].push({i,j,s[mp[i][j]]});
    if(mp[i][j]==10)vis[i][j]=1;
  }cin.get();}
  rep(i,0,n+1)mp[i][0]=10; rep(i,0,m+1)mp[0][i]=10;
  rep(i,0,n+1)mp[i][m+1]=10; rep(i,0,m+1)mp[n+1][i]=10;

  while(1){
    bool OUT=1;rep(i,1,p+1)if(!st[i].empty())OUT=0;
    if(OUT)break;
    rep(id,1,p+1){
      while(!st[id].empty())q.push(st[id].front()),st[id].pop();
      while(!q.empty()){
        ele now=q.front(); q.pop();
        if(vis[now.x][now.y])continue;
        int x=now.x,y=now.y,mv=now.move;
        mp[x][y]=id; if(mv>0)vis[x][y]=1;
        if(mv==0)st[id].push({x,y,s[id]});
        if(mv>0 and !mp[x-1][y] and !vis[x-1][y])q.push({x-1,y,mv-1});
        if(mv>0 and !mp[x+1][y] and !vis[x+1][y])q.push({x+1,y,mv-1});
        if(mv>0 and !mp[x][y-1] and !vis[x][y-1])q.push({x,y-1,mv-1});
        if(mv>0 and !mp[x][y+1] and !vis[x][y+1])q.push({x,y+1,mv-1});
      }
    }
  }
  rep(i,1,n+1)rep(j,1,m+1)ans[mp[i][j]]++;
  rep(i,1,p+1)cout<<ans[i]<<' '; cout<<'\n';
  return 0;
}