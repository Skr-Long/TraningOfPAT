#include <cstdio>
#include <cstring>
#include <string>
using namespace std;


const char numberEnglish[][10] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine" 
};

// s[]表示输入的N， digit[]表示位数 
char s[111];
int digit[10]; 

int main(){
	scanf("%s", s);
	// len是s的长度
	int len = strlen(s); 
	
	// sum 是s的位之和
	// numLen是sum的长度 
	int sum = 0, numLen = 0;
	
	// 获得累加之和
	for(int i = 0; i < len; ++i){
		sum += (s[i] - '0');
	} 
	if(sum == 0){// 如果sum为0直接输出zero 
		printf("%s", numberEnglish[0]);
	}else {// 获得sum的每位 
		while(sum){
			digit[numLen++] = sum % 10;
			sum /= 10;
		}
		for(int i = numLen-1; i > 0; --i){
			printf("%s ", numberEnglish[digit[i]]);
		}
		printf("%s", numberEnglish[digit[0]]);
	}
	
	return 0;
} 
