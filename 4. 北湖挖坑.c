#include <stdio.h>
#include <string.h>
int absolute(int a,int b){
	if(a>b){
		return a-b;
	}
	else return b-a;
}
int main(){
	int wide=0, height=0;
	int a[100005]={0};
	long long int i=0,t=0;
	 
	scanf("%d %d",&wide,&height);
	a[0]=height;a[wide+1]=height;
	for(i=1;i<=wide;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<=wide;i++){
		t+=absolute(a[i],a[i+1]);
	}
	
	t/=2;
	
	printf("%lld\n",t);
	
	
	return 0;
}
