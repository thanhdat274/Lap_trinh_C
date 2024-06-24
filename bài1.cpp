
#include <iostream>
#include<vector>
#include<cmath>

using namespace std;


int main() {
	// bài 1: 
	int n;
	cout<<"Nhap so phan tu: ";
	cin>>n;
	
	vector<int>arr(n);
	cout<<"nhap day so: ";
	
	for(int i = 1; i<=n; i++){
		cin>>arr[i];
	}
	
	int sum = 0;
	for(int i = 1; i<=n; i++){
		sum+=arr[i];
	}
	cout<<"tong cac phan tu trong day so: "<<sum;
	
	
	
	
// tham khao
//	int n;
//    cout << "Nhap so phan tu cua day so: ";
//    cin >> n;
//
//    double arr[n];
//
//    cout << "Nhap vao cac phan tu cua day so:\n";
//    for (int i = 1; i <= n; i++) {
//        cout << "Phan tu thu " << i << ": ";
//        cin >> arr[i];
//    }
//
//	// cau a
//    double sum = 0;
//    for (int i = 1; i <= n; i++) {
//        sum += arr[i];
//    }
//    
//    // cau b
//    double max = arr[1];
//    for (int i = 2; i <= n; i++) {
//    	if (arr[i] > max) {
//    		max = arr[i];
//		} 
//    }
//    
//    // cau c
//    double x;
//    bool exist = false;
//    cout << "Nhap so x: ";
//    cin >> x;
//    for (int i = 1; i <= n; i++) {
//        if (arr[i] == x) {
//        	exist = true;
//		}
//    }
//
//    cout << "Tong cac phan tu trong day so: " << sum << endl;
//	cout << "So lon nhat: " << max << endl;
//	if (exist) {
//		cout << "Co trong day";
//	} else {
//		cout << "Khong co trong day";
//	}
}


