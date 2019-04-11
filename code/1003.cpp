#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 500+10;
const int INF = 0x3fffffff;

// n, m, st, ed �ֱ�Ϊ����, ����, ���, �յ�
// GΪ�ڽӾ���, weightΪ��Ȩ
// d[]��¼��̾���, w[]��¼����Ȩ֮��, num[]��¼���·������, vis[]��¼���Ƿ񱻷��ʹ�
int n, m, st, ed;
int G[MAX_SIZE][MAX_SIZE], weight[MAX_SIZE];
int d[MAX_SIZE], w[MAX_SIZE], num[MAX_SIZE];
bool vis[MAX_SIZE] = {false};

// ʹ��Dijkstra�㷨
void Dijkstra(int s) {
	// ��ʼ��
	// dʹ��INF���, ��Ϊd��Ҫ�Ƚ�
	// w��¼��������Ȩ֮��, Ҳ���Ǿ�ԮС�ӵĺ�
	// num��¼���·������, ���Գ�ʼΪ0
	fill(d, d+MAX_SIZE, INF);
	memset(w, 0, sizeof(w));
	memset(num, 0, sizeof(num));
	// ���ڳ�ʼ��stλ�õ�ֵ����
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;

	// ����Dijkstar�㷨, ����֪����Ҫѭ��n��,Ѱ��ÿ�����ŵ�·��
	for(int i = 0; i < n; ++i) {
		// �ҳ�d[j]��С�ĵ�, ����ǳ�ʼ��s�Ļ�, Ҳ�����ҵ� 
		int u = -1, MIN = INF;
		for(int j = 0; j < n; ++j){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		// ���u����-1, ������һ����������û����ͨ
		if(u == -1) return;
		
		// ����ҵ�
		vis[u] = true; 
		
		// �޸�u��ͨû�б����ʹ��ĵ�����Ž�
		for(int v = 0; v < n; ++v){
			if(vis[v] == false && G[u][v] != INF){// ���d[v] > d[u] + G[u][v], ��ô���޸� 
				if(d[v] > d[u] + G[u][v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];	 
					num[v] = num[u];			// �̳�num[u]�����·�� 
				}else if(d[v] == d[u] + G[u][v]){// ������, ����Ҫ�ж�
					if(w[v] < w[u] + weight[v]){
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];			// ������µ�·��, ����Ҫ��ӵ�num[v]�� 
				} 
			}
		} 
	}
}


int main() {
	// ��������
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &weight[i]); // �����Ȩ
	}

	fill(G[0], G[0] + MAX_SIZE*MAX_SIZE, INF); // ��ʼ��G
	int u, v;
	for(int i = 0; i < m; ++i) {

		scanf("%d%d",&u, &v);
		// ���±�Ȩ
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}

	// ʹ��Dijkstar�㷨����
	Dijkstra(st);

	// �����Ӧ
	printf("%d %d", num[ed], w[ed]);

	return 0;
}
