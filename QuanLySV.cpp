#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct SinhVien{
    int stt;
	char hoTen[30];
	char maSV[15];
	float dT1, dT2, dT3, dT4, dTB; 
	int hB;   
};

typedef SinhVien SV;
void nhap(SV &sv);
void Input(SV a[], int n);
void exportfile(SV a[], int n, char fileName[]);

 int main()
{
    int key;
    char fileName[] = "TDIEN.txt";
    int n;
    bool daNhap = false;
    do{
        printf("\nNhap so luong sinh vien: "); scanf("%d", &n);
    }while(n <= 0);
    SV a[n];
    while(true){
        system("cls");
        printf("******************************************\n");
        printf("**    CHUONG TRINH QUAN LY HOC BONG SV    **\n");
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

void tinhDTB(SV &sv){
	sv.dTB = (sv.dT1*2 + sv.dT2*3 + sv.dT3*2 + sv.dT4*3)/10;
}

void tinhHocBong(SV &sv){
	if((sv.dTB >= 9) && (sv.dT1 >= 8.5)){
		sv.hB = 1200000;
	}else if((sv.dTB >= 8) && (sv.dTB < 9)){
		sv.hB = 1000000;
	}else if((sv.dTB >= 7.5) && (sv.dTB < 8)){
		sv.hB = 800000;
	}else sv.hB = 0;
}

void nhap(SV &sv){
    printf("\n\tNhap STT: "); scanf("%d", &sv.stt); 
    printf("\tNhap ho ten: "); fflush(stdin); gets(sv.hoTen);
    printf("\tNhap MSV: "); fflush(stdin); gets(sv.maSV);
    printf("\tNhap diem thi 1: "); scanf("%f", &sv.dT1); 
    printf("\tNhap diem thi 2: "); scanf("%f", &sv.dT2); 
    printf("\tNhap diem thi 3: "); scanf("%f", &sv.dT3); 
    printf("\tNhap diem thi 4: "); scanf("%f", &sv.dT4); 
    tinhDTB(sv);
    tinhHocBong(sv);
    
}
void Input(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap sinh vien thu %d:", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}
void exportfile(SV a[], int n, char fileName[]){
    FILE * fp;
    fp = fopen (fileName,"a");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%-4d%-20s%-12s%-7.2f%-7.2f%-7.2f%-7.2f%-7.2f%-8d%\n", a[i].stt, a[i].hoTen, a[i].maSV, a[i].dT1,a[i].dT2,a[i].dT3,a[i].dT4,a[i].dTB, a[i].hB);
    }
    fclose (fp);
}





