#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
const int INF = 0x6fffffff;


int G[maxn][maxn]; // 表示图, 以及对应边的权值  
int weight[maxn]; // 表示节点的权值
int d[maxn]; // 记录最短遍历长度
int vis[maxn] = {false}; // 判断是否遍历过
int c, n, s, m; // 站的最大容量, 节点数, 问题节点序号, 边数 

int numPath = 0, minNeed = INF, minRemain = INF;
vector<int> pre[maxn]; // 前驱
vector<int> tempPath, path; // 临时路径与最优路径 
 
void init(){// 初始化所有的值 
	fill(d, d+maxn, INF);
	fill(G[0], G[0] + maxn*maxn, INF);
} 

void Dijkstra(int start){// 使用Dijkstra算法 
 	d[start] = 0;
 	for(int i = 0; i <= n; ++i){// 寻找所有最短路径 
 		int u = - 1, MIN = INF;
 		for(int j = 0; j <= n; ++j){// 寻找最小路径点 
 			if(vis[j] == false && d[j] < MIN){
 				u = j;
 				MIN = d[j];
			}
		}
		 
		if(u == -1) return; // 如果没有找到, 说明这个点所在的连通块已经全部被访问了 
		vis[u] = true; 
		
		for(int v = 0; v <= n; ++v){
			if(vis[v] == false && G[u][v] != INF){// 与u相连的点要没有被访问过, 并且它的边权要存在 
				if(d[v] > d[u] + G[u][v]){// 找到最新的最短路径, 对应的前驱全部清除 
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u); 
				}else if(d[u] + G[u][v] == d[v]){// 相同最短路径距离的不同前驱 
					pre[v].push_back(u);
				}
			}
		} 
	}
}
 
void DFS(int v){// 通过不断访问前驱节点, 最后访问到图的开始节点0的时候结束递归 
	if(v == 0){// 递归边界, 叶子节点 
		tempPath.push_back(v);
		int need = 0, remain = 0;
		for(int i = tempPath.size() - 1; i >= 0; --i){// 在叶子节点的时候, 说明当前路径已经遍历完, 需要回归栈, 进行计算 
			int id = tempPath[i];
			
			if(weight[id] > 0){
				remain += weight[id];
			}else{
				if(remain > abs(weight[id])){
					remain -= abs(weight[id]);
				}else{// 需要先计算后, 然后在将remain设置为0 
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		
		if(need < minNeed){// 进行最优选择 
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		} else if(need == minNeed && remain < minRemain){
			minRemain = remain;
			path = tempPath;
		}
		
		tempPath.pop_back(); // 需要回溯
		return;
	}
	
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); ++i){
		DFS(pre[v][i]);
	}
	tempPath.pop_back(); // 需要回溯 
}

void output(){
	printf("%d ", minNeed);
	for(int i = path.size()-1; i >= 0; --i){
		printf("%d", path[i]);
		if(i > 0) printf("->");
	}
	printf(" %d", minRemain);
}

int main(){
	init();
	scanf("%d %d %d %d", &c, &n, &s, &m);
	for(int i=1; i <= n; ++i){// 第二行包含n个数, 表示1到n的站中的自行车数量
		scanf("%d", &weight[i]); 
		weight[i] -= (c/2);
	} 
	for(int i=0; i < m; ++i){// 接下来m行表示路 
		int u, v, ew;
		scanf("%d %d %d", &u, &v, &ew);
		G[u][v] = G[v][u] = ew;
	}
	
	Dijkstra(0); 
	DFS(s);
	 
	output();
	return 0;
}

/*
Test Case:
10 4 4 5
4 8 9 0
0 1 1
1 2 1
1 3 2
2 3 1
3 4 1
Result:
1 0->1->2->3->4 2
*/
