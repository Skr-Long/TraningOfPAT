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

// ������������, ����ӳ���
// 0 ��ʾ title �Ĵ��� 
// 1 ��ʾ author �Ĵ���
// 2 ��ʾ key_words �Ĵ���
// 3 ��ʾ publisher �Ĵ���
// 4 ��ʾ published_year �Ĵ��� 
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

void output_set(const Set list_id){// �����ѯ��set 
	for(Set::iterator it = list_id.begin(); it != list_id.end(); ++it){
		printf("%07d\n", *it);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		// ��ȡ���� 
		scanf("%d\n", &temp.id);
		getline(cin, temp.title);
		getline(cin, temp.author);
		getline(cin, temp.key_words);
		getline(cin, temp.publisher);
		getline(cin, temp.published_year);
		
		// �������� 
		int id = temp.id;
		// 1. ����title
		add_id(temp.title, id, 0);
		// 2. ����author
		add_id(temp.author, id, 1); 
		// 3. ����key_words
		istringstream is(temp.key_words);
		string sub_key_word;
		while(getline(is, sub_key_word, ' ')){
			add_id(sub_key_word, id, 2);
		}
		// 4. ����publisher
		add_id(temp.publisher, id, 3);
		// 5. ����published_year
		add_id(temp.published_year, id, 4); 
	}

	// ��ѯ
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i){// ��ѯ 
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
