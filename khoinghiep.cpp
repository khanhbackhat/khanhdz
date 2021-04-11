#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib> 
#include<iomanip>
using namespace std;
class Sinhvien
{	
	int msv;
	char lop[10];
	char hoten[18];
	int ns;	//nam sinh;
	char diachi[25];
	char gioitinh[4];
	float tin1, tin2, tin3, tin4;
	float ha1, ha2, dtb;
	public:
		void chuanhoa(char hoten[18]);
		void nhap();
		void hienthi();
		void xuat();
		// cau 2 m bo sung them nha;
};
void Sinhvien::chuanhoa(char hoten[18])
{
	
	// xoa ki tu trang o dau
	while(hoten[0]==' ')
		for(int i=0;i<strlen(hoten);i++)
			hoten[i]=hoten[i+1];
	// xoa ki tu trang o giua
	for(int i=1;i<strlen(hoten);i++)
		if(hoten[i-1]==' '&&hoten[i]==' ')
			while(hoten[i]==' ')
				for(int j=i;j<strlen(hoten);j++)
					hoten[j]=hoten[j+1];
	// chuan hoa chu hoa
	for(int i=1;i<strlen(hoten);i++)
		if(hoten[i]>='A'&&hoten[i]<='Z')
			hoten[i]+=32;
	
	if(hoten[0]>'Z')	
		hoten[0]=hoten[0]-32;
	for(int i=1;i<strlen(hoten);i++)
		if(hoten[i-1]==' '&&hoten[i]>'Z')
			hoten[i]=hoten[i]-32;
}
void Sinhvien::nhap()
{
	cout<<"\nMoi Nhap MSV: ";cin>>msv;cout<<endl;
	fflush(stdin);
	cout<<"Nhap Ho Ten: ";cin.getline(hoten,18);chuanhoa(hoten);
	cout<<"\nSV Nay Hoc Lop Bao Nhieu? ";cin.getline(lop,10);
	cout<<"\nNhap Nam Sinh: ";cin>>ns;
	fflush(stdin);
	cout<<"\nNhap Dia Chi: ";cin.getline(diachi,25);
	cout<<"\nNhap Gioi Tinh: ";cin.getline(gioitinh,4);
	do{
		cout<<"\nNhap Diem Tin 1: ";
		cin>>tin1;
	}
	while(tin1<0||tin1>10); 
	
	do{
		cout<<"\nNhap Diem Tin 2: ";cin>>tin2;
	}
	while(tin2<0||tin2>10);
	do{
		cout<<"\nNhap Diem Tin 3: ";cin>>tin3;
	}
	while(tin3<0||tin3>10);
	do{
		cout<<"\nNhap Diem Tin 4: ";cin>>tin4;
	}
	while(tin4<0||tin4>10);
	do{
		cout<<"\nNhap Diem Ha 1: ";cin>>ha1;
	}
	while(ha1<0||ha1>10);
	do{
		cout<<"\nNhap Diem Ha 2: ";cin>>ha2;
	}
	while(ha2<0||ha2>10);
	dtb=(tin1+tin2+tin3+tin4+ha1+ha2)/6;
};
void Sinhvien::hienthi()
{
	cout<<msv<<"\t"<<hoten<<setw(15)<<lop<<setw(8)<<ns<<setw(8)<<diachi<<setw(20)<<gioitinh<<setw(5)<<tin1<<"\t"<<tin2<<"\t"<<tin3<<"\t"<<tin4<<"\t"<<ha1<<"\t"<<ha2<<"\t"<<dtb<<"\n";
}
void Sinhvien::xuat()
{
	cout<<"MSV"<<"\t"<<"Ho Ten"<<setw(15)<<"Lop"<<setw(8)<<"Nam Sinh"<<setw(8)<<"Dia Chi"<<setw(20)<<"Gioi Tinh"<<setw(5)<<"Tin 1"<<"\t"<<"Tin 2"<<"\t"<<"Tin 3"<<"\t"<<"Tin 4"<<"\t"<<"Ha 1"<<"\t"<<"Ha 2"<<"\t"<<"DTB"<<"\n";
	hienthi();
};
int main()
{
	Sinhvien x;
	x.nhap();
	x.xuat();
	return 0;
}
