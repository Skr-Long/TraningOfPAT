#include<bits/stdc++.h>
using namespace std;

vector<int> digits;

void get_digits(int num, int radix){
	while(num){
		digits.push_back(num%radix);
		num /= radix;
	}
}

bool is_palindromicity(){
	int len = digits.size();
	for(int i = 0; i < len/2; ++i){
		if(digits[i] != digits[len - 1 - i]) return false;
	}
	return true;
}

int main(){
	int n, b;
	scanf("%d %d", &n, &b);
	get_digits(n, b);
	
	if(is_palindromicity()){
		printf("Yes\n");
	} else{
		printf("No\n");
	}
	
	for(int i = digits.size() - 1; i >= 0; --i){
		printf("%d", digits[i]);
		if(i > 0) printf(" ");
	}
	
	return 0;
} 
