#include <bits/stdc++.h>
using namespace std;

const int maxk = 1010;
struct Window{
	int endTime, popTime;	// ��ǰ���ڷ������ʱ��, ���׷������ʱ��
	queue<int> q;			// ��ǰ�����Ŷ� 
}windows[20];

// n��ʾ������, m��ʾÿ�����ڻ����ڲ�����, k��ʾ�˿���, query��ʾ��ѯ����
int n,m,k,query;

// ans��ʾ�������ʱ��, need��ʾ������Ҫʱ�� 
int ans[maxk], needTime[maxk]; 

int convertToMintinues(int h, int m){// ��ʱ��ת��Ϊ����, ������� 
	return h*60+m;
}

int main(){
	int inCus = 0; // ��ǰ��һ����δ���еĹ˿�
	scanf("%d%d%d%d", &n, &m, &k, &query);
	for(int i = 0; i < k; ++i){
		scanf("%d", &needTime[i]);
	} 
	for(int i = 0; i < n; ++i){
		windows[i].endTime=windows[i].popTime=convertToMintinues(8, 0);
	}
	
	for(int i = 0; i < min(n*m, k); ++i){// ��ʼ����, ����n*m ���߹˿�����k����n*m 
		windows[inCus%n].q.push(inCus);
		windows[inCus%n].endTime += needTime[inCus];
		if(inCus < n) windows[inCus].popTime = needTime[inCus];
		ans[inCus] = windows[inCus%n].endTime;
		inCus++;
	}
	
	for(; inCus < k; ++inCus){// ����ʣ����� 
		int idx = -1, minPopTime = 1 << 30;
		for(int i = 0; i < n; ++i){// Ѱ�Ҷ����������ʱ��Ĵ��� 
			if(windows[i].popTime < minPopTime){
				idx = i;
				minPopTime = windows[i].popTime;
			}
		}
		
		Window& W = windows[idx]; 
		
		W.q.pop();	// �ȳ����� 
		W.q.push(inCus);	// inCud���
		W.popTime += needTime[W.q.front()];
		W.endTime += needTime[inCus];
		ans[inCus] = W.endTime;
	}
	
	int q;
	int deadLine = convertToMintinues(17, 0); 
	for(int i = 0; i < query; ++i){// �����ѯ
		scanf("%d", &q);
		if(ans[q-1] - needTime[q-1] >= deadLine){
			printf("Sorry\n");
		} else{
			printf("%02d:%02d\n", ans[q-1]/60, ans[q-1]%60);
		}
	}
	
	return 0;
}
