/**
* ��������ҳ�����̰���㷨(���ܹ�), ��������Ҫ�������(���, ���Ǻ����Եĳ�ʱ��)
* ��Ҳ֪������ʹ�ö�̬�滮, ����д����, �������������°�
* ���濴��һλ���еĴ���, û�������ඥ�ĸо�, Ӧ�ò�����Ϊʲô����ʹ��̰���㷨?
* ΪʲôҪ����ȥ����, ����Ϊʲô������⶯̬�滮Ҫ������? ������~(> ^ <)~ 
* ���ڳ���һ��ʹ�ö�̬�滮����, ����ԭ������ 
*/

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int INF = 0x7ffffff; 
const int MAXN = 1e4;

int dp[MAXN + 10]; // ��̬�滮����, ��ʾ������i��ʱ����Сֵ 

int main(){
	int t; scanf("%d", &t);
	while(t--){
		// ��Ǯ�޵Ŀ�we����wf������ 
		int we, wf;
		scanf("%d %d", &we, &wf);
		// �ڴ�Ǯ��������Ӳ������ 
		int w_coins = wf - we; 
		for(int i = 1; i <= w_coins; ++i){
			dp[i] = INF;
		}
		dp[0] = 0;
		// Ӳ�ҵ�������, Ӳ�Ҽ�ֵ, Ӳ������ 
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
		// ���
		if(dp[w_coins] == INF) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[w_coins]);
	} 
	
	return 0;
}
