#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;

struct Book{
	int id;
	string title;
	string author;
	string key_words;
	string publisher;
	string published_year; 
}temp;

typedef set<int> Set;
typedef map<string, Set > MAP;
typedef pair<string, Set > PAIR;

// 用来处理数据, 建立映射表
// 0 表示 title 的处理 
// 1 表示 author 的处理
// 2 表示 key_words 的处理
// 3 表示 publisher 的处理
// 4 表示 published_year 的处理 
MAP process_map[5];  

void add_id(const string key, int id, int i){
	MAP::iterator it = process_map[i].find(key);
	if(it == process_map[i].end()){
		Set temp;
		temp.insert(id);
		process_map[i].insert(PAIR(key, temp));
	}else{
		(it->second).insert(id);
	} 
} 

void output_set(const Set list_id){// 输出查询的set 
	for(Set::iterator it = list_id.begin(); it != list_id.end(); ++it){
		printf("%07d\n", *it);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		// 获取数据 
		scanf("%d\n", &temp.id);
		getline(cin, temp.title);
		getline(cin, temp.author);
		getline(cin, temp.key_words);
		getline(cin, temp.publisher);
		getline(cin, temp.published_year);
		
		// 处理数据 
		int id = temp.id;
		// 1. 处理title
		add_id(temp.title, id, 0);
		// 2. 处理author
		add_id(temp.author, id, 1); 
		// 3. 处理key_words
		istringstream is(temp.key_words);
		string sub_key_word;
		while(getline(is, sub_key_word, ' ')){
			add_id(sub_key_word, id, 2);
		}
		// 4. 处理publisher
		add_id(temp.publisher, id, 3);
		// 5. 处理published_year
		add_id(temp.published_year, id, 4); 
	}

	// 查询
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i){// 查询 
		int qId;
		string qS;
		scanf("%d: ", &qId);
		getline(cin, qS); 
		printf("%d: ", qId);
		cout << qS << endl; 
		
		MAP::iterator it = process_map[qId - 1].find(qS);
		if(it == process_map[qId-1].end()){
			printf("Not Found\n");
		}else{
			output_set(it->second);
		}		
	} 
		
	return 0;
}
