#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void docmatran(int rows, int col, FILE *f,  int ***matrix){
    *matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            fscanf(f, "%d", &(*matrix)[i][j]);
        }
    }
}

// in ra ma tran
void xuatmatran(int rows,int col, int **matrix){
	printf("Du lieu ma tran trong tep: \n");
	 for (int i = 0; i < rows; i++) {
        
        for (int j = 0; j < col; j++) {
            	printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }	
}

double avgMaTran(int rows, int col, int **matrix){
	int tong = 0;
	int dem = 0;
	for(int i =0 ; i<rows; i++){
		if(i%2 == 1) continue;
		for(int j =0; j<col;j++){
			if(matrix[i][j]>0){
					tong += matrix[i][j];
					dem++;
			}
		
		}
	}
	 return dem == 0 ? 0 : (double)tong / dem;
}

int main(){
	FILE *f;
	int rows, col;
	int **matrix;
		char fileName[100];
	printf("Nhap ten tep matran_2105.txt \n");
	printf("Nhap ten tep: ");
	scanf("%s", fileName);
	f=fopen(fileName, "rt");
	if (f == NULL) {
        printf("Tep khong ton tai.\n");
        return 1;
    }
 
	fscanf(f, "%d %d", &rows, &col);
	docmatran(rows, col, f, &matrix);
	xuatmatran(rows, col, matrix);
	
	// yc 2 tim trung bình cong cac phan tu duong ma thuoc cac hang  le ma tran
	printf("\n Trugn binh cong cac phan tu duong ma thuoc ca hang le ma tran la: %.2f", 	avgMaTran(rows, col, matrix));
	
	
	// Gi?i phóng b? nh?
	for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
	fclose(f);
}
