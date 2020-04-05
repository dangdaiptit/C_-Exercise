#include<stdio.h>
#include<string.h>
#include<conio.h>

struct MatHang{
	char tenHang[30];
    char maHang[15];
    int soLuong;
	float donGia;
	float giaTien = 0;
};

typedef MatHang MH;
	void nhap(MH &mh);
	void nhapN(MH a[], int n);
	void xuat(MH mh);
	void xuatN(MH a[], int n);
	void tinhGiaTien(MH &mh);
	
int main(){
    int n;
    printf("\nNhap so luong mat hang: "); scanf("%d", &n);
    if(n>15){
    	printf("\tError: Gioi han khong qua 15 mat hang!!!");
    	return 0;
	}
    MH a[n];
	nhapN(a, n);
	xuatN(a, n);
	
}
void tinhGiaTien(MH &mh){
	mh.giaTien = (float)mh.donGia*mh.soLuong;
}
void nhap(MH &mh){
	printf("\tNhap ten hang: "); fflush(stdin); gets(mh.tenHang);
    printf("\tNhap ma hang: "); fflush(stdin); gets(mh.maHang);
    printf("\tNhap so luong: "); scanf("%d", &mh.soLuong);
    printf("\tNhap don gia: "); scanf("%f", &mh.donGia);
    tinhGiaTien(mh);
    
}

void nhapN(MH a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        	printf("\nNhap mat hang thu %d: \n", i+1);
        	nhap(a[i]);
    	}
}

void xuat(MH mh){
    printf("%-15s %-10s %-10d %-10.0f %-10.2f", mh.tenHang, mh.maHang, mh.soLuong, mh.donGia, mh.giaTien);
    
}
void xuatN(MH a[], int n){
	printf("\n____________________________________________________\n");
	printf("%-15s %-10s %-10s %-10s %-10s", "Ten hang", "Ma hang", "So luong", "Don gia", "Tong tien" );
	printf("\n");
	for(int i = 0; i < n; i++){
		xuat(a[i]);
		printf("\n");
	}
}
