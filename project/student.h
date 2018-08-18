#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 100

typedef struct{
	char cNumber[10];
	char cName[10];
	int point;
}Course;

typedef struct CNode {
	Course data;
	int length;
	CNode *next;
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

CNode *p;
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

// ��ʼ���γ̱�
int initCourseList (CourseList &L) {
	L = new CNode;
	L->next = NULL;
	L->length = 0;
	return 1;
}

// ��ȡĳ���γ���Ϣ
int getCourse(CourseList L, int i, Course &e) {
	p = L->next;
	int j = 1;
	while(p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) {
		return -1;
	}
	e = p->data;
	return 1;
} 

// ���ҿγ�Ϊxxx����Ϣ
CNode *locateElem (CourseList L, Course e) {
	p = L->next;
	while (p && (strcmp(p->data.cNumber, e.cNumber) != 0)) {
		p = p->next;
	}
	return p;
} 

// ����ĳ���γ� 
int insertCourse(CourseList &L, int i, Course e) {
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
	s->data = e;
	s->next = p->next;
	p->next = s;
	L->length++;
	return 1;
} 
