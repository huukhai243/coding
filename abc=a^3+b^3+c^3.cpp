#include<stdio.h>
 
int main()
{
    int i;
    int a,b,c;
 
 
    for(i=100;i<=999;i++)
    {
        int n=i;
        c=n%10;
        n/=10;
        b=n%10;
        n/=10;
        a=n%10;
 
 
 
        if(100*a+10*b+c==a*a*a+b*b*b+c*c*c)
        {
           
            printf("%d\t\n",i);
        }
    }
 
}
