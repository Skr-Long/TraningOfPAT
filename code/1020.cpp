#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
struct node{
	int value;
	node *left, *right;
};

int pre[maxn], in[maxn], post[maxn]; // ��, ��, �����������
int n; // �ڵ���

node* create(int psL, int psR, int inL, int inR){
	if(psL > psR){// ����������г���С��0, ֱ�ӷ��� 
		return NULL;
	}
	
	// ����������һ����Ϊ��ǰ���ĸ��ڵ� 
	node* root = new node;
	root->value = post[psR];
	
	int k;
	for(int i = inL; i <= inR; ++i){// �ҵ������������������ 
		if(in[i] == post[psR]){
			k = i;
			break;
		}
	} 
	
	int numLeft = k - inL; // �ҵ���ǰ�ڵ������������� 
	root->left = create(psL, psL + numLeft - 1, inL, k - 1);
	root->right = create(psL + numLeft, psR - 1, k + 1, inR);
	return root;
} 

int num = 0;
void BFS(node* root){// ʹ��BFS������, ���в�α��� 
	queue<node*> q;
	q.push(root); 
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d", now->value);
		num++;
		if(num < n) printf(" ");
		if(now->left != NULL) q.push(now->left);
		if(now->right != NULL) q.push(now->right); 
	}
	
	
}

int main(){	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &post[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &in[i]);
	}
	
	node* root = create(0, n-1, 0, n-1);
	BFS(root);
	
	return 0;
}
