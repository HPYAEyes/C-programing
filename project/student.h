#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 100

typedef struct CNode {
	char cNumber[10];
	char cName[20];
	int point;
	int length;
	struct CNode *next;
}CNode, *CourseList;

typedef struct {
	char number[10];
	char name[10];
	char gender[10];
	char birth[10];
	char from[10];
	char face[10];
	char mobile[15];
	char address[30];
	CNode *head;
}Student;
typedef struct {
	Student *elem;
	int length;
}StudentList;



// 初始化课程表
int initCourseList (CourseList &L) {
	L = new CNode;
	L->next = NULL;
	L->length = 0;
	return 1;
}

// 获取某个课程信息
int getCourse(CourseList L, int i, char num[10], char name[20], int &score) {
	CNode *p;
	p = L->next;
	int j = 1;
	while(p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) {
		return -1;
	}
	name = p->cName;
	num = p->cNumber;
	score = p->point;
	return 1;
} 

// 根据课程号查找课程信息
CNode *locateElem (CourseList L, char num[10]) {
	CNode *p;
	p = L->next;
	while (p && (strcmp(num, p->cNumber) == 0)) {
		p = p->next;
	}
	return p;
} 

// 插入某个课程 
int insertCourse(CourseList &L, int i) {
	CNode *p;
	CNode *s;
	p = L;
	int j = 0, item = 1;
	while (p && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) {
		return -1;
	}
	while(item) {
		s = new CNode;
		cout<<"请输入课程号："<<endl;
		cin>>s->cNumber;
		cout<<"请输入课程名："<<endl;
		cin>>s->cName;
		cout<<"请输入成绩："<<endl;
		cin>>s->point;
		s->next = p->next;
		p->next = s;
		L->length++;
		cout<<"按1继续输入，否则按0退出"<<endl;
		cin>>item;
	}
	return 1;
} 

// 创建课程信息
void createCourse(CourseList &L) {
	int i = 1;
	CNode *p;
	if (initCourseList(L) != 1) {
		cout<<"初始化课程链表失败！"<<endl; 
		return;
	}
	while(i) {
		p = new CNode;
		cout<<"请输入课程号："<<endl;
		cin>>p->cNumber;
		cout<<"请输入课程名："<<endl;
		cin>>p->cName;
		cout<<"请输入成绩："<<endl;
		cin>>p->point;
		p->next = L->next;
		L->next = p;
		L->length++;
		cout<<"按1继续输入，否则按0退出"<<endl;
		cin>>i;
		
	}
} 

// 遍历课程信息 
void travelCourse(CourseList L) {
	CNode *p = L;
	if (L->next == NULL) {
		cout<<"该学生还没有课程信息"<<endl;
		return;
	} else {
		cout<<"课程号|课程名|成绩"<<endl;
	}
	while(p->next != NULL) {
		p = p->next;
		cout<<p->cNumber<<"|"<<p->cName<<"|"<<p->point<<endl;
	}
}
// 统计某学生所有课程的平均成绩
int countAver(Student stu) {
	int sum, i = 0;
	CNode *p = stu.head;
	if (stu.head->next != NULL) {
		while(p->next != NULL) {
			p = p->next;
			sum += p->point;
			i++;
		}
	} else {
		cout<<"该学生还没有任何课程！"<<endl;
		return -1;
	}
	return sum/i;
} 

// 初始化学生顺序表
int initStudentList(StudentList &L) {
	L.elem = new Student[MAXSIZE];
	if (!L.elem) {
		exit(-1);
	}
	L.length = 0;
	return 1;
}

// 获取单个学生信息
int getStudent(StudentList L, int i, Student &e) {
	if (i < 1 || i > L.length) {
		return -1;
	}
	e = L.elem[i - 1];
	return 1;
}

// 根据学号查询某个学生在顺序表中的位置
int locateStudent(StudentList L, char sNumber[10]) {
	for (int i = 0; i < L.length; i++) {
		if (strcmp(L.elem[i].number, sNumber) == 0) {
			return i+1;
		}
	}
	return 0;
}

// 根据姓名查询学生 
int searchStudentByName(StudentList L, char sName[10]) {
	for (int i = 0; i < L.length; i++) {
		if (strcmp(L.elem[i].name, sName) == 0) {
			return i+1;
		}
	}
	return 0;
}

// 显示查询到的学生信息 
void displayStudentInfo(StudentList L, int location) {
	Student s;
	getStudent(L, location, s);
	cout<<"学号|姓名|性别|生日|生源地|政治面貌|手机号|住址|平均成绩"<<endl;
	cout<<s.number<<" | ";
	cout<<s.name<<" | ";
	cout<<s.gender<<" | ";
	cout<<s.birth<<" | ";
	cout<<s.from<<" | ";
	cout<<s.face<<" | ";
	cout<<s.mobile<<" | ";
	cout<<s.address<<" | ";
	int avg = countAver(s);
	if (avg == -1) {
		cout<<"暂无"<<endl;
	} else {
		cout<<avg<<endl;
	}
	travelCourse(s.head);
	cout<<"请按任意键继续..."<<endl;
	getch();
	system("CLS");
}

// 插入单个学生信息
int insertStudent(StudentList &L, int i, Student e) {
	if (i < 1 || (i > L.length + 1)) {
		return -1;
	}
	if (L.length == MAXSIZE) {
		return -1;
	}
	for (int j = L.length -1; j >= i - 1; j--) {
		// 将插入位置后的元素后移一位 
		L.elem[j + 1] = L.elem[j];
	}
	// 插入元素e 
	L.elem[i - 1] = e;
	initCourseList(L.elem[i-1].head);
	++L.length;
	return 1;
}

// 删除单个学生信息
int deleteStudent(StudentList &L, int i) {
	if (i < 1 || (i > L.length)) {
		return -1;
	}
	for (int j = i; j <= L.length - 1; j++) {
		// 被删除元素之后的元素前移一位 
		L.elem[j - 1] = L.elem[j];
	}
	--L.length;
	return 1;
}


