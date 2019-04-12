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
	int msum = -1, ls = 0, re = n-1, tempi = 0, temps = 0;
	for(int i = 0; i < n; ++i){
		 temps += emls[i];
		
		 if(temps < 0){ // 如果前面相加为负数, 直接以后面为开始为最大值左侧 
		 	temps = 0;
		 	tempi = i+1;
		 } 
		 
		 if(msum < temps){// 如果msum小于当前计算, 那说明继续增加的是正数, 后面需要继续向后更新右侧坐标 
		 	msum = temps;
		 	ls = tempi;
		 	re = i;
		 } 
	}
	
	// 输出
	if(msum < 0) msum = 0;
	printf("%d %d %d\n", msum, emls[ls], emls[re]); 
	
	return 0;
} 
