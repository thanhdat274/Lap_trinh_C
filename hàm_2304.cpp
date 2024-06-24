// ham tiep ngay 23-04-2024
#include <iostream>
#include <vector>
// xây dung ham thuc hien cac cong viec sau:
//- nhap vao 1 day so nguyen co n phan tu
//- in day so ra man hinh
//- dem các phan tu co gia tri lon hon x voi x nhap tu ban phim 
//- tinh tong cac phan tu co gia tri am trong day 
//- kiem tra xem day co phai la day tang dan hay khong

using namespace std;

//- nhap vao 1 day so nguyen co n phan tu
void nhapDaySo(int a[], int n) {
    cout << "Nhap vao day so nguyen co " << n << " phan tu:\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

//- in day so ra man hinh
void inDaySo(int a[], int n) {
    cout << "Day so vua nhap la:\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}

//- dem các phan tu co gia tri lon hon x voi x nhap tu ban phim 
int demSoLonHonX(int a[], int n, int x){
	int count = 0;
	for (int i =0; i<n; i++){
		if(a[i]>x){
			count++;
		}
	}
	return count;
}

//- tinh tong cac phan tu co gia tri am trong day 
int tinhTong(int a[], int n){
	int sum= 0;
	for(int i=0; i<n;i++){
		if(a[i]<0){
			sum+=a[i];
		}
	}
	return sum;
}

//- kiem tra xem day co phai la day tang dan hay khong
bool kiemTraDayTangDan(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] >= a[i + 1]) {
            return false;
        }
    }
    return true;
}

int main(){
	int n, x;
	do{
		cout<<"nhap vao so phan tu cua day so: ";
		cin>>n;
	}
	while(n<=1);
    int a[1000];
    nhapDaySo(a, n);
    inDaySo(a, n);
	cout<<"nhap vao phan tu x: ";
	cin>>x;
	cout << "\nSo phan tu lon hon "<<x<<" la: "<<  demSoLonHonX(a, n, x);
	cout<< "\nTong cac phan tu co gia tri am trong day so: "<<tinhTong(a,n);
	if(kiemTraDayTangDan(a, n)) cout<<"\nDay so là day tang dan";
	else cout<<"\nDay so khong la day tang dan";
	return 0;
}

