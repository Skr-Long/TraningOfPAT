#include <bits/stdc++.h>
using namespace std;

const int K = 111;
const int INF = 1e9;
struct Player{
	// ����ʱ��, ѵ����ʼʱ��, ѵ��ʱ�� 
	int arriveTime, startTime, trainTime;
	// �Ƿ���VIP 
	bool isVip; 
}newPlayer; // �����ʱ��Ա 

struct Table{
	// ��ǰ������Ա����ʱ��, �Ѿ�ѵ�������� 
	int endTime, numServie;
	// �Ƿ���vip
	bool isVip; 
}table[K];

// ��Ա���� 
vector<Player> player;

int convertTime(int h, int m, int s){// ��ʱ��ת��Ϊ�� 
	return h*3600 + m*60 + s;
}

bool cmpArriveTime(Player a, Player b){// ����ʱ������ 
	return a.arriveTime < b.arriveTime;
} 

bool cmpStartTime(Player a, Player b){ // ��ʼʱ������ 
	return a.startTime < b.startTime;
}

int nextVIPPlayer(int VIPi){// ���VIPi�ӵ�ǰVIP��Ա�Ƶ���һ��VIP��Ա 
	VIPi++; // �Ƚ���ǰVIPi��һ, Ϊʲô? ��Ϊ��ǰVIPi�Ѿ��������, ��ô��һ����ʼ�ж��Ƿ���VIP 
	while(VIPi < player.size() && player[VIPi].isVip == 0){// ��Player�ڲ�, ͬʱ����VIP�ż�1 
		VIPi++;
	} 
	return VIPi; // ����VIPi��Ա��ID, ���VIPi == player.size() ==> ˵����û��VIP��Ա�� 
}

void allotTable(int pID, int tID){// ��tID�����������pID����Ա 
	if(player[pID].arriveTime <= table[tID].endTime){// ������Ա�Ŀ�ʼʱ�� 
		player[pID].startTime = table[tID].endTime;
	} else {
		player[pID].startTime = player[pID].arriveTime;
	}
	// ����������ѵ������ʱ�� =  ����Ա�Ľ���ʱ�� 
	// ���������ķ�������+1 
	table[tID].endTime = player[pID].startTime + player[pID].trainTime;
	table[tID].numServie++;
}


int main(){
	int n, k, m, vipTable;
	// ��Ա���� 
	scanf("%d", &n);
	// ����, ����ʱ�� 
	int stTime = convertTime(8, 0, 0); 
	int edTime = convertTime(21, 0, 0); 
	
	for(int i = 0; i < n; ++i){
		int h, m, s, trainTime, isVip;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &trainTime, &isVip);
		// �ȼ��㵽��ʱ��, �������ʱ�䶼���ڹ���ʱ��, ֱ����������¼ 
		newPlayer.arriveTime = convertTime(h, m, s);
		if(newPlayer.arriveTime >= edTime) continue;
		// ��ʼѵ��ʱ��, ѵ��ʱ��, �Ƿ���vip 
		newPlayer.startTime = edTime;
		newPlayer.trainTime = trainTime <= 120 ? convertTime(0, trainTime, 0) : convertTime(0, 120, 0); 
		newPlayer.isVip = isVip;
		// ������Ա��ӽ�����
		player.push_back(newPlayer); 
	}
	
	// �������Լ�vip������ 
	scanf("%d %d", &k, &m);
	for(int i = 1; i <= k; ++i){// ���������Ľ���ʱ��, �տ�ʼ��ʱ���ǿ���ʱ�� ͬʱ���·�������Ϊ0, ��Ϊ��ͨ���� 
		table[i].endTime = stTime;
		table[i].numServie = table[i].isVip = 0;
	}
	for(int i = 0; i < m; ++i){// ����vip���� 
		scanf("%d", &vipTable);
		table[vipTable].isVip = 1;
	} 
	
	// ���ݵ���ʱ�����Ա�������� 
	sort(player.begin(), player.end(), cmpArriveTime);
	
	// i ɨ�����е���Ա, VIPiɨ��ָ��ǰ����ǰ��VIP��Ա 
	int i = 0, VIPi = -1;
	// �ҵ���һ��VIP���� 
	VIPi = nextVIPPlayer(VIPi); 
	while(i < player.size()){
		// Ѱ�������ܿ��е����� 
		int idx = -1, minEndTime = INF;
		for(int j = 1; j <= k; j++){
			if(table[j].endTime < minEndTime){
				minEndTime = table[j].endTime;
				idx = j; 
			}
		}
		// idx Ϊ�����������
		if(table[idx].endTime >= edTime) break; // �Ѿ�����, ֱ��GG
		if(player[i].isVip == 1 && i < VIPi){// ���i��VIP��Ա, ����i<VIPi, ��ô˵�����i���vip��Ա�Ѿ�ѵ���� 
			i++;
			continue; 
		} 
		if(table[idx].isVip == 1){
			if(player[i].isVip == 1){// a. ������vip, ��Ա��vip 
				allotTable(i, idx);	// �����������idx
				if(VIPi == i) VIPi = nextVIPPlayer(VIPi);
				i++; 
			}else{// b. ������vip, ������Ա����vip 
				if(VIPi < player.size() && player[VIPi].arriveTime <= table[idx].endTime){// ���vipi������������з������֮ǰ, Ӧ�ý��������������� 
					allotTable(VIPi, idx);
					VIPi = nextVIPPlayer(VIPi);
				}else{// vip���ı����ʱ����, ��Ȼ����������������Ա 
					allotTable(i, idx);
					i++;
				}
			}
		}else{
			if(player[i].isVip == 0){// c. ��������vip, ��Ա����vip 
				allotTable(i, idx);
				i++; 
			}else{// d. ��������vip, ��Ա��vip 
				// �ҵ�������е�vip���� 
				int VIPidx = -1, minVIPEndTime = INF;
				for(int j = 1; j <= k; j++){
					if(table[j].isVip == 1 && table[j].endTime < minVIPEndTime){
						minVIPEndTime = table[j].endTime;
						VIPidx = j;
					}
				}
				if(VIPidx != -1 && player[i].arriveTime >= table[VIPidx].endTime){// vip��Ա������, ������� 
					allotTable(i, VIPidx);
					if(VIPi == i) VIPi = nextVIPPlayer(VIPi);
					i++;
				}else{
					allotTable(i, idx);
					if(VIPi == i) VIPi = nextVIPPlayer(VIPi);
					i++; 
				}
			}
		} 
	}
	
	sort(player.begin(), player.end(), cmpStartTime);
	for(int i = 0; i < player.size() && player[i].startTime < edTime; ++i){
		int t1 = player[i].arriveTime;
		int t2 = player[i].startTime;
		printf("%02d:%02d:%02d ", t1/3600, t1%3600/60, t1%60);
		printf("%02d:%02d:%02d ", t2/3600, t2%3600/60, t2%60);
		printf("%.0f\n", round((t2-t1)/60.0));
	}
	for(int i = 1; i <= k; ++i){
		printf("%d", table[i].numServie);
		if(i<k) printf(" ");
	}
	
	return 0;
}
