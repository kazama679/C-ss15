#include <stdio.h>
struct SinhVien{
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};
void nhapSinhVien(struct SinhVien *sv){
    printf("Nhap ho ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    printf("Nhap so dien thoai: ");
    scanf("%s", sv->soDienThoai);
    printf("Nhap email: ");
    scanf("%s", sv->email);
}
void xuatSinhVien(const struct SinhVien *sv){
    printf("\nThong tin sinh vien:\n");
    printf("Ho ten: %s", sv->hoTen);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("So dien thoai: %s\n", sv->soDienThoai);
    printf("Email: %s\n", sv->email);
}
int main(){
    struct SinhVien sv;
    nhapSinhVien(&sv);
    xuatSinhVien(&sv);
    return 0;
}
