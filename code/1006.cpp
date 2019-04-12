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

// n数据条数 
int n;

int main(){
	scanf("%d", &n);
	// id表示编号，sgin 表示登陆时间， sgout表示登出时间
	// inR表示登陆记录， outR表示登出记录
	string id, sgin, sgout;
	MapL inR;
	MapG outR;
	for(int i = 0; i < n; ++i){
		cin >> id >> sgin >> sgout;
		inR.insert(PAIR(sgin, id));
		outR.insert(PAIR(sgout, id)); 
	}
	
	// 输出
	cout << *inR.begin() << " " << *outR.begin() << endl;

	
	return 0;
}
