#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
#define MAXSIZE 100

typedef struct Course {
	char cNumber[10];
	char cName[10];
	int point;
	Course *next;
}Course, *CourseList;

typedef struct Student {
	char number[10];
	char name[10];
	char gender[10];
	char birth[8];
	char from[10];
	char face[10];
	char mobile[11];
	char address[30];
	Course *head;
}Student;
typedef struct {
	Student *elem;
	int length;
}StudentList;

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

// 查询某个学生在顺序表中的位置
//int locateStudent(StudentList L, Student e) {
//	for (int i = 0; i < L.length; i++) {
//		if (L.elem[i] == e) {
//			return i+1;
//		}
//	}
//	return 0;
//}

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
