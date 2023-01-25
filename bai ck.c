#include <stdio.h>
#include <string.h>
typedef struct vacxin
{
	char Name[31];
	char cccd[13];
	char sdt[15];
	float nhietdo;
	int ha1,ha2;	
}VX;
VX vx[10000];
int n=0;
float sum=0;
void correct(char s[])
{
	int i;
	for (i=0;i<strlen(s);i++)
	{
		if (i==0||s[i-1]==' ')
		{
			if (s[i]>='a'&&s[i]<='z')
				s[i]='A'+(s[i]-'a');
		}
		else if (s[i]>='A'&&s[i]<='Z')
			s[i]='a'+(s[i]-'A');
		if (s[i]=='\n')
			s[i]='\0';
	}
}
void in()
{
	int m,i; 
	printf("1. Nhap thong tin nguoi den tiem vacxin\n");
	do
	{
		printf("So luong nguoi den tiem nhap moi: ");
		scanf("%d",&m);
		if (m<=0)
			printf("So luong nguoi den tiem khong hop le. Vui long nhap lai.\n");
	}
	while (m<=0);
	for (i=n;i<n+m;i++)
	{
		fflush(stdin);
		printf("Ten nguoi den tiem: ");
		fgets(vx[i].Name,30,stdin);
		correct(vx[i].Name);
		fflush(stdin);
		printf("CCCD: ");
		fgets(vx[i].cccd,12,stdin);
		correct(vx[i].cccd);
		fflush(stdin);
		printf("So dien thoai: ");
		fgets(vx[i].sdt,30,stdin);
		correct(vx[i].sdt);
		printf("Nhiet do: ");
		scanf("%f",&vx[i].nhietdo);
		printf("Huyet ap tam thu: ");
		scanf("%d",&vx[i].ha1);
		printf("Huyet ap tam truong: ");
		scanf("%d",&vx[i].ha2);
		printf("\n");
	}
	n+=m;
}
void out()
{
	int i;
	printf("2. In thong tin cac nguoi den tiem\n");
	printf("Danh sach nguoi den tiem:\n\n");
	printf("STT    Ten                               CCCD            SDT\n");
	for (i=0;i<n;i++)
	{
		printf("%-3d    %-30s    %-12s    %-30d\n",i+1,vx[i].Name,vx[i].cccd,vx[i].sdt);
	}
}
void seek()
{
	char sdt[12];
	int i, j=1;
	printf("3. Tim kiem theo so dien thoai\n");
	printf("Nhap SDT can tim: ");
	fflush(stdin);
	fgets(sdt,12,stdin);
	correct(sdt);
	for (i=0;i<n;i++)
	{
		if (strcmp(sdt,vx[i].sdt)==0)
		{
			printf("Tim thay nguoi den tiem co sdt %d:\n\n",sdt);
			printf("STT    Ten                               CCCD            SDT          Nhiet do      Huyet ap tam thu        Huyet ap tam truong\n");	
			printf("%-3d    %-30s    %-12s    %-30d    %3.1f      %-10d      %-10d       %-10d\n\n",j,vx[i].Name,vx[i].cccd,vx[i].sdt,vx[i].nhietdo,vx[i].ha1,vx[i].ha2);
			break;
		}
	}
		if (i==n)
			printf("Khong tim thay nguoi den tiem co SDT %d.\n\n",sdt);
}
void search()
{
	char cccd[13];
	int i, j=1;
	printf("3. Tim kiem theo CCCD\n");
	printf("Nhap CCCD can tim: ");
	fflush(stdin);
	fgets(cccd,12,stdin);
	correct(cccd);
	for (i=0;i<n;i++)
	{
		if (strcmp(cccd,vx[i].cccd)==0)
		{
			printf("Tim thay nguoi den tiem co CCCD %d:\n\n",cccd);
			printf("STT    Ten                               CCCD            SDT          Nhiet do      Huyet ap tam thu        Huyet ap tam truong\n");	
			printf("%-3d    %-30s    %-12s    %-30d    %3.1f      %-10d      %-10d       %-10d\n\n",j,vx[i].Name,vx[i].cccd,vx[i].sdt,vx[i].nhietdo,vx[i].ha1,vx[i].ha2);
			break;
		}
	}
		if (i==n)
			printf("Khong tim thay sinh vien co CCCD %s.\n\n",cccd);
}
int kiemTraNhietDo(float nhietdo)
{
	if(nhietdo>=36.8&&nhietdo<=38)
		return 1;
	return 0;
}
int kiemTraHuyetAp(int ha1, int ha2)
{
	if (ha1>100&&ha1<130&&ha2>79&&ha2<89)
		return 1;
	return 0;
}
void danhsach()
{
	VX vx[10000];
	VX tmp;
	int i,j;
	printf("5. Nhung nguoi du dieu kien tiem\n");
	printf("Danh sach nguoi den tiem:\n\n");
	printf("STT    Ten                               CCCD            SDT\n");
	for (i=0;i<n;i++)
	{
		if(kiemTraNhietDo(vx[i].nhietdo)==1&&kiemTraHuyetAp(vx[i].ha1,vx[i].ha2)==1)
			printf("%-3d    %-30s    %-12s    %-30d\n",i+1,vx[i].Name,vx[i].cccd,vx[i].sdt);
	}
}
int main()
{
	int menu;
	do
	{
		do
		{
			printf("---- Menu ----\n");
			printf("1. Nhap thong tin nguoi den tiem\n");
			printf("2. In thong tin cac nguoi den tiem\n");
			printf("3. Tim kiem theo CCCD nguoi den tiem\n");
			printf("4. Tim kiem theo sdt nguoi den tiem\n");
			printf("5. Danh sach nhung nguoi du dieu kien tiem\n");
			printf("6. Thoat\n");
			printf("Chon 1 chuc nang (1 - 6): ");
			scanf("%d",&menu);
			if (menu<1||menu>6)
				printf("Gia tri khong hop le. Vui long chon lai.\n\n");
		}
		while (menu<1||menu>6);
		printf("\n");
		switch(menu)
		{
			case 1: in(); break;
			case 2: out(); break;
			case 3: search(); break;
			case 4: seek(); break;
			case 5: danhsach(); break;
			case 6: printf("6. Thoat\n"); return 0;
		}
	}
	while (menu!=6);
}
