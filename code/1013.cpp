#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
vector<int> G[maxn]; // 邻接表
bool vis[maxn];	// 点是否已经被遍历 
int currentPoint; // 当前查询的点 

void dfs(int p){
	if(p == currentPoint) return;
	for(int i = 0; i < G[p].size(); ++i){
		if(!vis[G[p][i]]){
			vis[G[p][i]] = true;
			dfs(G[p][i]); 
		} 
	}
}

int n, m, k; 

int main(){
	scanf("%d %d %d", &n, &m, &k);
	int u, v;
	for(int i = 0; i < m; ++i){
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 0; i < k; ++i){
		scanf("%d", &currentPoint);
		int block = 0;
		memset(vis, false, sizeof(vis));
		for(int j = 1; j <= n; ++j){
			if(j!=currentPoint && !vis[j]){// j不为当前查询点, 同时没有被遍历过 
				dfs(j);
				block++;
			}
		}
		printf("%d\n", block-1);
	} 

	return 0; 
} 
