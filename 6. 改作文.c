#include <stdio.h>
#include <string.h>
//ȫ�ֱ���
char a[100000]; 


////��Сдת������ ����������ȡ��ַ 
//void change(char *a){
//	if('A'<=*a&&*a<='Z') *a=*a+32;//��дתСд 
//	if('a'<=*a&&*a<='z') *a=*a-32;//Сдת��д 
//} ��Щ����

char change(char a){
	if('A'<=a&&a<='Z') return a-'A'+'a';
	if('a'<=a&&a<='z') return a-'a'+'A';
} 



//������
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
