#include<bits/stdc++.h>
using namespace std;

main(void){
	ios_base::sync_with_stdio(false); cin.tie(0);
	unordered_set<string> stplace,stanimal;
	vector<string> place;
	place.reserve(1000);
	vector<string> animal;
	animal.reserve(1000);
	
	//map<string,int> idplace;
	//map<string,int> idanimal;
	
	int table[1000][1000]={{0}}; //place-animal
	int n;
	cin>>n;
	while(n--){
		string ani,plac; int count;
		cin>>ani>>count>>plac;
		if(stplace.find(plac)==stplace.end()){
			place.push_back(plac);
			//idplace[plac]=idplace.size()+1;
			stplace.insert(plac);
		}
		if(stanimal.find(ani)==stanimal.end()){
			animal.push_back(ani);
			//idanimal[ani]=idanimal.size()+1;
			stanimal.insert(ani);
		}
		int indpl,indan;
		for(int i=0;i<place.size();i++)
			if(place[i]==plac)
				indpl=i;
		for(int i=0;i<animal.size();i++)
			if(animal[i]==ani)
				indan=i;
		table[indpl][indan]+=count;
	}
	for(int i=0;i<place.size();i++){
		cout<<place[i]<<" : ";
		int sofar=0;
		for(int j=0;j<animal.size();j++){
			if(table[i][j]){
				if(!sofar){
					cout<<animal[j]<<" "<<table[i][j];
					sofar++;
					continue;
				}
				cout<<", "<<animal[j]<<" "<<table[i][j];
			}
		}
		cout<<endl;
	}
}
