#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
//head
const int _n=1010;
struct ele{int x,y,move;};
int t,n,m,s[11],p,mp[_n][_n],ans[11];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
queue<ele> st[11],q; // queue必須宣告在外面
bool vis[_n][_n];
char c,a[_n][_n];
main(void) {
  scanf("%d%d%d",&n,&m,&p); rep(i,1,p+1)scanf("%d",&s[i]);
  rep(i,1,n+1)scanf("%s",a[i]+1);
  rep(i,1,n+1)rep(j,1,m+1){
    c=a[i][j];int res=c;if(c=='.')res='0'+0;if(c=='#')res='0'+10;
    mp[i][j]=res-'0';
    if(mp[i][j]!=0 and mp[i][j]!=10)st[mp[i][j]].push({i,j,s[mp[i][j]]}),vis[i][j]=1;   if(mp[i][j]==10)vis[i][j]=1;
  }
  while(1){
    bool OUT=1;rep(i,1,p+1){if(!st[i].empty())OUT=0;}
    if(OUT)break;
    rep(id,1,p+1){
      while(!st[id].empty())q.push(st[id].front()),st[id].pop();
      ele now;int nx,ny;
      while(!q.empty()){
        now=q.front(); q.pop();
        int x=now.x,y=now.y,mv=now.move;
        mp[x][y]=id;
        if(mv==0)st[id].push({x,y,s[id]});
        else rep(j,0,4){
          nx=x+dx[j],ny=y+dy[j];
          if(nx<1||nx>n||ny<1||ny>m||vis[nx][ny]||mp[nx][ny]||mv<=0)continue;
          vis[nx][ny]=1; //先放好vis再push，可能可以剪一點枝? 效果並不顯著
          q.push({nx,ny,mv-1});
        }
      }
    }
  }
  rep(i,1,n+1)rep(j,1,m+1)ans[mp[i][j]]++;
  rep(i,1,p+1)printf("%d ",ans[i]);
  return 0;
}