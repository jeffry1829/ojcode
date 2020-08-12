#include<bits/stdc++.h>
using namespace std;
int FX,FY,SX,SY,EX,EY,T;
char premap[171]="******************...*.......**..***..*....*.*.*..**......*.**.**.***..**...**..**.****.....**..*.*..**....*..........**.....****.*...******.*.*........******************";
int map_[10][17]={{0},{0}}; // 1 if cannot // x,y
queue<pair<int,int> > firequeue;
queue<pair<int,int> > spotqueue;
void fire(){
	int firesize_of_t=firequeue.size();
	for(int j=0;j<firesize_of_t;j++){
		pair<int,int> curfire=firequeue.front(); firequeue.pop();
		//x-1
		if(!(curfire.first-1==EX&&curfire.second==EY))
		if(!map_[curfire.first-1][curfire.second]){
			map_[curfire.first-1][curfire.second]=1;
			firequeue.push(make_pair(curfire.first-1,curfire.second));
		}
		//x+1
		if(!(curfire.first+1==EX&&curfire.second==EY))
		if(!map_[curfire.first+1][curfire.second]){
			map_[curfire.first+1][curfire.second]=1;
			firequeue.push(make_pair(curfire.first+1,curfire.second));
		}
		//y-1
		if(!(curfire.first==EX&&curfire.second-1==EY))
		if(!map_[curfire.first][curfire.second-1]){
			map_[curfire.first][curfire.second-1]=1;
			firequeue.push(make_pair(curfire.first,curfire.second-1));
		}
		//y+1
		if(!(curfire.first==EX&&curfire.second+1==EY))
		if(!map_[curfire.first][curfire.second+1]){
			map_[curfire.first][curfire.second+1]=1;
			firequeue.push(make_pair(curfire.first,curfire.second+1));
		}
	}
}
int main(void){
	scanf("%d%d%d%d%d%d%d",&FX,&FY,&T,&SX,&SY,&EX,&EY);
	for(int i=0;i<10;i++){//x
		for(int j=0;j<17;j++){//y
			int index=17*i+j;
			if(premap[index]=='*') map_[i][j]=1;
		}
	}
	map_[FX][FY]=1;
	firequeue.push(make_pair(FX,FY)); //what to push: already on fire
	for(int i=1;i<=T-2;i++){
		fire();
		if(map_[SX][SY]==1){
			puts("Help!");
			return 0;
		}
	}
	fire();
	pair<int,int> E (EX,EY);
	spotqueue.push(make_pair(SX,SY));
	map<pair<int,int>,bool> alreadyspot;
	alreadyspot[make_pair(SX,SY)]=true;
	int TT=-1;
	while(!spotqueue.empty()){
		fire();
		TT++;
		int spotsize_of_t=spotqueue.size();
		for(int j=0;j<spotsize_of_t;j++){
			pair<int,int> curspot=spotqueue.front(); spotqueue.pop();
			if(curspot==E){
				printf("%d",TT);
				return 0;
			}
			//x-1
			if(!alreadyspot.count(make_pair(curspot.first-1,curspot.second)))
			if(!map_[curspot.first-1][curspot.second]){
				spotqueue.push(make_pair(curspot.first-1,curspot.second));
				alreadyspot[make_pair(curspot.first-1,curspot.second)]=true;
			}
			//x+1
			if(!alreadyspot.count(make_pair(curspot.first+1,curspot.second)))
			if(!map_[curspot.first+1][curspot.second]){
				spotqueue.push(make_pair(curspot.first+1,curspot.second));
				alreadyspot[make_pair(curspot.first+1,curspot.second)]=true;
			}
			//y-1
			if(!alreadyspot.count(make_pair(curspot.first,curspot.second-1)))
			if(!map_[curspot.first][curspot.second-1]){
				spotqueue.push(make_pair(curspot.first,curspot.second-1));
				alreadyspot[make_pair(curspot.first,curspot.second-1)]=true;
			}
			//y+1
			if(!alreadyspot.count(make_pair(curspot.first,curspot.second+1)))
			if(!map_[curspot.first][curspot.second+1]){
				spotqueue.push(make_pair(curspot.first,curspot.second+1));
				alreadyspot[make_pair(curspot.first,curspot.second+1)]=true;
			}
		}
	}
	puts("Help!");
} 
