#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 100

typedef struct CNode {
	int cNumber;
	char cName[10];
	int point;
	int length;
	struct CNode *next;
}CNode, *CourseList;

typedef struct {
	char number[10];
	char name[10];
	char gender[10];
	char birth[8];
	char from[10];
	char face[10];
	char mobile[11];
	char address[30];
	CNode *head;
}Student;
typedef struct {
	Student *elem;
	int length;
}StudentList;



// ��ʼ���γ̱�
int initCourseList (CourseList &L) {
	L = new CNode;
	L->next = NULL;
	L->length = 0;
	return 1;
}

// ��ȡĳ���γ���Ϣ
int getCourse(CourseList L, int i, int &num, char name[10], int &score) {
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

// ���ݿγ̺Ų��ҿγ���Ϣ
CNode *locateElem (CourseList L, int num) {
	CNode *p;
	p = L->next;
	while (p && num == p->cNumber) {
		p = p->next;
	}
	return p;
} 

// ����ĳ���γ� 
int insertCourse(CourseList &L, int i, int num, char name[10], int score) {
	CNode *p;
	CNode *s;
	p = L;
	int j = 0;
	while (p && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) {
		return -1;
	}
	s = new CNode;
	strcpy(s->cName,name);
	s->cNumber = num;
	s->point = score;
	s->next = p->next;
	p->next = s;
	L->length++;
	return 1;
} 

// �����γ���Ϣ
void createCourse(CourseList &L) {
	int i = 1;
	CNode *p;
	L = new CNode;
	L->next = NULL;
	while(i) {
		p = new CNode;
		cout<<"������γ̺ţ�"<<endl;
		cin>>p->cNumber;
		cout<<"������γ�����"<<endl;
		cin>>p->cName;
		cout<<"������ɼ���"<<endl;
		cin>>p->point;
		p->next = L->next;
		L->next = p;
		cout<<"��1�������룬����0�˳�"<<endl;
		cin>>i;
		
	}
} 

// �����γ���Ϣ 
void travelCourse(CourseList L) {
	CNode *p = L;
	if (L->next == NULL) {
		cout<<"��ѧ����û�пγ���Ϣ"<<endl;
	} else {
		cout<<"�γ̺�|�γ���|�ɼ�"<<endl;
	}
	while(p->next != NULL) {
		p = p->next;
		cout<<p->cNumber<<"|"<<p->cName<<"|"<<p->point<<endl;
	}
}

// ��ʼ��ѧ��˳���
int initStudentList(StudentList &L) {
	L.elem = new Student[MAXSIZE];
	if (!L.elem) {
		exit(-1);
	}
	L.length = 0;
	return 1;
}

// ��ȡ����ѧ����Ϣ
int getStudent(StudentList L, int i, Student &e) {
	if (i < 1 || i > L.length) {
		return -1;
	}
	e = L.elem[i - 1];
	return 1;
}

// ����ѧ�Ų�ѯĳ��ѧ����˳����е�λ��
int locateStudent(StudentList L, char sNumber[10]) {
	for (int i = 0; i < L.length; i++) {
		if (strcmp(L.elem[i].number, sNumber) == 0) {
			return i+1;
		}
	}
	return 0;
}

// ���뵥��ѧ����Ϣ
int insertStudent(StudentList &L, int i, Student e) {
	if (i < 1 || (i > L.length + 1)) {
		return -1;
	}
	if (L.length == MAXSIZE) {
		return -1;
	}
	for (int j = L.length -1; j >= i - 1; j--) {
		// ������λ�ú��Ԫ�غ���һλ 
		L.elem[j + 1] = L.elem[j];
	}
	// ����Ԫ��e 
	L.elem[i - 1] = e;
	initCourseList(L.elem[i-1].head);
	++L.length;
	return 1;
}

// ɾ������ѧ����Ϣ
int deleteStudent(StudentList &L, int i) {
	if (i < 1 || (i > L.length)) {
		return -1;
	}
	for (int j = i; j <= L.length - 1; j++) {
		// ��ɾ��Ԫ��֮���Ԫ��ǰ��һλ 
		L.elem[j - 1] = L.elem[j];
	}
	--L.length;
	return 1;
}

// ͳ��ĳѧ�����пγ̵�ƽ���ɼ�
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
		cout<<"��ѧ����û���κογ̣�"<<endl;
	}
	return sum/i;
} 

