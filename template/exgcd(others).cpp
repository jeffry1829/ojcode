void exgcd(int a,int b,int& d,int& x,int& y){
    if(!b)x=1,y=0,d=a;
    else exgcd(b, a%b, d, y, x),y-=x*(a/b);
}