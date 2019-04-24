#include<bits/stdc++.h>
using namespace std;

const int maxn = 30010;


struct Testee{
	char id[15]; // 编号 
	int score; // 成绩 
	int fr; // 最终排行 
	int ln; // 考场号 
	int lr; // 考场排名 
}testee[maxn];

bool cmp(Testee x, Testee y){
	bool f = strcmp(x.id, y.id);
	if(x.score != y.score) return x.score > y.score;
	else return f < 0;		 
}

int main(){
	int n, k;
	int sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &k);
		for(int j = sum; j < sum + k; ++j){// 统计当地数据, 考生考号, 考生成绩, 考生考场号 
			scanf("%s %d", testee[j].id, &testee[j].score);
			testee[j].ln = i;
		}
		sort(testee+sum, testee+sum+k, cmp);
		testee[sum].lr = 1;
		for(int j = sum + 1; j < sum+k; ++j){// 处理当地名次 
			if(testee[j].score == testee[j-1].score){
				testee[j].lr = testee[j-1].lr;
			}else{
				testee[j].lr = j + 1 - sum;
			}
		}
		sum += k;
	}	
	
	sort(testee, testee+sum, cmp);
	testee[0].fr = 1;
	for(int i = 1; i < sum; ++i){
		if(testee[i].score == testee[i-1].score){
			testee[i].fr = testee[i-1].fr; 
		}else{
			testee[i].fr = i + 1;
		} 
	} 
	
	printf("%d\n", sum);
	for(int i = 0; i < sum; ++i){
		printf("%s %d %d %d\n", testee[i].id, testee[i].fr, testee[i].ln, testee[i].lr);
	}
	
	return 0;
}

