#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const string numberEnglish[] = {
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

const int MAXN = 1e100 + 1;
char N[MAXN] = "\0";

void get_digits(){
	int i = 0, digit = 0;
	string sum;
	while(N[i] != 0){
		digit = (N[i] - '0');
		sum.to_string()
		++i;
	}
	
	for(int i = sum.length() - 1; i > 0; --i){
		printf("%s ", numberEnglish[])
	}
}


int main(){
	scanf("%s", N);
	get_digits();
	
	return 0;
} 
