#include <iostream>
#include <cstring>
#include <vector>
#define N 1001
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
#define abs(x) ((x)>0?(x):(-(x)))
using namespace std;
int B[N],cnt;
bool wed[N];
struct MP{
    int t,x,y;
}D[N];
bool DFS(vector<int>*G,int x){
    wed[x]=true;
    F(G[x].size())if(!wed[B[G[x][i]]-1]){
        if(!B[G[x][i]]||DFS(G,B[G[x][i]]-1)){
            if(!B[G[x][i]])cnt++;
            B[G[x][i]]=x+1;
            return true;
        }
    }
    return false;
}
main(){
    int n;
    cin>>n;
    while(cin>>n){
        vector<int>G[N];
        F(n)cin>>D[i].t>>D[i].x>>D[i].y;
        F(n)Fi(j,n)if(i!=j&&abs(D[i].x-D[j].x)+abs(D[i].y-D[j].y)+D[i].t<=D[j].t){
            G[i].push_back(j);
        }
        memset(B,0,sizeof(B));
        cnt=0;
        F(n)DFS(G,i),memset(wed,0,sizeof(wed));
        cout<<(n-cnt)<<endl;
    }
}