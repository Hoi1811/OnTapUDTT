#include<iostream>
#include<string>
using namespace std;
// thuat toan boyer moore
// kiem tra su ton tai cua 1 chuoi ki tu trong xau ki tu da cho
int checkindex(string search, char main){
	for(int i = 0 ; i < search.length();i++){
		if(search[i] == main){
			return i;
		}
	}
	return -1;
}
int value(string main, string search){
	int v = search.length() - 1;
	int i = v;
	while(i < main.length()){
		int x = v;
		int j = i;
		while(main[j] == search[x]){
			j--;
			x--;
		}
		if(x < 0){
			return j + 1;
		}else{
			x = checkindex(search, main[j]);
			if(x < 0) i += v + 1;
			else if(x < v) i += v - x;
			else ++i;
		}
	}
	return -1;
}
int main(){
	string main = "ai lop you chut chut 21000 hehe";
	string s = "1000";
	cout << value(main, s);
	
}