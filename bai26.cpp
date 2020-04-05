#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct ThongTin{
	char loaiHo[10];
	int chiSoDau;
	int chiSoCuoi;
	int heSo;
	float thanhTien = 0;
};

typedef ThongTin TT;
	void nhap(TT &tt);
	void nhapDs(TT a[], int n);
	void xuat(TT tt);
	void xuatDs(TT a[], int n);
	void tinhGiaTien(TT &tt);
	
	
void tinhGiaTien(TT &tt){
	tt.thanhTien = (float)(tt.chiSoCuoi - tt.chiSoDau) * tt.heSo * 450;
}
	
void nhap(TT &tt){
	printf("\tLoai ho: "); fflush(stdin); gets(tt.loaiHo);
	printf("\tChi so dau: "), scanf("%d", &tt.chiSoDau);
	printf("\tChi so cuoi: "), scanf("%d", &tt.chiSoCuoi);
	printf("\tHe so: "), scanf("%d", &tt.heSo);
	tinhGiaTien(tt);
}
void nhapDs(TT a[], int n){
	printf("\n_____________________________\n");
	for(int i = 0; i < n; i++){
		printf("Loai ho thu %d: \n", i+1);
		nhap(a[i]);
	}
}
void xuat(TT tt){
	printf("%-10s %-15d %-15d %-10d %-15.2f", tt.loaiHo, tt.chiSoDau, tt.chiSoCuoi, tt.heSo, tt.thanhTien);
}
void xuatDs(TT a[], int n){
	printf("\n_____________________________________________________________________\n");
	printf("%-10s %-15s %-15s %-10s %-15s", "Loai ho", "Chi so dau", "Chi so cuoi", "He so", "Thanh Tien");
	printf("\n");
	for(int i = 0; i < n; i++){
		xuat(a[i]);
		printf("\n");
	}
}
	
int main(){
	int n;
	printf("\nNhap so luong DS muon them: "); scanf("%d", &n);
	TT a[n];
	printf("-----------Nhap thong tin DS---------");
	nhapDs(a, n);
	printf("-----------DANH SACH BAN DA NHAP THANH CONG!-----------");
	xuatDs(a, n);
}
