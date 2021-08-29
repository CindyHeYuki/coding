#include <stdio.h>
int main(){
	int T=0,t=0;
	int n=0;
	int a[100002]={0};
	long long int water=0;
	int flag1=0,flag2=0;
	int i=0;
	
	scanf("%d",&T);
	for(t=0;t<T;t++){
		memset(a,0,sizeof(a));
		water=0;//renew
		
		//input
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		//find flag in left
		int left_max=0;
		for(i=0;i<n;i++){
			if(a[i]>left_max){
				flag1=i;
				left_max=a[i];
			}
		}
		//find flag in right
		int right_max=0;
		for(i=n-1;i>=0;i--){
			if(a[i]>right_max){
				flag2=i;
				right_max=a[i];
			}
		}
		
		//judge whether it has only one max or not
		int tem_flag1=0,tem_flag2=0;
		if(flag1==flag2){//only one hill
			//left side
			for(i=0;i<flag1;i++){
				if(a[i]>tem_flag1){
					tem_flag1=a[i];
				}
				else{
					water+=tem_flag1-a[i]; 
				}
			}
			//right side
			for(i=n-1;i>flag2;i--){
				if(a[i]>tem_flag2){
					tem_flag2=a[i];
				}
				else{
					water+=tem_flag2-a[i];
				}
			}
			
			printf("%lld\n",water);
			
			
		}
		else{
			//left side
			for(i=0;i<flag1;i++){
				if(a[i]>tem_flag1){
					tem_flag1=a[i];
				}
				else{
					water+=tem_flag1-a[i]; 
				}
			}
			//right side
			for(i=n-1;i>flag2;i--){
				if(a[i]>tem_flag2){
					tem_flag2=a[i];
				}
				else{
					water+=tem_flag2-a[i];
				}
			}
			
			//middle
			for(i=flag1+1;i<flag2;i++){
				water+=a[flag1]-a[i];
			}
			
			printf("%lld\n",water);
			
		}
		
	}
	
	return 0;
}
