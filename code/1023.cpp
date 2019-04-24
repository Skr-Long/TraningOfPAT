#include<bits/stdc++.h>
using namespace std;

struct BigN{// �������� 
	int digit[21];
	int len;
	BigN(){
		memset(digit, 0, sizeof(digit));
		len = 0;
	}
}; 

BigN change(char str[]){// ���ַ���ת��Ϊ�������� 
	BigN a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; ++i){
		a.digit[i] = str[a.len - i - 1] - '0';
	}
	return a; 
}

BigN multi(BigN a, int b){// �߾����㷨 
	BigN c;
	int carry = 0; // ��λ
	
	for(int i = 0; i < a.len; ++i){ 
		int temp = a.digit[i] * b + carry;
		c.digit[c.len++] = temp%10;
		carry = temp/10;
	} 
	
	while(carry != 0){// �˷���������λ�� 
		c.digit[c.len++] = carry % 10;
		carry /= 10;
	}
	return c; 
}


bool judge(BigN a, BigN b){// �ж��������������Ƿ���ͬ 
	if(a.len != b.len) return false;
	
	int digit[10] = {0};
	for(int i = 0; i < a.len; ++i){
		digit[a.digit[i]]++;
		digit[b.digit[i]]--;
	} 
	
	for(int i = 0; i < 10; ++i){
		if(digit[i] != 0) return false;
	}
	return true;
}

void print(BigN a){
	for(int i = a.len - 1; i >= 0; --i){
		printf("%d", a.digit[i]);
	}
}
 
int main(){
	char str[21];
	gets(str);
	BigN a = change(str);
	BigN b = multi(a, 2);
	if(judge(a, b)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	print(b);
	return 0;
} 
