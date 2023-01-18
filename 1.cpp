#include<stdio.h>
#include<conio.h>
int main(){
	int n, tong;
    printf(" nhap n: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){ 
	tong += i;
	}
	printf("%d",tong);
    getch();
    return 0;
}
