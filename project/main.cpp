#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include "student.h"
using namespace std;
void readTxt(string file);
int main () {
	StudentList stuList;
	CourseList courseList;
	FILE *fp1, *fp2;
	char str[100];
	int choose;
//	readTxt("d:\\test.txt");
	initStudentList(stuList);
	initCourseList(courseList);
	do {
		cout<<"****************************************"<<endl;
		cout<<"1--------------创建"<<endl;
		cout<<"2--------------显示"<<endl;
		cout<<"3--------------输入成绩"<<endl;
		cout<<"4--------------统计成绩"<<endl;
		cout<<"5--------------查找"<<endl;
		cout<<"6--------------排序"<<endl;
		cout<<"7--------------插入"<<endl;
		cout<<"8--------------删除"<<endl;
		cout<<"9--------------退出"<<endl;
		cout<<"****************************************"<<endl;
		cin>>choose;
		switch(choose) {
			case 1:
				Student stu;
				cout<<"请输入学号："<<endl;
				cin>>stu.number;
				cout<<"请输入姓名："<<endl;
				cin>>stu.name;
				cout<<"请输入性别："<<endl;
				cin>>stu.gender;
				cout<<"请输入生日："<<endl;
				cin>>stu.birth;
				cout<<"请输入生源地："<<endl;
				cin>>stu.from;
				cout<<"请输入政治面貌："<<endl;
				cin>>stu.face;
				cout<<"请输入手机号："<<endl;
				cin>>stu.mobile;
				cout<<"请输入住址："<<endl;
				cin>>stu.address;
				insertStudent(stuList, stuList.length+1, stu);
				system("CLS");
				cout<<"创建成功！"<<endl;
				break;
			case 2:
				if (stuList.length == 0) {
					cout<<"暂无学生信息！"<<endl;
					break;
				} else {
					cout<<"学号|姓名|性别|生日|生源地|政治面貌|手机号|住址"<<endl;
				}
				for (int i = 0; i < stuList.length; i++) {
					cout<<stuList.elem[i].number<<"|";
					cout<<stuList.elem[i].name<<"|";
					cout<<stuList.elem[i].gender<<"|";
					cout<<stuList.elem[i].birth<<"|";
					cout<<stuList.elem[i].from<<"|";
					cout<<stuList.elem[i].face<<"|";
					cout<<stuList.elem[i].mobile<<"|";
					cout<<stuList.elem[i].address<<endl;
				}
				break;
			case 3:
//				Student stu1;
//				getStudent(stuList, 2, stu1);
//				int i;
//				i = locateStudent(stuList, stu1);
//				cout<<i<<endl;
				Course crs;
				char sNumber[10];
				int location;
				cout<<"请输入学号："<<endl;
				cin>>sNumber;
				location = locateStudent(stuList, sNumber);
				if (location == 0) {
					 cout<<"没有该学生！"<<endl;
					 break;
				}
				cout<<"请输入课程号："<<endl;
				cin>>crs.cNumber;
				cout<<"请输入课程名："<<endl;
				cin>>crs.cName;
				cout<<"请输入成绩："<<endl;
				cin>>crs.point;
				insertCourse(stuList.elem[location-1].head, 1, crs);
				cout<<stuList.elem[location-1].head->data.point<<endl;
				cout<<"添加成功！"<<endl;
				break;
				
		} 
	} while(choose != 9);
	return 0;
}
//void readTxt(string file)
//{
//    ifstream infile; 
//    infile.open(file.data());   //将文件流对象与文件连接起来 
//    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
//
//    char c;
//    infile >> noskipws;
//    while (!infile.eof())
//    {
//        infile>>c;
//        cout<<c;
//
//    }
//    infile.close();             //关闭文件输入流 
//}
