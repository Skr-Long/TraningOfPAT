#include <bits/stdc++.h>

using namespace std;

typedef pair<int, float> PAIR;
typedef map<int,float, greater<int> > MAP;
typedef map<int,float, greater<int> >::iterator MAPITERA; 
ostream& operator<<(ostream& out, const PAIR& p){
	return out << p.first << " " << fixed << setprecision(1) << p.second;
}


void input(MAP& terms, MAP& result){
  // �����һ��, һ����map�в�����, ���ԾͲ��ж���, ֱ�����
	int k = 0;
	scanf("%d", &k);
	while(k--){
		int a;
		float b;
		scanf("%d %f", &a, &b);	
		terms.insert(PAIR(a, b));
	}
	
	// ����ڶ���, ���ھ���Ҫ�Եڶ���Ԫ�ظ���, ���Ϊ0, ��ɾ��Ԫ��
	scanf("%d", &k);
	while(k--){
		int a;
		float b;
		scanf("%d %f", &a, &b);
		for(MAPITERA it = terms.begin(); it != terms.end(); ++it){// a, first��ָ��, b, second��ϵ�� 
			int new_first = a + it->first; // ����ʽ���, ��ôָ�����
			float new_second = it->second*b;
			MAPITERA _it = result.find(new_first);	// _itѰ��result���Ƿ�����ָͬ����
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
	MAP terms, result;
	input(terms, result);
	output(result);
	
	return 0;
} 
