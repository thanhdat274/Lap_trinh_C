#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// doc ma tran
void docmatran(int n, int matrix[MAX][MAX], FILE *f){
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &matrix[i][j]);
        }
    }
}
// in ra ma tran
void xuatmatran(int n, int matrix[MAX][MAX]){
	printf("Du lieu ma tran trong tep: \n");
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            	printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }	
}

// yeu cau 1 tinh trung binh cong 
double trungbinhcong(int matrix[MAX][MAX], int n ){
	  int sum = 0;
    int count = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + j >= n) {
                sum += matrix[i][j];
                count++;
            }
        }
    }
    return count == 0 ? 0 : (double)sum / count;
}

// yeu cau 2: kiem tra xem ma tran A có là ma tran tam giac khong
bool laTamGiacTren(int matrix[MAX][MAX], int n ){
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

// yeu cau 3 ma tran doi xung ko
bool laMaTranDoiXung(int matrix[MAX][MAX], int n ){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}
// yeu cau 4 tinh tong tung hang cho biet hang nào tong lon nhat
void tinhTongTheoHang( int matrix[MAX][MAX], int n, int** rowSums, int* maxRowIndex) {
    *rowSums = (int*)malloc(n * sizeof(int));
    int maxSum = -1;
    for (int i = 0; i < n; ++i) {
        (*rowSums)[i] = 0;
        for (int j = 0; j < n; ++j) {
            (*rowSums)[i] += matrix[i][j];
        }
        if ((*rowSums)[i] > maxSum) {
            maxSum = (*rowSums)[i];
            *maxRowIndex = i;
        }
    }
}

int main(){
	FILE *f;
	int n;
	int matrix[MAX][MAX];
	char fileName[100];
	printf("Ten tep matran.txt \n");
	printf("Nhap ten tep: ");
    scanf("%s", fileName);
	f = fopen(fileName, "rt");
	fscanf(f, "%d", &n);
	docmatran(n,matrix,f );
	xuatmatran(n, matrix);
    if (f == NULL) {
        printf("Tep khong ton tai.\n");
        return 1;
    }
    fclose(f);
	printf("\nTrung binh cong cac phan tu nam duoi duong cheo phu cua ma tran A: %.2f\n", trungbinhcong(matrix, n));
	bool matranTamGiac = laTamGiacTren(matrix, n);
   	printf("Ma tran tam giac: %s\n", (matranTamGiac ? "Co" : "Khong"));
   	bool maTranDoiXung = laMaTranDoiXung(matrix, n);
   	printf("Ma tran doi xung: %s\n",(maTranDoiXung ? "Co" : "Khong"));
    int* rowSums;
    int maxRowIndex;
    tinhTongTheoHang(matrix, n, &rowSums, &maxRowIndex);
    for (int i = 0; i < n; i++) {
        printf("Tong cua hang %d la: %d\n", i, rowSums[i]);
    }
    printf("Hang co tong lon nhat: %d\n", maxRowIndex);
}
