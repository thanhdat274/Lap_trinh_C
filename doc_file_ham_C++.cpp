// 07/05/2024 doc file txt code C++
// dùng ham
// tim gia tri lon nhat cua day so va in ra tep output.txt
#include <stdio.h>

using namespace std;

void nhap(int n, int a[], FILE *f){
	for(int i=0; i<n; i++){
		fscanf(f, "%d", &a[i]);
	}
}

void xuat(int n, int a[]){
	for(int i = 0; i<n;i++){
		printf("%d ", a[i]);
	}	
}

int demAm(int n, int a[]){
	int d = 0;
	for(int i = 0; i<n;i++){
		if(a[i]<0){
			d++;
		}
	}
	return d;
}

int soLonNhat(int n, int a[]){
	int max= a[0];
	for(int i=0; i<n; i++){
		if(a[i]>max){
			max = a[i];
		}
	}
	return max;
}

// dem va in ra tep output.txt cac bo 3 so lien tiep lap thanh cap so cong 
// (khong xet thu tu) 4 8 6, 4 6 8, 6 4 8. 6 8 4  
void boBaSo(int n, int a[], FILE *f){
	int d =0;
	for(int i = 0; i<n-2; i++){
		int so1= a[i];
		int so2 = a[i+1];
		int so3 = a[i+2];
		if(so1+so2 == 2*so3 || so1+so3 == 2*so2 || so2+so3 == 2*so1){
			fprintf(f, "\n%d %d %d", so1, so2,so3);
			d++;
		}
	}
	fprintf(f, "\n SO cac cap la: %d", d);
}

int main(){
	FILE *f, *fo;
	int n;
	int a[100];
	// mo file
	f = fopen("input.txt", "rt");
	// output file
	fo = fopen("output.txt","wt");
	fscanf(f, "%d", &n);
	nhap(n, a, f);
	xuat(n,a);
	fprintf(fo, "\nCac phan tu am la: %d", demAm(n,a));
	fprintf(fo, "\nSo lon nhat: %d", soLonNhat(n,a));
	boBaSo(n,a,fo);
}


