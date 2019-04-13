#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll inf = (1ll<<63)-1;	// inf是long long的最大数, 必须标记1是long long, 不然会默认为int, 导致直接溢出 

void get_digit(string s, vi& num){// num是存储string转换s每位为十进制数值的容器
	int len = s.length();
	for(int i = 0; i < len; ++i){
		if('0' <= s[i] && s[i] <= '9') num.push_back(s[i] - '0');
		else num.push_back(s[i] - 'a' + 10); 
	} 
} 

ll get_value10(vi num, ll radix, ll t){// 获取vector<int>对应转换为10进制的值
	ll ans = 0;
	for(vi::iterator it = num.begin(); it != num.end(); ++it){
		ans = ans*radix + *it;
		if(ans < 0 || ans > t) return -1;	// 如果ans<0, 那么肯定是溢出了, 如果ans > t, 那么ans一定超过了t 
	} 
	return ans;
}

int findLargestDigit(vi num2){// 用于寻找num2中最大的数
	int ans = -1;
	for(vi::iterator it = num2.begin(); it != num2.end(); ++it){
		if(ans < *it) ans = *it;
	} 
	return ans+1;
}


int cmp(vi num2, ll radix, ll t){// 用于比较 n2 与 n1的差距的
	ll ans = get_value10(num2, radix, t);
	
	if(ans < 0) return -1;		// 如果ans < 0, 那说明超过了n1,  或者ans溢出long long(n1 不会超过long long, 那么还是 n2太大了)
	
	if(ans > t) return -1;		// ans > t, ans太大了, n2 > n1, 说明进制太大了 
	else if(ans == t) return 0; // ans = t, n2 = n1, 那说明这个进制刚好满足
	else return 1;				// ans < t, ans太小了, n2 < n1, 说明进制太小了 
}

ll binarySearch(vi num2, ll left, ll right, ll t){// 用于二分查找
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
	// n1, n2表示不超过10位的字符串, tag标志radix属于前面谁的进制数 
	string n1, n2;
	int tag, radix; 
	cin >> n1 >> n2 >> tag >> radix;
	// 首先是 tag 会指明radix是谁的进制, 那么需要对n1, n2置换, 以便后面求解
	if(tag == 2) swap(n1, n2); // swap是algorithm的函数
	// 处理n1, n2成为vector<int>表示每位, 最多不超过10位
	vi num1, num2;
	get_digit(n1, num1);
	get_digit(n2, num2);
	// 获得n1的十进制数
	ll t = get_value10(num1, radix, inf); 
	// 获得n2中的最大的数
	ll low = findLargestDigit(num2);	// 至于为啥是low, 因为n2中的每位最大1位对应加1的进制是n2的最小进制 
	ll high = max(t, low) + 1; 
	ll ans = binarySearch(num2, low, high, t);	// 二分搜寻, t是n1的十进制值, 是用于n2的判断的标准 

	// 输出
	if(ans == -1) printf("Impossible\n");
	else printf("%lld\n", ans); 
	
	return 0;	
}



