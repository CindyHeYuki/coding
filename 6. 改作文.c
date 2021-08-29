#include <stdio.h>
#include <string.h>
//全局变量
char a[100000]; 


////大小写转换函数 输入用数组取地址 
//void change(char *a){
//	if('A'<=*a&&*a<='Z') *a=*a+32;//大写转小写 
//	if('a'<=*a&&*a<='z') *a=*a-32;//小写转大写 
//} 有些问题

char change(char a){
	if('A'<=a&&a<='Z') return a-'A'+'a';
	if('a'<=a&&a<='z') return a-'a'+'A';
} 



//主函数
int main(){
	
	while(gets(a)!=NULL)
	{
		
		
	
		
		int len=0;
		len=strlen(a);
		int i=0;
		
		for(i=0;i<len;i++){
			if('A'<=a[i]&&a[i]<='Z') {
//				if(('A'<=a[i-1]&&a[i-1]<='Z')||('a'<=a[i-1]&&a[i-1]<='z')) {
//					a[i]=change(a[i]);
//				}
				if(a[i-2]!='.') {
					a[i]=change(a[i]);
				}
			}
			if('a'<=a[i]&&a[i]<='z'){
				if(&a[i]==&a[0]){
					a[i]=change(a[i]);
				} 
				if(a[i-1]==' '&&(a[i-2]=='.'||a[i-2]=='?'||a[i-2]=='!')) {
					a[i]=change(a[i]);
				}
			}
		}
		
		puts(a);
	}
	
	
	return 0;
} 
