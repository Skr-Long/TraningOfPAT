#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100+10;

// 由于每个节点都有编号, 所以只需要开一个数组, 在输入的时候, 如果有孩子就设置hasChild = true 
struct tNode{
	int father;
	int level;
	bool hasChild; 
};

// tree表示树, 使用双亲表示法, 以及确定是否有孩子 
// n表示树的节点数, m表示非叶子节点个数, level 表示树有多少层 
// d[]表示每一层的叶子节点数量 
tNode tree[MAXN];
int n, m, level;
int d[MAXN];


void findLeafLevel(){
	// 循环遍历查找节点 
	for(int i = 1; i <= n; ++i){
		if(tree[i].hasChild == false){
			d[tree[i].level]++;
		}
	} 
}

// 输出函数 
void output(){
	int i = 1;
	for(; i < level; ++i){
		printf("%d ", d[i]);
	}  
	printf("%d\n", d[i]);	
} 

int main(){
	// 初始化根节点
	memset(tree, 0, sizeof(tree));
	memset(d, 0, sizeof(d));
	// 输入 
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
				// 继承父亲的层数+1 
				tree[j].level = tree[i].level + 1;
				// 获得最大层数
				if(tree[j].level > level) level = tree[j].level; 
			}
		}
	} 
	
	// 计算每一层的叶子节点 
	findLeafLevel();
	// 输出 
	output(); 
	return 0;
}


