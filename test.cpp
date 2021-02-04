//#include <bits/stdc++.h>
#include <algorithm>
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
const ll mod=998244353;
int rnd(int x){return mrand()%x;}
ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
#define rank oiajgpowsdjg
#define y1 ojsapogjahg
#define prev ojaposjdas
//#define end aononcncnccc
inline int pmod(int x, int d){int m = x%d;return m+((m>>31)&d);}
//head
const int _n=1e5+10;
#include <vector>
#include <string>
int C[25][25];
std::vector<std::string> pascal_triangle(int N)
{
    std::vector<std::string> output;
    /// START YOUR CODE HERE ///
    rep(i,0,N)C[i][0]=1;
    rep(i,1,N)rep(j,1,i+1)C[i][j]=C[i-1][j-1]+C[i-1][j];
    rep(i,0,N)output.pb("");
    rep(j,0,N+1){
      int len=1,_=1;while(C[N-1][j]/(_*10))_*=10,len++;
      per(i,0,N){
        if(i<j)break;
        stringstream ss;
        if(j!=0)ss<<setw(len+1)<<C[i][j];
        else ss<<setw(len)<<C[i][j];
        output[i]=output[i]+ss.str();
      }
    }
    
    //// END YOUR CODE HERE ////
    return output;
}