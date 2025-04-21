// LC. 3455
// KMP 0-based 模板
int len = pstrs[i].size();   // pattern的length
string& curpatt = pstrs[i];  // 目前要製造next陣列的pattern
vector<int> nxt(len);
nxt[0] = 0;
int prefix_len = 0;  // 目前共同前後綴的長度
int j = 1;           // 目前看pattern的idx
while (j < len) {
  if (curpatt[j] == curpatt[prefix_len]) {
    nxt[j] = ++prefix_len;
    j++;
  } else if (prefix_len != 0) {
    prefix_len = nxt[prefix_len - 1];
  } else {
    nxt[j] = 0;
    j++;
  }
}
// 匹配
int mainidx = 0;  // 主string的idx, 主string是s
int subidx = 0;   // pattern string的idx
while (mainidx < s.size()) {
  if (s[mainidx] == curpatt[subidx]) {
    mainidx++;
    subidx++;
  } else if (subidx > 0) {
    subidx = nxt[subidx - 1];
  } else {
    mainidx++;
  }
  if (subidx == len) {
    // 找到在main string的index[mainidx - len]有match到curent pattern
    matchidxs[i].push_back(mainidx - len);  // 使用模板時請把matchidxs刪掉之類的 不一定需要這個vector
    // 繼續match，如果不需要的話可以刪掉 改成return之類的
    subidx = nxt[subidx - 1];
  }
}

// -----------------------------------------------------------------------------------------------------

// 注意:失敗函數的值和index都代表"長度"，所以是1-base
//(F[j]代表長度為F[j]的B的長度j的前綴的前綴，和長度為F[j]的B的長度j的前綴的後綴一樣)
// 基本上還是0-base，但是F[j]代表[0,F[j])和[j-F[j],j)是一樣的
// 注意到，我們定義F[j]<j([0,F[j]=j)和[j-F[j]=0,j)當然會相同)，所以F[1]=0 != 1
int F[N];
int match(const std::string& A, const std::string& B) {
  F[0] = -1, F[1] = 0;
  for (int i = 1, j = 0; i < (int)B.size() - 1; F[++i] = ++j) {  // 計算失敗函數，需要時可以改成i<(int)B.size()
    if (B[i] == B[j]) F[i] = F[j];                               // 優化，略去此行依然有相同結果 //這改變了失敗函數的定義
    while (j != -1 && B[i] != B[j]) j = F[j];
  }
  for (int i = 0, j = 0; i - j + B.size() <= A.size(); i++, j++) {  // 匹配 //i,j都是0-base,表示A,B比對吻合的前綴(0-base)
    while (j != -1 and A[i] != B[j]) j = F[j];
    if (j == (int)B.size() - 1) return i - j;  // 成功匹配到B 字串的結尾，回傳結果
  }
  return -1;
}
/* 這個也可以求失敗函數
F[0]=-1,jj=-1;rep(i,0,lenp){ //要update的是 F[i+1]
    jj=F[i];
    while(jj!=-1 and p[i]!=p[jj])jj=F[jj]; //p[i]!=p[jj] 利用了F[i]實際上比p[i]少考慮一個元素
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