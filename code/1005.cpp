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

// s[]��ʾ�����N�� digit[]��ʾλ�� 
char s[111];
int digit[10]; 

int main(){
	scanf("%s", s);
	// len��s�ĳ���
	int len = strlen(s); 
	
	// sum ��s��λ֮��
	// numLen��sum�ĳ��� 
	int sum = 0, numLen = 0;
	
	// ����ۼ�֮��
	for(int i = 0; i < len; ++i){
		sum += (s[i] - '0');
	} 
	if(sum == 0){// ���sumΪ0ֱ�����zero 
		printf("%s", numberEnglish[0]);
	}else {// ���sum��ÿλ 
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
