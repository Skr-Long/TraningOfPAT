#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll inf = (1ll<<63)-1;	// inf��long long�������, ������1��long long, ��Ȼ��Ĭ��Ϊint, ����ֱ����� 

void get_digit(string s, vi& num){// num�Ǵ洢stringת��sÿλΪʮ������ֵ������
	int len = s.length();
	for(int i = 0; i < len; ++i){
		if('0' <= s[i] && s[i] <= '9') num.push_back(s[i] - '0');
		else num.push_back(s[i] - 'a' + 10); 
	} 
} 

ll get_value10(vi num, ll radix, ll t){// ��ȡvector<int>��Ӧת��Ϊ10���Ƶ�ֵ
	ll ans = 0;
	for(vi::iterator it = num.begin(); it != num.end(); ++it){
		ans = ans*radix + *it;
		if(ans < 0 || ans > t) return -1;	// ���ans<0, ��ô�϶��������, ���ans > t, ��ôansһ��������t 
	} 
	return ans;
}

int findLargestDigit(vi num2){// ����Ѱ��num2��������
	int ans = -1;
	for(vi::iterator it = num2.begin(); it != num2.end(); ++it){
		if(ans < *it) ans = *it;
	} 
	return ans+1;
}


int cmp(vi num2, ll radix, ll t){// ���ڱȽ� n2 �� n1�Ĳ���
	ll ans = get_value10(num2, radix, t);
	
	if(ans < 0) return -1;		// ���ans < 0, ��˵��������n1,  ����ans���long long(n1 ���ᳬ��long long, ��ô���� n2̫����)
	
	if(ans > t) return -1;		// ans > t, ans̫����, n2 > n1, ˵������̫���� 
	else if(ans == t) return 0; // ans = t, n2 = n1, ��˵��������Ƹպ�����
	else return 1;				// ans < t, ans̫С��, n2 < n1, ˵������̫С�� 
}

ll binarySearch(vi num2, ll left, ll right, ll t){// ���ڶ��ֲ���
	ll mid;
	while(left <= right){
		mid = (left+right)/2;
		int flag = cmp(num2, mid, t);
		if(flag == 0) return mid;
		else if(flag == 1) left = mid + 1;
		else right = mid - 1;
	} 
	return -1;
}



int main(){
	// n1, n2��ʾ������10λ���ַ���, tag��־radix����ǰ��˭�Ľ����� 
	string n1, n2;
	int tag, radix; 
	cin >> n1 >> n2 >> tag >> radix;
	// ������ tag ��ָ��radix��˭�Ľ���, ��ô��Ҫ��n1, n2�û�, �Ա�������
	if(tag == 2) swap(n1, n2); // swap��algorithm�ĺ���
	// ����n1, n2��Ϊvector<int>��ʾÿλ, ��಻����10λ
	vi num1, num2;
	get_digit(n1, num1);
	get_digit(n2, num2);
	// ���n1��ʮ������
	ll t = get_value10(num1, radix, inf); 
	// ���n2�е�������
	ll low = findLargestDigit(num2);	// ����Ϊɶ��low, ��Ϊn2�е�ÿλ���1λ��Ӧ��1�Ľ�����n2����С���� 
	ll high = max(t, low) + 1; 
	ll ans = binarySearch(num2, low, high, t);	// ������Ѱ, t��n1��ʮ����ֵ, ������n2���жϵı�׼ 

	// ���
	if(ans == -1) printf("Impossible\n");
	else printf("%lld\n", ans); 
	
	return 0;	
}



