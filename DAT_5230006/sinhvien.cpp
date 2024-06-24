#include <stdio.h>
#include <string.h>

typedef struct {
    char HOTEN[10];
    char QUEQUAN[50];
    char HOCLUC[2];
} SinhVien;

void doc(FILE *f, SinhVien a[], int *n) {
    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%s %s %s", a[i].HOTEN, a[i].QUEQUAN, a[i].HOCLUC);
    }
}

void hocluc(SinhVien a[], int n, const char* hocluc) {
    printf("danh sach sinh vien hoc luc %s:\n", hocluc);
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].HOCLUC, hocluc) == 0) {
            printf("HOTEN: %s, QUEQUAN: %s\n", a[i].HOTEN, a[i].QUEQUAN);
        }
    }
    printf("\n");
}

void timTheoHoTen(SinhVien a[], int n, const char* hoten) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].HOTEN, hoten) == 0) {
            printf("Thong tin sinh vien tim thay:\n");
            printf("HOTEN: %s, QUEQUAN: %s, HOCLUC: %s\n", a[i].HOTEN, a[i].QUEQUAN, a[i].HOCLUC);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ten %s.\n", hoten);
    }
}

int HocLucA(SinhVien a[], int n) {
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].HOCLUC, "A") == 0) {
            d++;
        }
    }
    return d;
}

int main() {
    FILE *f;
    int n;
    SinhVien a[100];
    f = fopen("sinhvien.txt", "r");
    doc(f, a, &n);
    fclose(f);

    hocluc(a, n, "A");
    hocluc(a, n, "B");
    hocluc(a, n, "C");
    hocluc(a, n, "D");
    hocluc(a, n, "E");
    
	char hoten[10];
    printf("Nhap ten sinh vien can tim: ");
    scanf("%9s", hoten);
    timTheoHoTen(a, n, hoten);
    printf("\nSo sinh vien dat hoc luc loai A: %d\n",HocLucA(a, n));
    char hoclucInput[2];
    printf("\nNhap loai hoc luc can tim: ");
    scanf("%1s", hoclucInput);
    hocluc(a, n, hoclucInput);
    return 0;
}
