#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

// emls ��ʾ����Ԫ��
// dp ��ʾ��̬�滮���� 
// s ��ʾ�Ķ�Ӧdp�Ŀ�ʼ�±� 
int emls[MAXN]; 

int main(){
	// ����
	int n; 
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &emls[i]);
	}
	
	// ����һ��	
	int l = 0, r = n-1, sum = -1, tl = 0, temp = 0;
	for(int i = 0; i < n; ++i){
		 temp += emls[i];
		
		 if(temp < 0){ // ���ǰ�����Ϊ����, ֱ���Ժ���Ϊ��ʼΪ���ֵ��� 
		 	temp = 0;
		 	tl = i+1;
		 } else if(sum < temp){// ���msumС�ڵ�ǰ����, ��˵���������ӵ�������, ������Ҫ�����������Ҳ����� 
		 	sum = temp;
		 	l = tl;
		 	r = i;
		 } 
	}
	
	// ���
	if(sum < 0) sum = 0;
	printf("%d %d %d\n", sum, emls[l], emls[r]); 
	
	return 0;
} 
