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
	int msum = -1, ls = 0, re = n-1, tempi = 0, temps = 0;
	for(int i = 0; i < n; ++i){
		 temps += emls[i];
		
		 if(temps < 0){ // ���ǰ�����Ϊ����, ֱ���Ժ���Ϊ��ʼΪ���ֵ��� 
		 	temps = 0;
		 	tempi = i+1;
		 } 
		 
		 if(msum < temps){// ���msumС�ڵ�ǰ����, ��˵���������ӵ�������, ������Ҫ�����������Ҳ����� 
		 	msum = temps;
		 	ls = tempi;
		 	re = i;
		 } 
	}
	
	// ���
	if(msum < 0) msum = 0;
	printf("%d %d %d\n", msum, emls[ls], emls[re]); 
	
	return 0;
} 
