#include<iostream>

using namespace std;

void algorithm(int n, int a[], int *L, int *T){
	a[0] = -2147483648; a[n + 1] = 2147483647;
	L[n + 1] = 0;
	int jmax = 0;
	for (int i = n; i >= 0; i--){
		jmax = n + 1;
		for(int j = i + 1; j <= n + 1; j++){
			if(a[j] > a[i] && L[j] > L[jmax]){
				jmax = j;
			}
			L[i] = L[jmax] + 1;
			T[i] = jmax;
		}
	}
}
int result(int n,int a[], int *T){
	int k = 1;
	int count = 0;
	while(k != n + 1){
		cout << "a[" << k << "]: " << a[k] << "\n";
		k = T[k];
		count++;
	}
	return count;
}

int main(){
	int n = 9;
	int	a[n + 2] = {0, 2,3,1,5,7,8,2,3,9,0};
	int *L = new int[n + 2]{0};
	int *T = new int[n + 2]{0};
	algorithm(n,a,L,T);
	cout << result(n,a,T);
	
}

