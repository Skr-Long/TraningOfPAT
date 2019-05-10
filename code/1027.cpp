#include <bits/stdc++.h>
using namespace std;

void convert_color(int c, char* color){
	int left, idx = 0;
	color[0] = '0';
	color[1] = '0'; 
	color[2] = 0;
	
	while(c){
		left = c%13;
		c /= 13;
		if(left >= 10) color[idx++] = 'A'+left-10;
		else if(left < 10) color[idx++] = '0' + left; 
	}
		
	char temp = color[0];
	color[0] = color[1];
	color[1] = temp;
}


int main(){
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	char red[4], green[4], blue[4];
	convert_color(r, red);
	convert_color(g, green);
	convert_color(b, blue);
	printf("#%s%s%s", red, green, blue);
	
	return 0;
} 
