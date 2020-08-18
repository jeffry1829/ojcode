void spfa(int a){
    instack[a]=true;//节点入栈
    for(int i=head[a];~i;i=Ed[i].next){//遍历出边
        if(dis[a]+Ed[i].w<dis[Ed[i].to]){//如果满足条件
            dis[Ed[i].to]=dis[a]+Ed[i].w;//更新答案
            if(!instack[Ed[i].to]){//如果终点不在栈内
                spfa(Ed[i].to);//深搜
            }
            else{//否则
                return;//有负环
            }
        }
    }
    instack[a]=false;//将当前结点退栈
}