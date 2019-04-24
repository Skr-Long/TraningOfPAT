#include<bits/stdc++.h>
using namespace std;

struct bign{
	int d[222];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	} 
	
	bign& operator=(const bign &p){
		for(int i = 0; i < p.len; ++i){
			this->d[i] = p.d[i];
		}
		this->len = p.len;
		return *this;
	}
}; 

bign change(char str[]){
	bign c;
	c.len = strlen(str);
	for(int i = 0; i < c.len; ++i){
		c.d[i] = str[c.len - i - 1] - '0';
	}
	return c;
}

bign addition_reverse(bign a){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; ++i){// 计算加法后的运算 
		int temp = a.d[i] + a.d[a.len-i-1] + carry;
		c.d[c.len++] = temp%10;
		carry = temp/10;
	}
	while(carry){
		c.d[c.len++] = carry%10;
		carry /= 10;
	} 
	return c;
} 

bool is_palindromic(const bign& a){
	for(int i = 0; i < a.len/2; ++i){
		if(a.d[i] != a.d[a.len-1-i]) return false;
	}
	return true;
} 


void print_bign(const bign& a){
	for(int i = a.len-1; i >= 0; --i){// 打印数字 
		printf("%d", a.d[i]);
	}
}


int main(){
	char str[222];
	int maxs;
	scanf("%s %d", str, &maxs);
	bign a = change(str); 
	int len = 0;
	bign result;
	while(len < maxs && !is_palindromic(a)){
		a = addition_reverse(a);
		++len;
	}
	print_bign(a);
	printf("\n%d", len); 
	return 0;
}
