#include<stdio.h>
#include<string.h>
int main() {
//define 
	int n,i,j,p,sum=0,kind=0,len=0;
	int left[100000]= {0},right[100000]= {0},left_left[50000]= {0},right_left[50000]= {0};
	
//input	
	scanf("%d",&n);
	char a[100000];
	for(i=0; i<n; i++) {
		scanf("%s",a);
		len=strlen(a);
		
		//化简，使本身可以合并的左右括号合并 
		for(j=0; j<len; j++) {
			if(a[j]=='(') left[i]++;
			else if(a[j]==')') {
				if(left[i]>0)  left[i]--;
				else if(left[i]==0)  right[i]++;
			}
		}
	}

	for(i=0,j=0,p=0; i<n; i++) {
		if(left[i]!=0&&right[i]==0) {
			left_left[j]=i;
			j++;
		} 
		else if(left[i]==0&&right[i]!=0) {
			right_left[p]=i;
			p++;
		} 
		else if(left[i]==0&&right[i]==0) {
			kind++;
		}
	}

	for(i=0; i<j; i++) {
		for(n=0; n<p; n++) {
			if(left[left_left[i]]==right[right_left[n]]) {
				sum+=1;
				right[right_left[n]]=-1;//不让这个再被选择 
				break;
			}
		}
	}
	printf("%d\n",sum+kind/2);
}  

