VI G[_n];
int sz[_n],cd_fa[_n];
bool del[_n];
void dfsSz(int v,int faa){
  sz[v]=1;
  rep(i,0,SZ(G[v]))if(G[v][i]!=faa and !del[G[v][i]])dfsSz(G[v][i],v),sz[v]+=sz[G[v][i]];
}
int get_centroid(int v,int faa,int cnt){
  rep(i,0,SZ(G[v]))if(G[v][i]!=faa and !del[G[v][i]] and sz[G[v][i]]>cnt/2)
    return get_centroid(G[v][i],v,cnt);
  return v;
}
void centroid_decomposition(int v,int faa){
  dfsSz(v,faa);int centroid=get_centroid(v,faa,sz[v]);
  cd_fa[centroid]=faa,del[centroid]=1;
  rep(i,0,SZ(G[centroid]))if(G[centroid][i]!=faa and !del[G[centroid][i]])
    centroid_decomposition(G[centroid][i],centroid);
}





/*
***
應用https://zhanghuimeng.github.io/post/centroid-decomposition-summaary-and-example/
***
*/
void update(int vv){
  int b=vv;
  while(b!=-1){ //應用到了cd的root的fa是-1
    int l=lca(vv,b);
    ans[b]=min(ans[b],dep[vv]+dep[b]-2*dep[l]);
    b=cd_fa[b];
  }
}