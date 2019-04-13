#include <bits/stdc++.h>
using namespace std;

typedef map<float, char, greater<float> > mFC; 
typedef pair<float, char> PAIR;

int main(){
	mFC m[3];
	float w, t, l;
	for(int i = 0; i < 3; ++i){
		scanf("%f %f %f", &w, &t, &l);
		m[i].insert(PAIR(w, 'W'));
		m[i].insert(PAIR(t, 'T'));
		m[i].insert(PAIR(l, 'L'));
	}
	
	float value = 1;
	for(int i = 0; i < 3; ++i){
		printf("%c ", m[i].begin()->second);
		value *= m[i].begin()->first;
	}
	value = (value*0.65-1)*2;
	printf("%.2f\n", value);
	
	return 0;
} 
