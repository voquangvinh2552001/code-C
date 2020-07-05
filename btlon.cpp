#include<stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
typedef struct NhanVien { 
	char hoten[30];
	char tinh [30];
	int namsinh;
} NhanVien;

void nhap(NhanVien nhanvien[3]) {

	for(int i=0; i<3; i++) {
		fflush(stdin);
		printf("\nNhap sinh vien thu %d: \n",i+1);
		printf("\n Hoten: ");
		gets(nhanvien[i].hoten); 
		printf("\n Tinh: ");
		gets(nhanvien[i].tinh );
		printf("\n Namsinh: ");
		scanf("%d",&nhanvien[i].namsinh );
	}
}

void sapXepHienThi(NhanVien nhanvien[3]) {
	NhanVien temp; 
	for(int i=0; i<3; i++) {
		for(int j=i+1; j<3; j++)
			if(strcmp(nhanvien[i].tinh,nhanvien[j].tinh) < 0) {
				temp=nhanvien[i];
				nhanvien[i]=nhanvien[j];
				nhanvien[j]=temp;
			}
	}
	printf("STT||Hoaten              ||Tinh                ||Namsinh\n");
	for(int i=0; i<3; i++) {
		printf("00%d||%-20s||%-20s||%d\n",i+1,nhanvien[i].hoten,nhanvien[i].tinh,nhanvien[i].namsinh);
	}
}

void timNhanVien(NhanVien nhanvien[3]) {

	char timnv[15];
		fflush(stdin);
		printf("\n Nhap tinh can tim :");
		gets(timnv);
	int t;
		printf("STT||Hoten               ||Tinh                ||Namsinh\n");
	for(int i=0; i<3; i++) {
		t=0;
		if(strcmp(timnv,nhanvien[i].tinh)==0) { 
			printf("00%d||%-20s||%-20s||%d\n",i+1,nhanvien[i].hoten,nhanvien[i].tinh,nhanvien[i].namsinh);
			t=1;
		}
	}
	if(t==0) {
		printf("\nKhong co nhan vien thuoc tinh nay.");
	}
}

int main() {
	FILE *fp;
	NhanVien nhanvien[3];
	system("color a1"); 
	while(1) { 

		int key , m=0;
		system("cls");
		printf("\t\t\t*********************************************************\n");
		printf("\t\t\t**                                                     **\n");
		printf("\t\t\t**           CHUONG TRINH QUAN LY NHAN VIEN            **\n");
		printf("\t\t\t**   1. Nhap du lieu                                   **\n");
		printf("\t\t\t**   2. Sap xep va hien thi thong tin chi              **\n");
		printf("\t\t\t**      tiet cua tung nhan vien theo  tinh tu Z->A     **\n");
		printf("\t\t\t**   3. Tim nhan vien theo tinh                        **\n");
		printf("\t\t\t**   4. Ghi ra tap tin DSSV.txt                        **\n");
		printf("\t\t\t**   5. Thoat                                          **\n");
		printf("\t\t\t**                                                     **\n");
		printf("\t\t\t*********************************************************\n");
		printf("\t\t\t**        Nhap vao lua chon cua ban (1 den 5):         **\n");
		scanf("%d",&key);
		switch(key) {
			case 1:
				nhap(nhanvien);
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;

			case 2:
				sapXepHienThi(nhanvien);
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;

			case 3:
				timNhanVien(nhanvien);
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;

			case 4:
				fp=fopen("C:\\Users\\WELCOME\\Desktop\\DSNV.txt","a+");
				if(fp==NULL) {
					printf("File khong mo duoc");
				}

				for(int i=0; i<3; i++) {
					fprintf(fp,"Nhan vien %d Hoten: %s Tinh:%s Namsinh:%d \n",i+1,nhanvien[i].hoten,nhanvien[i].tinh,nhanvien[i].namsinh);
				}
				fclose(fp); 
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;

			case 5:
				exit(1);
				return 0;
		}
	}
	return 0;
}
