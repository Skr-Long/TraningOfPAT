#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 500+10;
const int INF = 0x3fffffff;

// n, m, st, ed 分别为点数, 边数, 起点, 终点
// G为邻接矩阵, weight为点权
// d[]记录最短距离, w[]记录最大点权之和, num[]记录最短路径条数, vis[]记录点是否被访问过
int n, m, st, ed;
int G[MAX_SIZE][MAX_SIZE], weight[MAX_SIZE];
int d[MAX_SIZE], w[MAX_SIZE], num[MAX_SIZE];
bool vis[MAX_SIZE] = {false};

// 使用Dijkstra算法
void Dijkstra(int s) {
	// 初始化
	// d使用INF填充, 因为d需要比较
	// w记录的是最大点权之和, 也就是救援小队的和
	// num记录最短路径条数, 所以初始为0
	fill(d, d+MAX_SIZE, INF);
	memset(w, 0, sizeof(w));
	memset(num, 0, sizeof(num));
	// 对于初始点st位置的值设置
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;

	// 根据Dijkstar算法, 可以知道需要循环n次,寻找每次最优的路径
	for(int i = 0; i < n; ++i) {
		// 找出d[j]最小的点, 如果是初始点s的话, 也可以找到 
		int u = -1, MIN = INF;
		for(int j = 0; j < n; ++j){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		// 如果u还是-1, 表明这一点与其他点没有连通
		if(u == -1) return;
		
		// 如果找到
		vis[u] = true; 
		
		// 修改u连通没有被访问过的点的最优解
		for(int v = 0; v < n; ++v){
			if(vis[v] == false && G[u][v] != INF){// 如果d[v] > d[u] + G[u][v], 那么就修改 
				if(d[v] > d[u] + G[u][v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];	 
					num[v] = num[u];			// 继承num[u]的最短路径 
				}else if(d[v] == d[u] + G[u][v]){// 如果相等, 就需要判断
					if(w[v] < w[u] + weight[v]){
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];			// 如果是新的路线, 就需要添加到num[v]中 
				} 
			}
		} 
	}
}


int main() {
	// 输入数据
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &weight[i]); // 读入点权
	}

	fill(G[0], G[0] + MAX_SIZE*MAX_SIZE, INF); // 初始化G
	int u, v;
	for(int i = 0; i < m; ++i) {

		scanf("%d%d",&u, &v);
		// 更新边权
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}

	// 使用Dijkstar算法处理
	Dijkstra(st);

	// 输出对应
	printf("%d %d", num[ed], w[ed]);

	return 0;
}
