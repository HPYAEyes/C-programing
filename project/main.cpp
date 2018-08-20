#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "student.h"
using namespace std;
int main () {
	StudentList stuList;
	FILE *fp1, *fp2;
	char str[100];
	int choose, fileFlag = 0;
	initStudentList(stuList);
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
				{
					if (fileFlag == 1) {
						cout<<"您已经创建过学生信息了！请不要重复操作！"<<endl;
						system("pause");
						system("CLS");
						break;
					}
					fp1 = fopen("student.txt", "r");
					fp2 = fopen("course.txt", "r");
					system("CLS");
					if (fp1 == NULL || fp2 == NULL) {
						cout<<"文件读取失败!"<<endl;
						exit(-1);
					} else {
						while (!feof(fp1)) {
							Student s;
							fscanf(fp1, "%s %s %s %s %s %s %s %s", s.number, s.name, s.gender, s.birth, s.from, s.face, s.mobile, s.address);
							insertStudent(stuList, stuList.length+1, s);
						}
						while(!feof(fp2)) {
							char sNum[10], cNum[10], cName[20];
							int score, location;
							fscanf(fp2, "%s %s %s %d", sNum, cNum, cName, &score);
							location = locateStudent(stuList, sNum);
							if (location != 0) {
								addCourse(stuList.elem[location-1].head, 1, cNum, cName, score);
							}
						}
					}
					fclose(fp1);
					fclose(fp2);
					cout<<"创建成功！"<<endl;
					fileFlag = 1;
					system("pause");
					system("CLS");
					break;
				}
				
			case 2:
				{
					system("CLS");
					if (stuList.length == 0) {
						cout<<"暂无学生信息！"<<endl;
						system("pause");
						system("CLS");
						break;
					}
					for (int i = 0; i < stuList.length; i++) {
						displayStudentInfo(stuList, i+1);
						cout<<endl<<endl;
					}
					system("pause");
					system("CLS");
					break;
				}
				
			case 3:
				{
					system("CLS");
					char sNumber[10];
					int location;
					cout<<"请输入学号："<<endl;
					cin>>sNumber;
					location = locateStudent(stuList, sNumber);
					if (location == 0) {
						 cout<<"没有该学生！"<<endl;
						 system("pause");
						 system("CLS");
						 break;
					}
					if (stuList.elem[location-1].head->length == 0) {
						createCourse(stuList.elem[location-1].head);
					} else {
						insertCourse(stuList.elem[location-1].head, 1);
					}				
					cout<<"添加成功！"<<endl;
					system("pause");
					system("CLS");
					break;
				}
			
			case 4:
				{
					system("CLS");
					char sNumber[10];
					int location;
					cout<<"请输入学号："<<endl;
					cin>>sNumber;
					location = locateStudent(stuList, sNumber);
					if (location == 0) {
						 cout<<"没有该学生！"<<endl;
						 system("pause");
						 system("CLS");
						 break;
					}
					travelCourse(stuList.elem[location-1].head);
					int aver = countAver(stuList.elem[location-1]);
					if (aver != -1) {
						cout<<"平均成绩:"<<endl;
						cout<<aver<<endl; 
						system("pause");
						system("CLS");
					}
					break;
				}
			case 5: 
			{
				system("CLS");
				int select;
				do{
					cout<<"****************************************"<<endl;
					cout<<"1--------------根据学号查找"<<endl;
					cout<<"2--------------根据姓名查找"<<endl;
					cout<<"0--------------返回上一级"<<endl;
					cout<<"****************************************"<<endl;
					cin>>select;
					if (select == 1) {
						char sNumber[10];
						int location;
						cout<<"请输入学号："<<endl;
						cin>>sNumber;
						location = locateStudent(stuList, sNumber);
						if (location == 0) {
							cout<<"没有该学生！"<<endl;
							system("pause");
							system("CLS");
							break;
						} else {
							displayStudentInfo(stuList, location);
							system("pause");
							system("CLS");
						}
					} else if (select == 2) {
						char sName[10];
						int location;
						cout<<"请输入姓名："<<endl;
						cin>>sName;
						location = searchStudentByName(stuList, sName);
						if (location == 0) {
							cout<<"没有该学生！"<<endl;
							break;
						} else {
							displayStudentInfo(stuList, location);
							system("pause");
							system("CLS");
						}
					}
				} while (select != 0);
				break;
			}
			case 6:{
				system("CLS");
				int select;
				do{
					cout<<"****************************************"<<endl;
					cout<<"1--------------根据学号排序"<<endl;
					cout<<"2--------------根据平均成绩排序"<<endl;
					cout<<"0--------------返回上一级"<<endl;
					cout<<"****************************************"<<endl;
					cin>>select;
					if (select == 1) {
						system("CLS");
//						char sNum[100][10], temp[100];
//						for (int i = 0; i < stuList.length; i++) {
//							strcpy(sNum[i],stuList.elem[i].number);
//						}
//						sortByStudentNumber(sNum, stuList.length); 
						sortByStudentNumber(stuList);
						for (int i = 0; i < stuList.length; i++) {
							displayStudentInfo(stuList, i);
							cout<<endl<<endl;
						}
						system("pause");
						system("CLS");
					} else if (select == 2) {
						// TODO 根据平均成绩排序 
						int point[100];
						
						system("pause");
						system("CLS");
					}
				} while (select != 0);
				break;
			}
			case 7:{
				system("CLS");
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
				int item = stuList.length + 1;
				insertStudent(stuList, item, stu);
				system("CLS");
				cout<<"插入成功！"<<endl;
				system("pause");
				system("CLS");
				break;
			}
			case 8:{
				char sNumber[10];
				int location;
				cout<<"请输入学号："<<endl;
				cin>>sNumber;
				location = locateStudent(stuList, sNumber);
				if (location == 0) {
					cout<<"没有该学生！"<<endl;
					system("pause");
					system("CLS");
					break;
				} else {
					deleteStudent(stuList, location);
					cout<<"删除成功！"<<endl;
					system("pause");
					system("CLS");
				}
				break;
			}
				
		} 
	} while(choose != 9);
	return 0;
}
