#include <bits/stdc++.h>

using namespace std;

typedef pair<int, float> PAIR;
typedef map<int,float, greater<int> > MAP;
typedef map<int,float, greater<int> >::iterator MAPITERA; 
ostream& operator<<(ostream& out, const PAIR& p){
	return out << p.first << " " << fixed << setprecision(1) << p.second;
}


void input(MAP& terms, MAP& result){
  // 输入第一行, 一定在map中不存在, 所以就不判断了, 直接添加
	int k = 0;
	scanf("%d", &k);
	while(k--){
		int a;
		float b;
		scanf("%d %f", &a, &b);	
		terms.insert(PAIR(a, b));
	}
	
	// 输入第二行, 存在就需要对第二个元素更新, 如果为0, 就删除元素
	scanf("%d", &k);
	while(k--){
		int a;
		float b;
		scanf("%d %f", &a, &b);
		for(MAPITERA it = terms.begin(); it != terms.end(); ++it){// a, first是指数, b, second是系数 
			int new_first = a + it->first; // 多项式相乘, 那么指数相加
			float new_second = it->second*b;
			MAPITERA _it = result.find(new_first);	// _it寻找result中是否有相同指数项
			if(_it == result.end()){
				result.insert(PAIR(new_first, new_second));
			}else{
				new_second += _it->second;
				if(fabs(new_second) < 1e-6) result.erase(_it);
				else _it->second = new_second;
			}
		}
	}
}

void output(map<int, float, greater<int> > terms){
	// 判定边界是否全部为零的情况 
	if(terms.size() == 0){
		printf("0");
		return;
	} 
	
	// 如果map元素中存在, 那么就输出出来 
	cout << terms.size();
	for(MAPITERA it = terms.begin(); it != terms.end(); ++it){
		cout << " " << *it ;
	}
} 


int main(){
	MAP terms, result;
	input(terms, result);
	output(result);
	
	return 0;
} 
