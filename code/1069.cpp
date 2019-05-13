#include <bits/stdc++.h>
using namespace std;

int digits[4]; 

void convert_digits(int n){
	int i = 0;
	while(n){
		digits[i] = n%10;
		n /= 10;
		i++;
	}
	for(; i < 4; ++i){
		digits[i] = 0;
	}
}

bool is_same_digits(int n){
	convert_digits(n);
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			if(digits[i] != digits[j]) return false;
		}
	}
	return true;
}

int get_value(){
	int sum = 0;
	for(int i = 0; i < 4; ++i){
		sum = sum*10 + digits[i]; 
	} 
	return sum;
}

bool cmp_small(int a, int b){
	return a < b;
}
bool cmp_big(int a, int b){
	return a > b;
}

int main(){
	int n;
	scanf("%d", &n);
	
	if(is_same_digits(n)){// 如果所有位置相同就输出 
		printf("%d - %d = 0000", n, n);
	}else{
		int small, big, result;
		do{
			sort(digits, digits+4, cmp_big);
			big = get_value();
			sort(digits, digits+4, cmp_small);
			small = get_value();
			result = big - small;
			printf("%04d - %04d = %04d\n", big, small, result); 
			
			convert_digits(result); // 需要更新digits 
		}while(result != 6174);
	}
	
	return 0;
} 
