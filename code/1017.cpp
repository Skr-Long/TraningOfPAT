#include<bits/stdc++.h>
using namespace std;

const int K = 111;
const int INF = 1e9;

struct Customer{
	int arriveTime; // 到达时间 
	int serveTime; // 服务时间 
}newCustomer; // 临时顾客存储 

vector<Customer> cus; // 模拟队列
int endTime[K]; // 窗口的服务结束时间 

int cmp(Customer a, Customer b){// Customer的排序函数 
	return a.arriveTime < b.arriveTime;
} 

int convertTime(int hh, int mm, int ss){// 将时间转换为秒来表示时间 
	return hh*3600 + mm*60 + ss;
}

int main(){
	int c, w, totalTime; // 顾客数, 窗口数, 总的等待时间
	scanf("%d %d", &c, &w);
	int stTime = convertTime(8, 0, 0);// 银行开门时间 
	int edTime = convertTime(17, 0, 0);// 银行关门时间 
	
	for(int i = 0; i < w; ++i) endTime[i] = stTime; 
	for(int i = 0; i < c; ++i){// 顾客的信息 
		int h, m, s, serveTime;
		scanf("%d:%d:%d %d", &h, &m, &s, &serveTime);
		int arriveTime = convertTime(h, m, s);
		if(arriveTime > edTime) continue; // 顾客关门后来, 不计入
		newCustomer.arriveTime = arriveTime;
		newCustomer.serveTime = serveTime <= 60 ? serveTime*60 : 3600;// 服务时间超过1h转换为1h 
		cus.push_back(newCustomer); 
	}
	
	sort(cus.begin(), cus.end(), cmp); // 按照顾客的到来时间进行排序 
	
	for(int i = 0; i < cus.size(); ++i){
		int idx = -1, minEndTime = INF;
		for(int j = 0; j < w; ++j){// 找到最小结束时间的窗口
			if(endTime[j] < minEndTime){
				minEndTime = endTime[j];
				idx = j;
			}			
		} 
		
		if(endTime[idx] < cus[i].arriveTime){// 如果最小结束时间小于顾客到达时间, 顾客直接服务, 无需等待 
			endTime[idx] = cus[i].arriveTime + cus[i].serveTime;
		} else{// 顾客来早了, 需要等待 
			totalTime += (endTime[idx] - cus[i].arriveTime);
			endTime[idx] += cus[i].serveTime;
		}
	}
	
	if(cus.size() == 0) printf("0.0");
	else printf("%.1lf", totalTime/(60.0*cus.size()));
	
	return 0;
} 
