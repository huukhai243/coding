#include<stdio.h>
#include<string.h>
#define MAX 102
int main(){
	char s[max];
	printf("Nhap chuoi:")
	fflush(stdin);
	gets(s);
	int m[26]={0};
	int i;
	for(i=o;i<strlen(s);i++){
		if(s[i]>='a' && s[i]<='z')
		m[s[i]-97]++;
	}
	int j;
	for(j=0;j<26;j++){
		if(m[j] !=0)
		printf("Chu %c xuat hien %d lan.\n",j+97,m[j]);
	}
	return 0;
}
	
}
