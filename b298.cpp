#include<bits/stdc++.h>
using namespace std;
typedef struct{
	bool isBad;
	vector<int> factorynum;
}factory;
vector<factory> onetoN;
queue<int> q;
int main(void){
	int N,M,L,Q;
	scanf("%d%d%d%d",&N,&M,&L,&Q);
	onetoN.resize(N);
	for(int i=0;i<N;i++){
		onetoN[i].isBad=false;
	}
	int a,b;
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		onetoN[a].factorynum.push_back(b);
	}
	int x;
	for(int i=0;i<L;i++){
		scanf("%d",&x);
		q.push(x);
		while(!q.empty()){
			int cur=q.front(); q.pop();
			if(onetoN[cur].isBad){
				continue;
			}
			onetoN[cur].isBad=true;
			int cursize=onetoN[cur].factorynum.size();
			for(int j=0;j<cursize;j++){
				q.push(onetoN[cur].factorynum[j]);
			}
		}
	}
	int y;
	for(int i=0;i<Q;i++){
		scanf("%d",&y);
		if(!onetoN[y].isBad) puts("YA~~\n");
		else puts("TUIHUOOOOOO\n");
	}
} 
