#include <stdio.h>
int main()
{
	int a,s,n,i,j,t;
	s=0;n=0;i=0;j=0;t=0;
	printf ("Nhap cac so nguyen:\n");
	while (s<=1550&&n<=100)
	{
		scanf("%d",&a);
		s+=a;
		n++;
		if (35<a&&a<70)
			i++;
		if (a%7==0)
		{
			t+=a;
			j++;
		}
	}
	printf ("So phan tu nam trong khoang(35,70) la %d.\n",i);
	if (j==0)
		printf ("Khong co so nao chia het cho 7.\n");
	else
		printf ("Trung binh cong cac so chia het cho 7 la %d.\n",t/j);
	return 0;
}
