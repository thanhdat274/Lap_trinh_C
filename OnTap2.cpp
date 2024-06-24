#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char MNV[10];
    char HT[50];
    int LUONG;
    char PHONG[2];
} NhanVien;

void doc(FILE *f, NhanVien a[], int *n) {
    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%s %s %d %s", a[i].MNV, a[i].HT, &a[i].LUONG, a[i].PHONG);
    }
}

void phong(FILE *fo,NhanVien a[], int n, const char* phong) {
    fprintf(fo,"danh sach nhan vien %s:\n", phong);
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].PHONG, phong) == 0) {
            fprintf(fo,"MNV: %s, HT: %s, LUONG: %d\n", a[i].MNV, a[i].HT, a[i].LUONG);
        }
    }
    fprintf(fo,"\n");
}

void phong(NhanVien a[], int n, const char* phong) {
    printf("danh sach nhan vien %s:\n", phong);
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].PHONG, phong) == 0) {
            printf("MNV: %s, HT: %s, LUONG: %d\n", a[i].MNV, a[i].HT, a[i].LUONG);
        }
    }
    printf("\n");
}

float luongTB(NhanVien a[], int n, const char* phong) {
    int tong = 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].PHONG, phong) == 0) {
            tong += a[i].LUONG;
            d++;
        }
    }
    if (d == 0) {
        return 0.0;
    }
    return (float)tong /d;
}

int compare(const void *a, const void *b) {
    NhanVien *nv1 = (NhanVien *)a;
    NhanVien *nv2 = (NhanVien *)b;
    return nv2->LUONG - nv1->LUONG;
}

int main() {
    FILE *f,*fo;
    int n;
    NhanVien a[100];
    f = fopen("input2.txt", "r+");
    fo = fopen("kq.txt", "wt");
   // if (f == NULL) {
   //     printf("khong the mo file.\n");
   //     return 1;
   // }

    doc(f, a, &n);
    float min = luongTB(a, n, "A");
char Pmin[2] = "A";
const char* DSphong[] = {"B", "C"};

for (int i = 0; i < sizeof(DSphong) / sizeof(DSphong[0]); i++) {
    float LP = luongTB(a, n, DSphong[i]);
    if (LP < min) {
        min = LP;
        strcpy(Pmin, DSphong[i]);
    }
}
printf("phong %s nhap nhat voi luong trung bình %.2f\n", Pmin, min);
fprintf(fo,"phong %s nhap nhat voi luong trung bình %.2f\n", Pmin, min);

	qsort(a, n, sizeof(NhanVien), compare);
	phong(a, n, "A");
    phong(a, n, "B");
    phong(a, n, "C");
    
    phong(fo,a, n, "A");
    phong(fo,a, n, "B");
    phong(fo,a, n, "C");
    
    fclose(fo);
    fclose(f);
    return 0;
}
