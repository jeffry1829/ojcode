/*
 * 2831_Wormholes.cpp
 *
 *  Created on: 2018年11月15日
 *      Author: Jeason
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#define N 1000
using namespace std;
int numPoint,numPath,numHole;
int T,temp,temA,temB,temLength;
int dist[N],num_visited[N];  //dist用于记录搜寻源点到各点的距离，num_visited用于记录每个点入队的次数；
int root;     //SPFA的搜寻起点；
queue<int> Q;
struct node
{
    int nextPoint;
    int length;
};
vector <node> Tree[N];

void readData(){
    cin >> numPoint >> numPath >> numHole;
    for(int i = 0 ; i < numPath ;i++){
        cin >> temA >> temB >> temLength;
        node P1,P2;
        P1.nextPoint = temB;
        P1.length = temLength;
        P2.nextPoint = temA;
        P2.length = temLength;
        Tree[temA].push_back(P1);
        Tree[temB].push_back(P2);
        root = temA;      //找起点；
    }
    for(int i = 0 ; i < numHole ;i++){
        node P;
        cin >> temA >> temB >> temLength;
        P.nextPoint = temB;
        P.length = 0 - temLength;
        Tree[temA].push_back(P);
    }
}

void init()
{
    for( int i = 0; i < N; i++ )
        Tree[i].clear();
    memset(num_visited,0,sizeof(num_visited));
}

int SPFA()
{
    while(!Q.empty()){

        temp = Q.front();
        Q.pop();
//        cout << temp << "点出队" << endl;
        if(num_visited[temp] > numPoint)
            return 0;  //返回0说明有负权环出现，Q队列一直不为空，死循环
        for(int i = 0; i < Tree[temp].size(); i++){ //对出队的每个点进行遍历,并进行松弛
            if(dist[ Tree[temp][i].nextPoint ] > dist[temp] + Tree[temp][i].length ){
                dist[ Tree[temp][i].nextPoint ] = dist[temp] + Tree[temp][i].length;
                Q.push(Tree[temp][i].nextPoint);
//                cout <<  Tree[temp][i].nextPoint << " > " << temp << " + " << Tree[temp][i].length << endl;
//                cout << "已被松弛：" << temp <<"--->" << Tree[temp][i].nextPoint <<endl;
//                cout << Tree[temp][i].nextPoint << "点入队" << endl;
                num_visited[Tree[temp][i].nextPoint]++;
            }
        }
    }
    return 1;   //返回1说明SPFA操作成功，没有负权环出现
}

int main()
{
    cin >> T;
    while(T--){
        init();
        readData();

        for(int i = 0; i < N;i++)
            dist[i] = 999999;
        Q.push(root);
//        cout << root << "点入队" << endl;
        dist[root] = 0;
        num_visited[root]++;
        if ( SPFA() )
            cout << "NO" << endl;
        else
            cout << "YES" <<endl;
    }
    return 0;
}


/*

Sample Input
2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3

3 2 1
1 2 3
2 3 4
3 1 8
Sample Output
NO
YES

 * */