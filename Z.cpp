#include<iostream>
#include<string>
using namespace std;

bool contain(string mainString, string searchString){
	string s = searchString + "$" + mainString;
	int searchStringLen = searchString.length();
	int n = s.length();
	int z[n];
	int left = 0;
	int right = 0;
	for(int i = 1; i < n;i++){
		if(i > right){
			left = right = i;
			while(right < n && s[right - left] == s[right]){
				++right;
			}
			z[i] = right - left;
			if(z[i] ==searchStringLen){
				return true;
			}
			--right;
		}
		else if(z[i - left] < right - i - 1){
			z[i] = z[i - left];
		}
		else{
			left = i;
			while(right < n && s[right - left] == s[right]){
				++right;
			}
			--right;
		}
		
	}
	return 0;
}
int main(){
	string s = "I love more Java than C++";
	string target = "Java";
	cout << contain(s,target);
}