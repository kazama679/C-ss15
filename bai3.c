#include <stdio.h>
#include <string.h>
struct SinhVien{
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};
struct SinhVien danhSachSinhVien[100];
int soLuongSinhVien = 0;
void nhapThongTin(struct SinhVien *sv){
    printf("Nhap ho va ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = '\0';
    scanf("%s",&sv->hoTen);	
    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    printf("Nhap so dien thoai: ");
    fgets(sv->soDienThoai, sizeof(sv->soDienThoai), stdin);
    sv->soDienThoai[strcspn(sv->soDienThoai, "\n")] = '\0';
    scanf("%s", sv->soDienThoai);
    printf("Nhap email: ");
    fgets(sv->email, sizeof(sv->email), stdin);
    sv->email[strcspn(sv->email, "\n")] = '\0';
    scanf("%s", sv->email);
}
void themSinhVien(){
    if (soLuongSinhVien < 100){
        struct SinhVien sv;
        nhapThongTin(&sv);
        danhSachSinhVien[soLuongSinhVien++] = sv;
        printf("Da them sinh vien thanh cong.\n");
    } else{
        printf("Danh sach da day, khong the them sinh vien.\n");
    }
}
void inThongTinSinhVien(){
    printf("\nDanh sach sinh vien:\n");
    printf("%s%-20s%-5s%-15s%s\n","STT|", "Ho va Ten|", "|Tuoi|", "|So Dien Thoai|", "|Email|");
    for (int i = 0; i < soLuongSinhVien; i++) {
        printf("%d   %-21s%-5d%-15s%s\n",i+1, danhSachSinhVien[i].hoTen, danhSachSinhVien[i].tuoi,
               danhSachSinhVien[i].soDienThoai, danhSachSinhVien[i].email);
    }
}
int main(){
    int choice;
    do{
        printf("\nMenu:\n");
        printf("1. Them sinh vien\n");
        printf("2. In danh sach sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                themSinhVien();
                break;
            case 2:
                inThongTinSinhVien();
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}
