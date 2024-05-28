#include<bits/stdc++.h>
using namespace std;

struct QuatBan{
	string tenHangSX;
	string mau;
	double giaBan;
};
// so luong va danh sach nhieu nhat cac quat ban co the mua duoc 
// tu danh sach d voi so tien p

// Chien luoc tham lam
int G1(int n, QuatBan d[], double p, vector<QuatBan> &s){
	int i = n - 1;
	while(p > 0 && i >= 0){
		if(p >= d[i].giaBan){
			p-= d[i].giaBan;
			s.push_back(d[i]);	
		}
		i--;
	}
	return s.size();
}
void printList(vector<QuatBan> s){
	int i = 0;
	while(i < s.size()){
		cout << s[i].tenHangSX << endl;;
		++i;
	}
}
int main(){
	int n = 6;
	double p = 1300000;
	QuatBan d[n] = {
		{"Panasonic", "Xanh", 1000000},
		{"Daikin", "Xanh", 700000},
		{"LG", "Xanh", 650000},
		{"Xiaomi", "Xanh", 600000},
		{"Thong Nhat", "Xanh", 500000},
		{"PRO", "Xanh", 200000},
	};
	vector<QuatBan> s;
	cout << "so luong nhieu nhat co the lay voi so tien: " << p << " la: " << G1(n,d,p,s) << endl;
	printList(s);

}