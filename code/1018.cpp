#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
const int INF = 0x6fffffff;


int G[maxn][maxn]; // ��ʾͼ, �Լ���Ӧ�ߵ�Ȩֵ  
int weight[maxn]; // ��ʾ�ڵ��Ȩֵ
int d[maxn]; // ��¼��̱�������
int vis[maxn] = {false}; // �ж��Ƿ������
int c, n, s, m; // վ���������, �ڵ���, ����ڵ����, ���� 

int numPath = 0, minNeed = INF, minRemain = INF;
vector<int> pre[maxn]; // ǰ��
vector<int> tempPath, path; // ��ʱ·��������·�� 
 
void init(){// ��ʼ�����е�ֵ 
	fill(d, d+maxn, INF);
	fill(G[0], G[0] + maxn*maxn, INF);
} 

void Dijkstra(int start){// ʹ��Dijkstra�㷨 
 	d[start] = 0;
 	for(int i = 0; i <= n; ++i){// Ѱ���������·�� 
 		int u = - 1, MIN = INF;
 		for(int j = 0; j <= n; ++j){// Ѱ����С·���� 
 			if(vis[j] == false && d[j] < MIN){
 				u = j;
 				MIN = d[j];
			}
		}
		 
		if(u == -1) return; // ���û���ҵ�, ˵����������ڵ���ͨ���Ѿ�ȫ���������� 
		vis[u] = true; 
		
		for(int v = 0; v <= n; ++v){
			if(vis[v] == false && G[u][v] != INF){// ��u�����ĵ�Ҫû�б����ʹ�, �������ı�ȨҪ���� 
				if(d[v] > d[u] + G[u][v]){// �ҵ����µ����·��, ��Ӧ��ǰ��ȫ����� 
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u); 
				}else if(d[u] + G[u][v] == d[v]){// ��ͬ���·������Ĳ�ͬǰ�� 
					pre[v].push_back(u);
				}
			}
		} 
	}
}
 
void DFS(int v){// ͨ�����Ϸ���ǰ���ڵ�, �����ʵ�ͼ�Ŀ�ʼ�ڵ�0��ʱ������ݹ� 
	if(v == 0){// �ݹ�߽�, Ҷ�ӽڵ� 
		tempPath.push_back(v);
		int need = 0, remain = 0;
		for(int i = tempPath.size() - 1; i >= 0; --i){// ��Ҷ�ӽڵ��ʱ��, ˵����ǰ·���Ѿ�������, ��Ҫ�ع�ջ, ���м��� 
			int id = tempPath[i];
			
			if(weight[id] > 0){
				remain += weight[id];
			}else{
				if(remain > abs(weight[id])){
					remain -= abs(weight[id]);
				}else{// ��Ҫ�ȼ����, Ȼ���ڽ�remain����Ϊ0 
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		
		if(need < minNeed){// ��������ѡ�� 
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		} else if(need == minNeed && remain < minRemain){
			minRemain = remain;
			path = tempPath;
		}
		
		tempPath.pop_back(); // ��Ҫ����
		return;
	}
	
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); ++i){
		DFS(pre[v][i]);
	}
	tempPath.pop_back(); // ��Ҫ���� 
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
	for(int i=1; i <= n; ++i){// �ڶ��а���n����, ��ʾ1��n��վ�е����г�����
		scanf("%d", &weight[i]); 
		weight[i] -= (c/2);
	} 
	for(int i=0; i < m; ++i){// ������m�б�ʾ· 
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
