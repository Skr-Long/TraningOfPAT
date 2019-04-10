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
  // �����һ��, һ����map�в�����, ���ԾͲ��ж���, ֱ�����
	int k = 0;
	scanf("%d", &k);
	while(k--){
		int a;
		float b;
		scanf("%d %f", &a, &b);	
		terms.insert(PAIR(a, b));
	}
	
	// ����ڶ���, ��Ҫ�ж�֮ǰ�Ƿ����, ���ھ���Ҫ�Եڶ���Ԫ�ظ���, ���Ϊ0, ��ɾ��Ԫ��
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
	// �ж��߽��Ƿ�ȫ��Ϊ������ 
	if(terms.size() == 0){
		printf("0");
		return;
	} 
	
	// ���mapԪ���д���, ��ô��������� 
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
