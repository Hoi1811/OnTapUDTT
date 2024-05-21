#include<iostream>
#include<string>
using namespace std;
// xau doi xung 
// vi du moomoom la xau doi xung
// co doi xung hay khong
bool A1(string chuoi){
	int n = chuoi.length();
	int i = 0;
	int j = n - 1;
	while(i < j){
		if(chuoi[i] != chuoi[j]){
			return false;
		}
		i++;j--;
	}
	return true;
}
// tim xau con doi xung qua tam k dai nhat
string A2(string chuoi,int k){
	int n = chuoi.length();
	int i = k - 1;
	int j = k + 1;
	int count = 0;
	int temp = 0;
	while(i >= 0 && j <= n - 1){
		if(chuoi[i] == chuoi[j]){
			temp++;
			i--;j++;
		}else{
			temp = 0;
			i--;j++;
		}
		count = count < temp ? temp : count;
	}
	
}
int main(){
	string chuoi = "moomoom";
	cout << A1(chuoi);
}