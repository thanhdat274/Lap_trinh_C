#include <iostream>
#include<math.h>

using namespace std;

main(){
	int n;
	float a[100];
	// nhap
	cout<<"nhap n: ";
	cin>>n;
	// nhap he so
	for(int i = 0; i<=n;i++)	{
		cout<<"Nhap he so bac: "<<i<<": ";
		cin>>a[i];
	}
	// in ra man hinh 
	for(int i= 0; i<=n; i++){
		cout<<a[i]<<" ";
	}
	float x;
	cout<<"\nNhap x: ";
	cin>>x;
	float s= 0;
	for(int i=0; i<=n;i++){
		s=s+a[i]*pow(x,i);
	}
	float s1 =0;
	for(int i= 1; i<=n; i++){
		s1=s1+a[i]*i*pow(x,i-1);
	}
	float kq = x + sqrt(s+s1+2023);
	cout<<"\nKQ: "<<kq;
	
	// tim he so lon nhat cua da thuc
	float m= a[0];
	for(int i=0;i<=n;i++){
		if(a[i]>m){
			m= a[i];
		}
	}
	cout<<"\nMax: "<<m;
	// tinh tong cac he so am cua da thuc
	float s= 0; dem = 0; tich =1;
	for(int i = 0;i<=n;i++){
		if(a[i]<0){
			s=s+a[i];
		}
	}
	cout<<"\nTong am la: "<<s;
	// tinh trung binh cong cac he so lon hon x torng da thuc
	s=0;
	for(int i = 0; i<=n;i++){
		if(a[i]>x){
			dem++;
			s+=a[i];
		}
	}
	if(dem==0){
		cout<<"Khong co: ";
	}else{
		cout<<"\nTBC: "<<s;
	}
}
