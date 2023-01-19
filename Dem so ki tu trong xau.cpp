#include<stdio.h>
#include<math.h>
    int main(){
        char str[100];
        int i,n,d;
        d=0;
        printf("Nhap xau Ki tu:");    gets(str);
        while(str[i]!='0'){
            if(str[i]==' ')
                d++;
                i++;
        }    
        printf("Xau co %d tu", d);
 
    
    return 0;
}
