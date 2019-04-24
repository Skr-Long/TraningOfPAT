#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> G[maxn]; // �ڽӱ� 

/**
* ���鼯����������ͨ��, �ҿ�ʼʹ�õ���DFSȾɫ 
**/
bool isRoot[maxn];
int father[maxn];
int find_father(int x){// ����x�ļ������ڵĸ��ڵ� 
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	
	while(a != father[a]){// ·��ѹ�� 
		int z = a;
		a = father[a];
		father[z] = x;
	}
	
	return x;
}

void _union(int a, int b){ // �ϲ�a��b�ļ��� 
	int faA = find_father(a);
	int faB = find_father(b);
	if(faA != faB){
		father[faA] = faB;
	} 
} 

void init(int n){// ���鼯��ʼ�� 
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
* ����ͼ�е���� 
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
	for(int i = 0; i < n - 1; ++i){// ���� 
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
