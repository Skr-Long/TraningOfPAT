#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, sum = 0;
	scanf("%d", &n);
	int last = 0, now = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &now);
		
		if(now > last){
			sum += (now-last)*6;
		} else {
			sum += (last - now)*4;
		}
		last = now;
	}
	
	sum += 5*n;
	
	printf("%d\n", sum);
	
	return 0;
}
