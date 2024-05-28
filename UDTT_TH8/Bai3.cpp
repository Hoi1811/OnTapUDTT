#include<bits/stdc++.h>
using namespace std;

struct DienThoai {
	string brand;
	int size;
	float price;
};
int Q1(int n, DienThoai d[], int s, float **F){
	for(int j = 0; j <= s;j++) F[0][j] = 0;
	
	for(int i = 1; i <= n;i++){
		
		for(int j = 0; j <= s;j++){
			F[i][j] = F[i - 1][j];
			if(j > d[i].size){
				float temp = d[i].price + F[i - 1][j - d[i].size];
				if(temp > F[i][j]){
					F[i][j] = temp;
				}
			}
		}
	}
}
void truyVet(int n, DienThoai d[],int s, float **F){
	int i = n;
	int j = s;
	while(i>0){
		if(F[i][j]!=F[i-1][j]){
			cout << d[i].brand << " -- " << d[i].price << endl;
			j -= d[i].size;
		}
		--i;
	}
}
int main() {
	int n = 6;
	DienThoai d[n + 1] = {
		{"",0 ,0 },
		{"SamSung", 5, 700000},
		{"Apple", 6, 1900000},
		{"LG", 8, 6000000},
		{"ASUS", 7, 6000000},
		{"Bomb", 9, 1200000},
		{"Nokia", 4, 5000000}
	};
	int s = 15;
	float **F;
	F = new float*[n + 1];
	for(int i = 0; i <= n; i++){
		F[i] = new float[s + 1];
	}
	Q1(n,d,s,F);
	truyVet(n,d,s,F);
	delete[] F;
}