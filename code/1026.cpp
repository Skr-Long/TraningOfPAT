#include <bits/stdc++.h>
using namespace std;

const int K = 111;
const int INF = 1e9;
struct Player{
	// 到达时间, 训练开始时间, 训练时间 
	int arriveTime, startTime, trainTime;
	// 是否是VIP 
	bool isVip; 
}newPlayer; // 存放临时球员 

struct Table{
	// 当前球桌球员结束时间, 已经训练的人数 
	int endTime, numServie;
	// 是否是vip
	bool isVip; 
}table[K];

// 球员队列 
vector<Player> player;

int convertTime(int h, int m, int s){// 将时间转化为秒 
	return h*3600 + m*60 + s;
}

bool cmpArriveTime(Player a, Player b){// 到达时间排序 
	return a.arriveTime < b.arriveTime;
} 

bool cmpStartTime(Player a, Player b){ // 开始时间排序 
	return a.startTime < b.startTime;
}

int nextVIPPlayer(int VIPi){// 编号VIPi从当前VIP球员移到下一个VIP球员 
	VIPi++; // 先将当前VIPi加一, 为什么? 因为当前VIPi已经服务过了, 那么下一个开始判断是否是VIP 
	while(VIPi < player.size() && player[VIPi].isVip == 0){// 在Player内部, 同时不是VIP才加1 
		VIPi++;
	} 
	return VIPi; // 返回VIPi球员的ID, 如果VIPi == player.size() ==> 说明了没有VIP会员了 
}

void allotTable(int pID, int tID){// 将tID的球桌分配给pID的球员 
	if(player[pID].arriveTime <= table[tID].endTime){// 更新球员的开始时间 
		player[pID].startTime = table[tID].endTime;
	} else {
		player[pID].startTime = player[pID].arriveTime;
	}
	// 更新球桌的训练结束时间 =  新球员的结束时间 
	// 更新球桌的服务人数+1 
	table[tID].endTime = player[pID].startTime + player[pID].trainTime;
	table[tID].numServie++;
}


int main(){
	int n, k, m, vipTable;
	// 球员数量 
	scanf("%d", &n);
	// 开门, 关门时间 
	int stTime = convertTime(8, 0, 0); 
	int edTime = convertTime(21, 0, 0); 
	
	for(int i = 0; i < n; ++i){
		int h, m, s, trainTime, isVip;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &trainTime, &isVip);
		// 先计算到达时间, 如果到达时间都大于关门时间, 直接跳过不记录 
		newPlayer.arriveTime = convertTime(h, m, s);
		if(newPlayer.arriveTime >= edTime) continue;
		// 开始训练时间, 训练时长, 是否是vip 
		newPlayer.startTime = edTime;
		newPlayer.trainTime = trainTime <= 120 ? convertTime(0, trainTime, 0) : convertTime(0, 120, 0); 
		newPlayer.isVip = isVip;
		// 将新球员添加进队列
		player.push_back(newPlayer); 
	}
	
	// 球桌数以及vip球桌数 
	scanf("%d %d", &k, &m);
	for(int i = 1; i <= k; ++i){// 更新球桌的结束时间, 刚开始的时候都是开门时间 同时更新服务人数为0, 都为普通球桌 
		table[i].endTime = stTime;
		table[i].numServie = table[i].isVip = 0;
	}
	for(int i = 0; i < m; ++i){// 更新vip球桌 
		scanf("%d", &vipTable);
		table[vipTable].isVip = 1;
	} 
	
	// 根据到达时间对球员进行排序 
	sort(player.begin(), player.end(), cmpArriveTime);
	
	// i 扫描所有的球员, VIPi扫描指向当前的最前面VIP球员 
	int i = 0, VIPi = -1;
	// 找到第一个VIP球桌 
	VIPi = nextVIPPlayer(VIPi); 
	while(i < player.size()){
		// 寻找最早能空闲的球桌 
		int idx = -1, minEndTime = INF;
		for(int j = 1; j <= k; j++){
			if(table[j].endTime < minEndTime){
				minEndTime = table[j].endTime;
				idx = j; 
			}
		}
		// idx 为最早空闲球桌
		if(table[idx].endTime >= edTime) break; // 已经关门, 直接GG
		if(player[i].isVip == 1 && i < VIPi){// 如果i是VIP球员, 但是i<VIPi, 那么说明这个i这个vip球员已经训练了 
			i++;
			continue; 
		} 
		if(table[idx].isVip == 1){
			if(player[i].isVip == 1){// a. 球桌是vip, 球员是vip 
				allotTable(i, idx);	// 将球桌分配给idx
				if(VIPi == i) VIPi = nextVIPPlayer(VIPi);
				i++; 
			}else{// b. 球桌是vip, 但是球员不是vip 
				if(VIPi < player.size() && player[VIPi].arriveTime <= table[idx].endTime){// 如果vipi来的在最早空闲服务结束之前, 应该将这个球桌分配给他 
					allotTable(VIPi, idx);
					VIPi = nextVIPPlayer(VIPi);
				}else{// vip来的比这个时间晚, 仍然将这个球桌分配给球员 
					allotTable(i, idx);
					i++;
				}
			}
		}else{
			if(player[i].isVip == 0){// c. 球桌不是vip, 球员不是vip 
				allotTable(i, idx);
				i++; 
			}else{// d. 球桌不是vip, 球员是vip 
				// 找到最早空闲的vip球桌 
				int VIPidx = -1, minVIPEndTime = INF;
				for(int j = 1; j <= k; j++){
					if(table[j].isVip == 1 && table[j].endTime < minVIPEndTime){
						minVIPEndTime = table[j].endTime;
						VIPidx = j;
					}
				}
				if(VIPidx != -1 && player[i].arriveTime >= table[VIPidx].endTime){// vip球员来的早, 分配给他 
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
