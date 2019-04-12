#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;

typedef map<string, string, greater<string> > MapG;
typedef map<string, string> MapL;
typedef pair<string, string> PAIR;

ostream& operator<<(ostream& out, const PAIR& p){
	return out << p.second;
}

// n�������� 
int n;

int main(){
	scanf("%d", &n);
	// id��ʾ��ţ�sgin ��ʾ��½ʱ�䣬 sgout��ʾ�ǳ�ʱ��
	// inR��ʾ��½��¼�� outR��ʾ�ǳ���¼
	string id, sgin, sgout;
	MapL inR;
	MapG outR;
	for(int i = 0; i < n; ++i){
		cin >> id >> sgin >> sgout;
		inR.insert(PAIR(sgin, id));
		outR.insert(PAIR(sgout, id)); 
	}
	
	// ���
	cout << *inR.begin() << " " << *outR.begin() << endl;

	
	return 0;
}
