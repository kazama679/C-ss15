#include<stdio.h>
#include<string.h>
struct Books{
    char tenSach[100];
    char maSach[15];
    char tacGia[50];
    char giaTien[15];
    char theLoai[30];
};

struct Books danhSachBook[100];
int soLuongSach = 0;
void nhapThongTin(struct Books *b){
    printf("Nhap ten sach: ");
    fgets(b->tenSach, sizeof(b->tenSach), stdin);
    b->tenSach[strcspn(b->tenSach, "\n")] = '\0';
    scanf("%s",&b->tenSach);	
    printf("Nhap tac gia: ");
    fgets(b->tacGia, sizeof(b->tacGia), stdin);
    b->tacGia[strcspn(b->tacGia, "\n")] = '\0';
    scanf("%s",&b->tacGia);
    printf("Nhap ma sach : ");
    fgets(b->maSach, sizeof(b->maSach), stdin);
    b->maSach[strcspn(b->maSach, "\n")] = '\0';
    scanf("%s",&b->maSach);
    printf("Nhap gia tien: ");
    fgets(b->giaTien, sizeof(b->giaTien), stdin);
    b->giaTien[strcspn(b->giaTien, "\n")] = '\0';
    scanf("%s",&b->giaTien);
    printf("Nhap the loai: ");
    fgets(b->theLoai, sizeof(b->theLoai), stdin);
    b->theLoai[strcspn(b->theLoai, "\n")] = '\0';
    scanf("%s",&b->theLoai);
}

void inThongTinBooks(){
    printf("Thong tin cua sach:\n");
    printf("%-4s%-20s%-15s%-15s%-15s%-15s\n", "STT|", "Ten sach|", "|Tac gia|", "|ma sach|", "|gia tien|", "|the loai|");
    for(int i = 0; i < soLuongSach; i++){
        printf("%-4s%-21s%-15s%-15s%-15s%-15s\n", i + 1, danhSachBook[i].tenSach, danhSachBook[i].tacGia, danhSachBook[i].maSach, danhSachBook[i].giaTien, danhSachBook[i].theLoai);
    }
}

void xuatBooks(int index){
    printf("Ten sach: %s\n", danhSachBook[index].tenSach);
    printf("Tac gia: %s\n", danhSachBook[index].tacGia);
    printf("Ma sach: %s\n", danhSachBook[index].maSach);
    printf("Gia tien: %s\n", danhSachBook[index].giaTien);
    printf("The Loai: %s\n", danhSachBook[index].theLoai);	
}

void themSachVaoViTri(int viTri){
    if(soLuongSach < 100 && viTri >= 0 && viTri <= soLuongSach){
        struct Books b;
        nhapThongTin(&b);
        for(int i = soLuongSach; i > viTri; i--){
            danhSachBook[i] = danhSachBook[i - 1];
        }
        danhSachBook[viTri] = b;
        soLuongSach++;
        printf("Da them sach thanh cong.\n");
    } else{
        printf("Vi tri khong hop le hoac danh sach da day, khong the them sach.\n");
    }
}

void xoaSachTheoMaSach() {
    char maSachXoa[15];
    printf("Nhap ma sach can xoa: ");
    scanf("%s", maSachXoa);
    for(int i = 0; i < soLuongSach; i++){
        if(strcmp(danhSachBook[i].maSach, maSachXoa) == 0){
            for (int j = i; j < soLuongSach - 1; j++) {
                danhSachBook[j] = danhSachBook[j + 1];
            }
            soLuongSach--;
            printf("Da xoa sach thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma sach %s.\n", maSachXoa);
}

void capNhatTheoMaSach() {
    char maSachCapNhat[15];
    printf("Nhap ma sach can cap nhat: ");
    scanf("%s", maSachCapNhat);
    for(int i = 0; i < soLuongSach; i++){
        if(strcmp(danhSachBook[i].maSach, maSachCapNhat) == 0){
            printf("Nhap thong tin moi cho sach:\n");
            nhapThongTin(&danhSachBook[i]);
            printf("Da cap nhat thong tin sach thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma sach %s.\n", maSachCapNhat);
}

void sapXepTheoGia(int tangGiam){
    struct Books temp;
    for(int i = 0; i < soLuongSach - 1; i++){
        for(int j = 0; j < soLuongSach - i - 1; j++){
            if(tangGiam == 1 && strcmp(danhSachBook[j].giaTien, danhSachBook[j + 1].giaTien) > 0){
                temp = danhSachBook[j];
                danhSachBook[j] = danhSachBook[j + 1];
                danhSachBook[j + 1] = temp;
            } else if(tangGiam == 2 && strcmp(danhSachBook[j].giaTien, danhSachBook[j + 1].giaTien) < 0){
                temp = danhSachBook[j];
                danhSachBook[j] = danhSachBook[j + 1];
                danhSachBook[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep sach theo gia %s.\n", (tangGiam == 1) ? "tang" : "giam");
}

void timKiemTheoTenSach(){
    char tenSachCanTim[100];
    printf("Nhap ten sach can tim: ");
    scanf(" %[^\n]", tenSachCanTim);
    int timThay = 0;
    for(int i = 0; i < soLuongSach; i++){
        if(strstr(danhSachBook[i].tenSach, tenSachCanTim) != NULL){
            xuatBooks(i);
            timThay = 1;
        }
    }
    if(!timThay){
        printf("Khong tim thay sach voi ten %s.\n", tenSachCanTim);
    }
}

void timKiemTheoKhoangGia(){
    char giaMin[15], giaMax[15];
    printf("Nhap gia thap nhat: ");
    scanf("%s", giaMin);
    printf("Nhap gia cao nhat: ");
    scanf("%s", giaMax);
    int timThay = 0;
    for(int i = 0; i < soLuongSach; i++){
        if(strcmp(danhSachBook[i].giaTien, giaMin) >= 0 && strcmp(danhSachBook[i].giaTien, giaMax) <= 0){
            xuatBooks(i);
            timThay = 1;
        }
    }
    if(!timThay){
        printf("Khong tim thay sach trong khoang gia tu %s den %s.\n", giaMin, giaMax);
    }
}

void printMenu(){
    printf("            MENU            \n");
    printf("1. Nhap so luong va thong tin sach\n");
    printf("2. Hien thi thong tin sach\n");
    printf("3. Them sach vao vi tri\n");
    printf("4. xoa sach theo ma sach\n");
    printf("5. cap nhat thong tin theo ma sach\n");
    printf("6. sap xep theo gia(tang/giam)\n");
    printf("7. tim kiem sach theo ten sach\n");
    printf("8. tim kiem sach theo khoang gia\n");
    printf("9. Thoat\n");
}

int main(){
    int choice;
    do{
        printMenu();
        printf("Lua chon chuc nang:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d", &soLuongSach);
                for(int i= 0; i < soLuongSach;i++){
                	if (soLuongSach < 100){
                    	struct Books b;
                    	nhapThongTin(&b);
                    	danhSachBook[i] = b;
                    	printf("Da them sach thanh cong.\n");
                	} else {
                    	printf("Danh sach da day, khong the them sach.\n");
                	}
				}
                break;
            case 2:
            	for(int i=0;i<soLuongSach;i++){
            		if(soLuongSach < 100){
            			printf("Thong tin sach %d:\n",i+1);
            			xuatBooks(soLuongSach - 1);
					}
				}
                break;
            case 3:
            	printf("Nhap vi tri muon them sach: ");
                int viTri;
                scanf("%d", &viTri);
                themSachVaoViTri(viTri);
                break;
            case 4:
                xoaSachTheoMaSach();
                break;
            case 5:
                capNhatTheoMaSach();
                break;
            case 6:
                printf("Chon kieu sap xep (1: tang, 2: giam): ");
                int sapXepChoice;
                scanf("%d", &sapXepChoice);
                sapXepTheoGia(sapXepChoice);
                break;
            case 7:
                timKiemTheoTenSach();
                break;
            case 8:
                timKiemTheoKhoangGia();
                break;
            case 9:
                printf("Thoat:\n");
                inThongTinBooks();
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 9);
    return 0;
}
