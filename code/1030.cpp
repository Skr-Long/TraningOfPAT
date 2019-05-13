#include <bits/stdc++.h>
using namespace std;

const int maxn = 501;
const int INF = 0x7fffffff;

struct Node{
	int cost;
	int distances;
	Node(){
		cost = INF;
		distances = INF;
	}
}; 

// Gͼ, min_costs��ÿ���ڵ����С����, min_distance��ÿ���ڵ����С����, �洢���·�� 
Node G[maxn][maxn]; 
int min_costs[maxn], min_distance[maxn], path[maxn];
// vis����Ƿ񱻷��ʹ� 
bool vis[maxn] = {false};
// n��������, m����������, s������, dĿ�ĵ� 
int n, m, s, d;

void dijkstra(){
	fill(min_distance, min_distance+n, INF);
	fill(min_costs, min_costs+n, INF);
	min_costs[s] = 0;
	min_distance[s] = 0;
	path[s] = s;
	
	for(int i = 0; i < n; ++i){
		int u = -1, min_dis = INF, min_cost = INF;
		for(int j = 0; j < n; ++j){
			if(vis[j] == false && min_distance[j] < min_dis){
				u = j;
				min_dis = min_distance[j]; 
				min_cost = min_costs[j];
			}else if(vis[j] == false && min_distance[j] == min_dis && min_costs[j] < min_cost){
				u = j;
				min_cost = min_costs[j];
			}
		}
		
		if(u == -1) return;
		vis[u] = true;
		
		for(int v = 0; v < n; ++v){
			if(vis[v] == false && G[u][v].distances != INF){
				if(min_distance[v] > min_distance[u]+G[u][v].distances){
					min_distance[v] = min_distance[u]+G[u][v].distances;
					min_costs[v] = min_costs[u]+G[u][v].cost;
					path[v] = u;
				}else if(min_distance[v] == min_distance[u] + G[u][v].distances && min_costs[v] > min_costs[u]+G[u][v].cost){
					min_costs[v] = min_costs[u] + G[u][v].cost;
					path[v] = u;
				}
			}
		}
	}
}

void output(){
	vector<int> r_path;
	int i = d;
	r_path.push_back(i);
	while(path[i] != i){
		r_path.push_back(path[i]);
		i = path[i];
	}
	
	for(int i = r_path.size()-1; i >= 0; --i){
		printf("%d ", r_path[i]);
	}
	printf("%d %d", min_distance[d], min_costs[d]);
}
int main(){
	scanf("%d %d %d %d", &n, &m, &s, &d);
	for(int i = 0; i < m; ++i){
		int u, v, dis, c;
		scanf("%d %d %d %d", &u, &v, &dis, &c);
		G[u][v].cost = c;
		G[u][v].distances = dis;
		G[v][u].cost = c;
		G[v][u].distances = dis;
	}
	
	dijkstra();
	output();
	return 0;
}
