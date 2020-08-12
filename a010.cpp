#include<bits/stdc++.h>
using namespace std;
map<int,int> primemap;
map<int,int> result;
bool isPrime(int x){
	if(primemap[x]==2)
		return true;
	if(primemap[x]==1)
		return false;
	int sqroot=sqrt(x);
	for(int i=2;i<=sqroot;i++){
		if(x%i==0){
			primemap[x]=1;
			return false;	
		}
	}
	primemap[x]=2;
	return true;
}
void extract(int x){
	int halfx=x/2;
	for(int i=2;i<halfx;i++){
		if(x%i==0){
			int j=x/i; // i should < j
			if(!isPrime(i)){
				extract(i);
			}else{
				if(!result.count(i)) result[i]=1;
				else result[i]++;
			}
			if(!isPrime(j)){
				extract(j);
			}else{
				if(!result.count(j)) result[j]=1;
				else result[j]++;
			}
			return;
		}
	}
}
int main(void){
	int x;
	while(scanf("%d",&x)!=EOF){
		if(isPrime(x)){
			printf("%d\n",x);
			continue;
		}
		extract(x);
		for(map<int,int>::iterator it=result.begin();it!=result.end();it++){
			if(it==--result.end()){
				if(it->second==1){
					printf("%d\n",it->first);
				}
				else{
					printf("%d^%d\n",it->first,it->second);
				}
				break;
			}

			if(it->second==1){
				printf("%d * ",it->first);
			}else{
				printf("%d^%d * ",it->first,it->second);
			}
		}
		result.clear();
	}
}
