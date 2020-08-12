#include<stdio.h>
int main(void){
	int a,b,steps=0;
	scanf("%d%d",&a,&b);
	for(;;){
		if(a==b){
			printf("%d",steps);
			return 0;	
		}
		if(a>b)
			a>>=1;
		else
			b>>=1;
		steps++;	
	}
}
