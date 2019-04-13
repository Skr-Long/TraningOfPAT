#include <bits/stdc++.h>
using namespace std;

const int maxm = 2010;
const int maxq = 10000000;

struct Stu{
	int id; // ѧ��id 
	int grade[4]; // ѧ�����ųɼ� 
} stu[maxm];

char course[] = {'A', 'C', 'M', 'E'}; // �γ����� 
int Rank[maxq][4];	// ѧ��idӳ������ſγ̳ɼ����� 
int now; // ��ǰ����Ŀγ̺�


bool cmp(Stu a, Stu b){// sort�ıȽϺ���, ���������� 
	return a.grade[now] > b.grade[now];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){// ���ѧ���ɼ� 
		scanf("%d %d %d %d",&stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]); 
		stu[i].grade[0] =  stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]; // ʹ�óɼ�֮�ʹ���ƽ���ɼ�, ����Ҫ�����Ƿ��������� 
	} 
	
	// �������ſγ�
	for(now = 0; now < 4; ++now){
		sort(stu, stu+n, cmp);
		Rank[stu[0].id][now] = 1;// ���õ�ǰ�ɼ���һ��
		for(int i = 1; i < n; ++i){
			if(stu[i].grade[now] == stu[i-1].grade[now]){
				Rank[stu[i].id][now] = Rank[stu[i-1].id][now];
			} else{
				Rank[stu[i].id][now] = i+1;
			}
		} 
	} 
	
	// ��ѯ
	int query = 0;
	for(int i = 0; i < m; ++i){
		scanf("%d", &query);
		if(Rank[query][0] == 0) printf("N/A\n");	// ���������, ��ô��� N/A 
		else{
			int k = 0;
			for(int j = 0; j < 4; ++j){
				if(Rank[query][k] > Rank[query][j]){
					k = j;
				}
			}
			printf("%d %c\n", Rank[query][k], course[k]);
		}
	} 
	
	return 0;
}
