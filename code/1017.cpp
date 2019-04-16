#include<bits/stdc++.h>
using namespace std;

const int K = 111;
const int INF = 1e9;

struct Customer{
	int arriveTime; // ����ʱ�� 
	int serveTime; // ����ʱ�� 
}newCustomer; // ��ʱ�˿ʹ洢 

vector<Customer> cus; // ģ�����
int endTime[K]; // ���ڵķ������ʱ�� 

int cmp(Customer a, Customer b){// Customer�������� 
	return a.arriveTime < b.arriveTime;
} 

int convertTime(int hh, int mm, int ss){// ��ʱ��ת��Ϊ������ʾʱ�� 
	return hh*3600 + mm*60 + ss;
}

int main(){
	int c, w, totalTime; // �˿���, ������, �ܵĵȴ�ʱ��
	scanf("%d %d", &c, &w);
	int stTime = convertTime(8, 0, 0);// ���п���ʱ�� 
	int edTime = convertTime(17, 0, 0);// ���й���ʱ�� 
	
	for(int i = 0; i < w; ++i) endTime[i] = stTime; 
	for(int i = 0; i < c; ++i){// �˿͵���Ϣ 
		int h, m, s, serveTime;
		scanf("%d:%d:%d %d", &h, &m, &s, &serveTime);
		int arriveTime = convertTime(h, m, s);
		if(arriveTime > edTime) continue; // �˿͹��ź���, ������
		newCustomer.arriveTime = arriveTime;
		newCustomer.serveTime = serveTime <= 60 ? serveTime*60 : 3600;// ����ʱ�䳬��1hת��Ϊ1h 
		cus.push_back(newCustomer); 
	}
	
	sort(cus.begin(), cus.end(), cmp); // ���չ˿͵ĵ���ʱ��������� 
	
	for(int i = 0; i < cus.size(); ++i){
		int idx = -1, minEndTime = INF;
		for(int j = 0; j < w; ++j){// �ҵ���С����ʱ��Ĵ���
			if(endTime[j] < minEndTime){
				minEndTime = endTime[j];
				idx = j;
			}			
		} 
		
		if(endTime[idx] < cus[i].arriveTime){// �����С����ʱ��С�ڹ˿͵���ʱ��, �˿�ֱ�ӷ���, ����ȴ� 
			endTime[idx] = cus[i].arriveTime + cus[i].serveTime;
		} else{// �˿�������, ��Ҫ�ȴ� 
			totalTime += (endTime[idx] - cus[i].arriveTime);
			endTime[idx] += cus[i].serveTime;
		}
	}
	
	if(cus.size() == 0) printf("0.0");
	else printf("%.1lf", totalTime/(60.0*cus.size()));
	
	return 0;
} 
