#include <stdio.h>
void in (int A[], int n)
{
	int i;
	printf("Enter array: ");
	for (i=0;i<n;i++)
		scanf("%d",&A[i]);
}
void process(int A[], int n, int *min, int *count)
{
	int i, tmp;
	*min=A[0]%10;
	*count=0;
	for (i=0;i<n;i++)
	{
		tmp=A[i];
		while (tmp!=0)
		{
			if ((tmp%10)==*min)
				*count++;
			else if ((tmp%10)<*min)
			{
				*min=tmp%10;
				*count=1;
			}
			tmp/=10;
		}
	}
}
void main()
{
	int n;
	int A[100];
	int min, count;
	printf("Enter n: ");
	scanf("%d",&n);
	in (A,n);
	process(A,n,&min,&count);
	printf("The number of the digit %d (smallest digit) in each number in the array is %d\n",min,count);
}
