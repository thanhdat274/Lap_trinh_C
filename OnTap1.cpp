#include <stdio.h>
#include <stdlib.h>

void doc(FILE *f, int n, int a[]){
    for (int i = 0; i < n; i++){
        fscanf(f, "%d", &a[i]);
    }
}

void xuat(int n, int a[]){
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int timMax(int n, int a[]){
    int max = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
void sapXepGiamDan(int n, int a[]){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] < a[j]){
                int dem = a[i];
                a[i] = a[j];
                a[j] = dem;
            }
        }
    }
}

int main(){
    FILE *f;
    int n, m;
    int *a;
    int *b;

    f = fopen("input1.txt", "r+");
    if (f == NULL){
        printf("không the mo tep.\n");
        return 1;
    }

    fscanf(f, "%d %d", &n, &m);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(m * sizeof(int));

    if (a == NULL || b == NULL){
        printf("khong du bo nho.\n");
        fclose(f);
        return 1;
    }

    doc(f, n, a);
    doc(f, m, b);
    xuat(n, a);
    printf("\n");
    xuat(m, b);
    printf("\ngia tri lon nhat cua a: %d", timMax(n, a));
    printf("\ngia tri lon nhat cua b: %d", timMax(m, b));
    sapXepGiamDan(n, a);
    printf("\nday a giam dan: ");xuat(n, a);
    sapXepGiamDan(m, b);
    printf("\nday b giam dan: ");xuat(m, b);
    free(a);
    free(b);
    fclose(f);
    return 0;
}
