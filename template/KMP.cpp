//注意:失敗函數的值和index都代表"長度"，所以是1-base
int F[N];
int match(const std::string& A, const std::string& B){
  F[0] = -1, F[1] = 0;
  for(int i = 1, j = 0; i < (int)B.size() - 1; F[++i] = ++j) { //計算失敗函數，需要時可以改成i<(int)B.size()
    if (B[i] == B[j]) F[i] = F[j]; //優化，略去此行依然有相同結果 //這改變了失敗函數的定義
    while (j != -1 && B[i] != B[j]) j = F[j];
  }
  for (int i = 0, j = 0; i - j + B.size() <= A.size(); i++, j++) { //匹配 
    while (j != -1 and A[i] != B[j]) j = F[j];
    if (j == (int)B.size() - 1) return i - j; //成功匹配到B 字串的結尾，回傳結果
  }
  return -1;
}
/* 這個也可以求失敗函數
F[0]=-1,jj=-1;rep(i,0,lenp){
    jj=F[i];
    while(jj!=-1 and p[i]!=p[jj])jj=F[jj];
    F[i+1]=jj+1; //if jj==-1, F[i]=0
  }
*/

/*
F[0]=-1;
for(int i = 0, j = -1; i < lenp; F[++i] = ++j) { //計算失敗函數，一般來說i<lenp-1，但是這題我們需要i<lenp
  while (j != -1 && p[i] != p[j]) j = F[j];
}
jj=F[lenp];
while(jj!=-1){ //**看看哪些前綴可以和整條字串p的後綴匹配**
  vis[jj]=1;
  jj=F[jj];
}
*/