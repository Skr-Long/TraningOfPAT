#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

// emls 表示所有元素
// dp 表示动态规划数组 
// s 表示的对应dp的开始下标 
int emls[MAXN]; 

int main(){
	// 输入
	int n; 
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &emls[i]);
	}
	
	// 处理一下	
	int l = 0, r = n-1, sum = -1, tl = 0, temp = 0;
	for(int i = 0; i < n; ++i){
		 temp += emls[i];
		
		 if(temp < 0){ // 如果前面相加为负数, 直接以后面为开始为最大值左侧 
		 	temp = 0;
		 	tl = i+1;
		 } else if(sum < temp){// 如果msum小于当前计算, 那说明继续增加的是正数, 后面需要继续向后更新右侧坐标 
		 	sum = temp;
		 	l = tl;
		 	r = i;
		 } 
	}
	
	// 输出
	if(sum < 0) sum = 0;
	printf("%d %d %d\n", sum, emls[l], emls[r]); 
	
	return 0;
} 
