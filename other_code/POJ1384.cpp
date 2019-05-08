/**
* 这个问题我尝试了贪心算法(不能过), 后面又想要暴力求解(深度, 但是很明显的超时了)
* 我也知道可以使用动态规划, 但是写不来, 真是在柠檬树下啊
* 后面看了一位大佬的代码, 没有醍醐灌顶的感觉, 应该不明白为什么不能使用贪心算法?
* 为什么要这样去计算, 而且为什么这个问题动态规划要那样做? 很难受~(> ^ <)~ 
* 现在尝试一下使用动态规划来做, 至于原理还不懂 
*/

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int INF = 0x7ffffff; 
const int MAXN = 1e4;

int dp[MAXN + 10]; // 动态规划数组, 表示容量在i的时候最小值 

int main(){
	int t; scanf("%d", &t);
	while(t--){
		// 存钱罐的空we与满wf的重量 
		int we, wf;
		scanf("%d %d", &we, &wf);
		// 在存钱罐中最大的硬币重量 
		int w_coins = wf - we; 
		for(int i = 1; i <= w_coins; ++i){
			dp[i] = INF;
		}
		dp[0] = 0;
		// 硬币的种类数, 硬币价值, 硬币质量 
		int n, P, W;
		scanf("%d", &n);
		while(n--){
			scanf("%d %d", &P, &W);
			for(int i = W; i <= w_coins; ++i){
				if(dp[i] > dp[i-W] + P){
					dp[i] = dp[i-W] + P;
				}
			}
		} 
		// 输出
		if(dp[w_coins] == INF) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[w_coins]);
	} 
	
	return 0;
}
