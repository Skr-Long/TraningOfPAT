#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

typedef pair<int, float> PAIR;
typedef map<int,float, greater<int> >::iterator MAPITERA; 
ostream& operator<<(ostream& out, const PAIR& p){
	return out << p.first << " " << fixed << setprecision(1) << p.second;
}


void input(map<int,float, greater<int> >& terms){
  // 输入第一行, 一定在map中不存在, 所以就不判断了, 直接添加
	int k = 0;
	scanf("%d", &k);
	while(k--){
		int a;
		float b;
		scanf("%d %f", &a, &b);	
		terms.insert(PAIR(a, b));
	}
	
	// 输入第二行, 需要判断之前是否存在, 存在就需要对第二个元素更新, 如果为0, 就删除元素
	scanf("%d", &k);
	while(k--){
		int a;
		float b;
		scanf("%d %f", &a, &b);
		MAPITERA it = terms.find(a);
		if(it == terms.end()){
			terms.insert(PAIR(a, b));
		}
		else{
			float new_second = it->second + b;
			if(fabs(new_second) < 1e-6) terms.erase(it);
			else it->second = new_second;
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
	map<int, float, greater<int> > terms;
	input(terms);
	output(terms);
	
	return 0;
} 
