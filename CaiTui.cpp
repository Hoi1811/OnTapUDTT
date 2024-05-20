#include<iostream>

using namespace std;
void algorithm(int n,int m, float w[], float v[], float F[6][13]){
	for(int i = 0; i <= m;i++){
		F[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m;j++){
			F[i][j] = F[i - 1][j];
			if(j >= w[i]){
				float temp = v[i] + F[i - 1][j - (int)w[i]];
				if(F[i][j] < temp){
					F[i][j] = temp;
				}
			}
		}
	}
}

void result(int n,int m, float w[], float v[], float F[6][13]){
	int i = n;
	int j = m;
	while(i > 0){
		if(F[i][j] != F[i - 1][j]){
			cout << "Lay goi hang "<< i << " voi gia tri la " << v[i] << endl;
			j -= w[i];
		}
		i--;
	}
}
int main(){
	int n = 6;
	int m = 12;
	float w[n + 1] = {0,3,6,2,7,1,5};
	float v[n + 1] = {0,4,5,2,6,1,3};
	float F[7][13];
	algorithm(n,m,w,v,F);
	result(n,m,w,v,F);
	
}

