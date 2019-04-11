#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100+10;

// ����ÿ���ڵ㶼�б��, ����ֻ��Ҫ��һ������, �������ʱ��, ����к��Ӿ�����hasChild = true 
struct tNode{
	int father;
	int level;
	bool hasChild; 
};

// tree��ʾ��, ʹ��˫�ױ�ʾ��, �Լ�ȷ���Ƿ��к��� 
// n��ʾ���Ľڵ���, m��ʾ��Ҷ�ӽڵ����, level ��ʾ���ж��ٲ� 
// d[]��ʾÿһ���Ҷ�ӽڵ����� 
tNode tree[MAXN];
int n, m, level;
int d[MAXN];


void findLeafLevel(){
	// ѭ���������ҽڵ� 
	for(int i = 1; i <= n; ++i){
		if(tree[i].hasChild == false){
			d[tree[i].level]++;
		}
	} 
}

// ������� 
void output(){
	int i = 1;
	for(; i < level; ++i){
		printf("%d ", d[i]);
	}  
	printf("%d\n", d[i]);	
} 

int main(){
	// ��ʼ�����ڵ�
	memset(tree, 0, sizeof(tree));
	memset(d, 0, sizeof(d));
	// ���� 
	scanf("%d %d", &n, &m); 
	
	int id, k, child;
	for(int i = 0; i < m; ++i){		
		scanf("%d %d", &id, &k);	
		tree[id].hasChild = true;	
		for(int j = 0; j < k; ++j){
			scanf("%d", &child);
			tree[child].father = id; 
		}
	}
	
	tree[1].level = 1;
	level = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(tree[j].father == i){
				// �̳и��׵Ĳ���+1 
				tree[j].level = tree[i].level + 1;
				// ���������
				if(tree[j].level > level) level = tree[j].level; 
			}
		}
	} 
	
	// ����ÿһ���Ҷ�ӽڵ� 
	findLeafLevel();
	// ��� 
	output(); 
	return 0;
}


