#include<stdio.h>
#include<conio.h>
// 522 Khai báo kiểu dữ liệu để biểu diễn thông tin của 1 hỗn số

struct HonSo
{
    int Nguyen;
    int Tu;
    int Mau;
};
typedef struct HonSo HONSO;

void NhapHonSo(HONSO &);
void XuatHonSo(HONSO);
HONSO RutGonHonSo(HONSO);

HONSO TinhTong2HonSo(HONSO, HONSO);
HONSO TinhHieu2HonSo(HONSO, HONSO);
HONSO TinhTich2HonSo(HONSO, HONSO);
HONSO TinhThuong2HonSo(HONSO, HONSO);

bool KiemTraHonSoToiGian(HONSO);
void QuiDong2HonSo(HONSO, HONSO);

// 523 Nhập hỗn số
void NhapHonSo(HONSO &hs)
{
    printf("\nNhap phan nguyen: ");
    scanf("%d", &hs.Nguyen);

    printf("\nNhap tu so: ");
