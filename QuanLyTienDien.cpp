#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>
struct hogiadinh{
    char tenchuho[30];
    int loaiho;
    char loaiHo[30]; // dung de chuyen doi loai ho thanh chu
    int chisodau,chisocuoi;
    int cost;    
};
typedef hogiadinh GD;
void nhap(GD &gd);
void Input(GD a[], int n);
void exportfile(GD a[], int n, char fileName[]);
void chuyenDoi();
 int main(){
    int key;
    char fileName[] = "D:\\TDIEN.txt";
    int n;
    bool daNhap = false;
    do{
        printf("\nNhap so luong ho gia dinh: "); scanf("%d", &n);
    }while(n <= 0);
    GD a[n];
    while(true){
        system("cls");
        printf("******************************************\n");
        printf("**    CHUONG TRINH QUAN LY TIEN DIEN    **\n");
        printf("**      1. Nhap du lieu                 **\n");               
        printf("**      2. Xuat File                    **\n");
        printf("**      0. Thoat                        **\n");
        printf("******************************************\n");
        printf("**       Nhap lua chon cua ban          **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap du lieu!");
                Input(a, n);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:        
                if(daNhap){
                    printf("\nBan da chon xuat du lieu!");
                    exportfile(a, n, fileName);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nXuat DSSV thanh cong vao file %s!", fileName);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}
 void tinhtien(GD &gd){
 	
 	if(gd.loaiho == 1){
 		gd.cost = 450 * (gd.chisocuoi - gd.chisodau);
 		strcpy(gd.loaiHo, "Gia dinh");
	 }
	 if(gd.loaiho == 2){
	 	gd.cost = 600 * (gd.chisocuoi - gd.chisodau);
	 	strcpy(gd.loaiHo, "Kinh doanh");
	 }
	 if(gd.loaiho == 3){
	 	gd.cost = 500 * (gd.chisocuoi - gd.chisodau);
	 	strcpy(gd.loaiHo, "San xuat");
	 }
    
}

void nhap(GD &gd){
    printf("\n\tNhap ten chu ho: "); fflush(stdin); gets(gd.tenchuho);
    printf("\tNhap loai ho [1. Gia dinh/2. Kinh doanh/ 3. San xuat]?: "); scanf("%d", &gd.loaiho);
   	printf("\tNhap chi so dau: "); scanf("%d", &gd.chisodau);
    printf("\tNhap chi so cuoi: "); scanf("%d", &gd.chisocuoi);    
    tinhtien(gd);
}
    
void Input(GD a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap ho gia dinh thu %d:", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}
void exportfile(GD a[], int n, char fileName[]){
    FILE * fp;
    fp = fopen (fileName,"a");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%-20s%-15s%-8d%-8d%10d\n", a[i].tenchuho,a[i].loaiHo,a[i].chisodau,a[i].chisocuoi,a[i].cost);
    }
    fclose (fp);
}





