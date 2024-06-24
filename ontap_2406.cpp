#include<stdio.h>
#include<stdlib.h>


#define MAX 100

void docmatran(int n, int matrix[MAX][MAX], FILE *f){
	for(int i = 0; i<n;i++){
			for(int j = 0; j<n;j++){
		fscanf(f,"%d", &matrix[i][j]);
	}
	}
}
void xuatmatran(int n, int matrix[MAX][MAX]){
	
}

int main (){
	FILE *f;
	int n;
	int matrix[100][100];
	char filename[100];
	printf("Moi nhap ten tep: ");
	scanf("%s", filename);
	f = fopen(filename, "rt");
	if(f == null){
		printf("Tep khong ton tai.\n");
		return;
	}
	fscanf(f, "%d", &n);
		docmatran(n,matrix, f);
}
