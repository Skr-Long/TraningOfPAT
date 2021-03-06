#include <bits/stdc++.h>
using namespace std;

struct Student{
	char ID[7];
	char name[11];
	int grade;
}new_stu;

vector<Student> students;

int n, c;
bool cmp_func(Student a, Student b){
	int flag = 0;
	switch(c){
		case 1:
			return strcmp(a.ID, b.ID) < 0;
			break;
		case 2:
			flag = strcmp(a.name, b.name); 
			if(flag != 0) return flag < 0;
			else return strcmp(a.ID, b.ID) < 0;
			break;
		case 3:
			if(a.grade != b.grade) return  a.grade < b.grade;
			else return strcmp(a.ID, b.ID) < 0;
			break;
	}
}

int main(){
	scanf("%d %d", &n, &c);
	for(int i = 0; i < n; ++i){
		scanf("%s %s %d", new_stu.ID, new_stu.name, &new_stu.grade);
		students.push_back(new_stu);
	}
	sort(students.begin(), students.end(), cmp_func);
	for(int i = 0; i < n; ++i){
		printf("%s %s %d\n", students[i].ID, students[i].name, students[i].grade);
	}
	
	return 0;
}
