#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> G[maxn]; // 邻接表 

/**
* 并查集用于搜索连通块, 我开始使用的是DFS染色 
**/
bool isRoot[maxn];
int father[maxn];
int find_father(int x){// 查找x的集合所在的根节点 
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	
	while(a != father[a]){// 路劲压缩 
		int z = a;
		a = father[a];
		father[z] = x;
	}
	
	return x;
}

void _union(int a, int b){ // 合并a和b的集合 
	int faA = find_father(a);
	int faB = find_father(b);
	if(faA != faB){
		father[faA] = faB;
	} 
} 

void init(int n){// 并查集初始化 
	for(int i = 1; i <= n; ++i){
		father[i] = i;
	}
}

int cal_block(int n){
	int block = 0;
	for(int i = 1; i <= n; ++i){
		isRoot[find_father(i)] = true;
	}
	for(int i = 1; i <= n; ++i){
		block += isRoot[i];
	}
	return block;
}

/**
* 计算图中的最高 
**/ 
int maxH = 0;
vector<int> temp, Ans;

void DFS(int u, int height, int pre){
	if(height > maxH){
		temp.clear();
		temp.push_back(u);
		maxH = height;
	} else if(height == maxH){
		temp.push_back(u);
	}
	
	for(int i = 0; i < G[u].size(); ++i){
		if(G[u][i] == pre) continue;
		DFS(G[u][i], height + 1, u);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	init(n);
	for(int i = 0; i < n - 1; ++i){// 输入 
		int u, v;
		scanf("%d %d", &u, &v); 
		G[u].push_back(v);
		G[v].push_back(u);
		_union(u, v);
	}
	int block = cal_block(n);
	if(block != 1){
		printf("Error: %d components\n", block);
	}else{
		DFS(1, 1, -1);
		Ans = temp;
		DFS(Ans[0], 1, -1);
		for(int i = 0; i < temp.size(); ++i){
			Ans.push_back(temp[i]);
		}
		sort(Ans.begin(), Ans.end());
		printf("%d\n", Ans[0]);
		for(int i = 1; i < Ans.size(); ++i){
			if(Ans[i] != Ans[i-1]){
				printf("%d\n", Ans[i]);
			}
		}
	}
	
	
	return 0;
}
