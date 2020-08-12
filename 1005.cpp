#include<iostream>
#include<string.h>
using namespace std;

int main()
{
   int s,a=0;
	//char t[];
   for(int i=2;i<=1000000;i++){
	    s=0;
		for(int j=2;j<=i;j++){
		   if(i%j==0)
	         s++;
	       }
		if(s==1)
		   a++;
	       
	}
	cout<<a;       
	    
	return 0;
}
