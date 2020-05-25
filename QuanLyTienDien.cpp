#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

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
        cout<<"\nNhap so luong ho gia dinh: "; cin>>n;
    }while(n <= 0);
    GD a[n];
    while(true){
        system("cls");
        cout<<"******************************************\n";
        cout<<"**    CHUONG TRINH QUAN LY TIEN DIEN    **\n";
        cout<<"**      1. Nhap du lieu                 **\n";               
        cout<<"**      2. Xuat File                    **\n";
        cout<<"**      0. Thoat                        **\n";
        cout<<"******************************************\n";
        cout<<"**       Nhap lua chon cua ban          **\n";
        cin>>key;
        switch(key){
            case 1:
                cout<<"\nBan da chon nhap du lieu!";
                Input(a, n);
                cout<<"\nBan da nhap thanh cong!";
                daNhap = true;
                cout<<"\nBam phim bat ky de tiep tuc!";
                getch();
                break;
            case 2:        
                if(daNhap){
                    cout<<"\nBan da chon xuat du lieu!";
                    exportfile(a, n, fileName);
                }else{
                    cout<<"\nNhap DS SV truoc!!!!";
                }
                printf("\nXuat DSSV thanh cong vao file %s!", fileName);
                cout<<"\nBam phim bat ky de tiep tuc!";
                getch();
                break;
            case 0:
                cout<<"\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout<<"\nKhong co chuc nang nay!";
                cout<<"\nBam phim bat ky de tiep tuc!";
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
    cout<<"\n\tNhap ten chu ho: "; fflush(stdin); gets(gd.tenchuho);
    cout<<"\tNhap loai ho [1. Gia dinh/2. Kinh doanh/ 3. San xuat] ?: ";  cin >> gd.loaiho;
   	cout<<"\tNhap chi so dau: "; cin>> gd.chisodau;
    cout<<"\tNhap chi so cuoi: "; cin>> gd.chisocuoi;    
    tinhtien(gd);
}
    
void Input(GD a[], int n){
    cout<<"\n____________________________________\n";
    for(int i = 0; i< n; ++i){
        printf("\nNhap ho gia dinh thu %d:", i+1);
        nhap(a[i]);
    }
    cout<<"\n____________________________________\n";
}
void exportfile(GD a[], int n, char fileName[]){
    FILE * fp;
    fp = fopen (fileName,"a");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%-20s%-15s%-8d%-8d%10d\n", a[i].tenchuho,a[i].loaiHo,a[i].chisodau,a[i].chisocuoi,a[i].cost);
    }
    fclose (fp);
}





