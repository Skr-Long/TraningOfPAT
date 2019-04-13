#include <bits/stdc++.h>
using namespace std;

const int maxk = 1010;
struct Window{
	int endTime, popTime;	// 当前窗口服务结束时间, 对首服务结束时间
	queue<int> q;			// 当前窗口排队 
}windows[20];

// n表示窗口数, m表示每个窗口黄线内部人数, k表示顾客数, query表示查询数量
int n,m,k,query;

// ans表示服务结束时间, need表示服务需要时间 
int ans[maxk], needTime[maxk]; 

int convertToMintinues(int h, int m){// 将时间转换为分钟, 方便计算 
	return h*60+m;
}

int main(){
	int inCus = 0; // 当前第一个尚未入列的顾客
	scanf("%d%d%d%d", &n, &m, &k, &query);
	for(int i = 0; i < k; ++i){
		scanf("%d", &needTime[i]);
	} 
	for(int i = 0; i < n; ++i){
		windows[i].endTime=windows[i].popTime=convertToMintinues(8, 0);
	}
	
	for(int i = 0; i < min(n*m, k); ++i){// 初始入列, 填满n*m 或者顾客人数k不足n*m 
		windows[inCus%n].q.push(inCus);
		windows[inCus%n].endTime += needTime[inCus];
		if(inCus < n) windows[inCus].popTime = needTime[inCus];
		ans[inCus] = windows[inCus%n].endTime;
		inCus++;
	}
	
	for(; inCus < k; ++inCus){// 处理剩余队伍 
		int idx = -1, minPopTime = 1 << 30;
		for(int i = 0; i < n; ++i){// 寻找对首最早完成时间的窗口 
			if(windows[i].popTime < minPopTime){
				idx = i;
				minPopTime = windows[i].popTime;
			}
		}
		
		Window& W = windows[idx]; 
		
		W.q.pop();	// 先出队列 
		W.q.push(inCus);	// inCud入队
		W.popTime += needTime[W.q.front()];
		W.endTime += needTime[inCus];
		ans[inCus] = W.endTime;
	}
	
	int q;
	int deadLine = convertToMintinues(17, 0); 
	for(int i = 0; i < query; ++i){// 处理查询
		scanf("%d", &q);
		if(ans[q-1] - needTime[q-1] >= deadLine){
			printf("Sorry\n");
		} else{
			printf("%02d:%02d\n", ans[q-1]/60, ans[q-1]%60);
		}
	}
	
	return 0;
}
