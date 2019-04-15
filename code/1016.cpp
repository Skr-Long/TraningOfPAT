#include <bits/stdc++.h>
using namespace std;

const int maxn = 1111;

struct Record{
	char name[22];
	char time[20];
	bool is_online;
}records[maxn];

int hourCharge[24]; // һ����ÿСʱ�շ�
int n; // ��¼���� 

bool cmp(Record a, Record b){
	if(strcmp(a.name, b.name) < 0) return true;
	else if(strcmp(a.name, b.name) == 0 && strcmp(a.time, b.time) < 0) return true;
	else return false;
}

int get_month(char* time){
	return (time[0]-'0')*10 + (time[1]-'0');
} 

int get_mintinue(char *time){// ��õ�ǰʱ���ʾ�Ķ��ٷ��� 
	int days = (time[3] - '0')*10 + (time[4] - '0');
	int hours = (time[6] - '0')*10 + (time[7] - '0');
	int mintinues = (time[9] - '0')*10 + (time[10] - '0');
	int total = days*24*60 + hours*60 + mintinues;
	return total;
} 

float get_charges(char *time1, char *time2){ 
	int d1 = (time1[3] - '0')*10 + (time1[4] - '0');
	int h1 = (time1[6] - '0')*10 + (time1[7] - '0');
	int m1 = (time1[9] - '0')*10 + (time1[10] - '0');
	int d2 = (time2[3] - '0')*10 + (time2[4] - '0');
	int h2 = (time2[6] - '0')*10 + (time2[7] - '0');
	int m2 = (time2[9] - '0')*10 + (time2[10] - '0');
	
	
	float money = 0.0; 
	while(d1 < d2 || h1 < h2 || m1 < m2){
		m1++;
		money += hourCharge[h1];
		if(m1 >= 60){
			m1 = 0;
			h1++;
		}  
		if(h1 >= 24){
			h1 = 0;
			d1++;
		}
	}
	
	return money/100.0;
}

int main(){
	// ��ʼ��,����,�洢���� 
	memset(records, 0, sizeof(records));
	for(int i = 0; i < 24; ++i){// �洢ÿ��24h��ÿ���ӻ��� cent/mintinue 
		scanf("%d", &hourCharge[i]);
	}
	scanf("%d", &n);
	for(int i =0; i < n; ++i){
		char status[10];
		scanf("%s %s %s", records[i].name, records[i].time, status);
		if(status[1] == 'n') records[i].is_online = true;
		else records[i].is_online = false; 
	}
	
	// ����
	sort(records, records+n, cmp);
	
	// ��˳����
	int curIndex = 0;
	int igore = 0; 
	float total = 0; 
	int curMonth = get_month(records[curIndex].time); 
	
	for(int i = 0; i < n; i += igore){
		if(curIndex == i){// ��ӡ�˿����Լ����� 
			printf("%s %02d\n", records[curIndex].name, curMonth);
		} 
		
		if((i+1 < n) // �����ڵ���������м�¼֮�� 
		&& (records[i].is_online == true) // �Ƿ����ڼ�¼ǰ��Ϊon-line��״̬ 
		&& strcmp(records[i].name, records[i+1].name) == 0 // �Ƿ���ͬһ�˿͵ļ�¼ 
		&& strcmp(records[i].time, records[i+1].time) < 0 // ͬһ�˿�, ������¼��ʱ�䲻ͬ 
		&& (records[i].is_online ^ records[i+1].is_online)){// �ж��������ڽڵ��Ƿ���on-line��off-line, ͬʱ�����ڵ�������ڲ� 
			igore = 2;
			int time1 = get_mintinue(records[i].time);
			int time2 = get_mintinue(records[i+1].time);
			float charge1 = get_charges(records[i].time, records[i+1].time);
			total += charge1;
			printf("%s %s %d $%.2f\n", &records[i].time[3], &records[i+1].time[3], time2-time1, charge1);	
		}else{// ֱ���Թ���ǰ������ļ�¼ 
			igore = 1;
		}
		
		if(i+igore >= n || strcmp(records[i].name, records[i+igore].name) != 0){// ���ڲ�ͬ�˿ͽ������ߴﵽ��������ʱ�� 
			printf("Total amount: $%.2f\n", total); // �ڹ˿ͽ������߽�����ʱ���ӡ�ܵĻ���
			total = 0.0;	 
			curIndex = i+igore; 
			curMonth = get_month(records[curIndex].time);
		} 
	} 
		
	return 0;
}
