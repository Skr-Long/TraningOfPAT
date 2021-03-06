#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

void input(long long&a, long long& b){
	scanf("%lld %lld", &a, &b);
}

long sum(long long a, long long b){
	return a+b;
}

void output(long long sum){
  	// 1. 确定sum是否为负数
	int flag = 1;
	if(sum < 0){
		flag = 0;
		sum = -sum;
	}
	if(!flag) printf("-");
	
	// 2. 创建一个栈, 存储没三位
	stack<int> bits;
	
	do{
		bits.push(sum%1000);
		sum /= 1000;
	}while(sum);

	// 3. 打印格式
	if(bits.size() == 1)
		printf("%d", bits.top());
	else
		printf("%d,", bits.top());
	bits.pop();
	
	while(bits.size() > 1){
		printf("%03d,", bits.top());
		bits.pop();
	}
	if(bits.size() == 1)
		printf("%03d", bits.top());
	bits.pop();
}
		

int main()
{
	long long a, b;
 	input(a, b);
	
	long long s = sum(a, b);
	output(s);
	
	return 0;
}
