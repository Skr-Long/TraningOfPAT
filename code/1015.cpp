#include<bits/stdc++.h>
using namespace std;

typedef vector<int> VI;

void get_digit(int num, int radix, VI& v){// ���н���ת��
	while(num){
		v.push_back(num%radix);
		num /= radix;	
	}
} 

int get_value10(VI v, int radix){
	int value = 0;
	for(VI::iterator it = v.begin(); it != v.end(); ++it){
		value = value*radix + (*it);
	}
	return value;
} 


bool is_prim(int num){// �ж��Ƿ�Ϊ���� 
	if(num <= 1) return false;
	long mid = (int)sqrt(1.0*num);
	for(int i = 2; i < mid + 1; ++i){
		if(num%i == 0) return false;
	}
	return true;
}

 
int main(){
	int n, d;
	while(scanf("%d", &n) != EOF){
		if(n < 0) break; // nΪ�����˳�ѭ�� 
		
		scanf("%d", &d);
		
		if(!is_prim(n)){ // ���жϸ����������Ƿ�Ϊ���� 
			printf("No\n");
		}else{
			VI digits;
			get_digit(n, d, digits);
			int num = get_value10(digits, d);
			if(is_prim(num)){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		} 
	}
	return 0;
} 
