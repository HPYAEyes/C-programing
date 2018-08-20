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
		cout<<"1--------------����"<<endl;
		cout<<"2--------------��ʾ"<<endl;
		cout<<"3--------------����ɼ�"<<endl;
		cout<<"4--------------ͳ�Ƴɼ�"<<endl;
		cout<<"5--------------����"<<endl;
		cout<<"6--------------����"<<endl;
		cout<<"7--------------����"<<endl;
		cout<<"8--------------ɾ��"<<endl;
		cout<<"9--------------�˳�"<<endl;
		cout<<"****************************************"<<endl;
		cin>>choose;
		switch(choose) {
			case 1:
				{
					if (fileFlag == 1) {
						cout<<"���Ѿ�������ѧ����Ϣ�ˣ��벻Ҫ�ظ�������"<<endl;
						system("pause");
						system("CLS");
						break;
					}
					fp1 = fopen("student.txt", "r");
					fp2 = fopen("course.txt", "r");
					system("CLS");
					if (fp1 == NULL || fp2 == NULL) {
						cout<<"�ļ���ȡʧ��!"<<endl;
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
					cout<<"�����ɹ���"<<endl;
					fileFlag = 1;
					system("pause");
					system("CLS");
					break;
				}
				
			case 2:
				{
					system("CLS");
					if (stuList.length == 0) {
						cout<<"����ѧ����Ϣ��"<<endl;
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
					cout<<"������ѧ�ţ�"<<endl;
					cin>>sNumber;
					location = locateStudent(stuList, sNumber);
					if (location == 0) {
						 cout<<"û�и�ѧ����"<<endl;
						 system("pause");
						 system("CLS");
						 break;
					}
					if (stuList.elem[location-1].head->length == 0) {
						createCourse(stuList.elem[location-1].head);
					} else {
						insertCourse(stuList.elem[location-1].head, 1);
					}				
					cout<<"��ӳɹ���"<<endl;
					system("pause");
					system("CLS");
					break;
				}
			
			case 4:
				{
					system("CLS");
					char sNumber[10];
					int location;
					cout<<"������ѧ�ţ�"<<endl;
					cin>>sNumber;
					location = locateStudent(stuList, sNumber);
					if (location == 0) {
						 cout<<"û�и�ѧ����"<<endl;
						 system("pause");
						 system("CLS");
						 break;
					}
					travelCourse(stuList.elem[location-1].head);
					int aver = countAver(stuList.elem[location-1]);
					if (aver != -1) {
						cout<<"ƽ���ɼ�:"<<endl;
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
					cout<<"1--------------����ѧ�Ų���"<<endl;
					cout<<"2--------------������������"<<endl;
					cout<<"0--------------������һ��"<<endl;
					cout<<"****************************************"<<endl;
					cin>>select;
					if (select == 1) {
						char sNumber[10];
						int location;
						cout<<"������ѧ�ţ�"<<endl;
						cin>>sNumber;
						location = locateStudent(stuList, sNumber);
						if (location == 0) {
							cout<<"û�и�ѧ����"<<endl;
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
						cout<<"������������"<<endl;
						cin>>sName;
						location = searchStudentByName(stuList, sName);
						if (location == 0) {
							cout<<"û�и�ѧ����"<<endl;
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
					cout<<"1--------------����ѧ������"<<endl;
					cout<<"2--------------����ƽ���ɼ�����"<<endl;
					cout<<"0--------------������һ��"<<endl;
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
						// TODO ����ƽ���ɼ����� 
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
				cout<<"������ѧ�ţ�"<<endl;
				cin>>stu.number;
				cout<<"������������"<<endl;
				cin>>stu.name;
				cout<<"�������Ա�"<<endl;
				cin>>stu.gender;
				cout<<"���������գ�"<<endl;
				cin>>stu.birth;
				cout<<"��������Դ�أ�"<<endl;
				cin>>stu.from;
				cout<<"������������ò��"<<endl;
				cin>>stu.face;
				cout<<"�������ֻ��ţ�"<<endl;
				cin>>stu.mobile;
				cout<<"������סַ��"<<endl;
				cin>>stu.address;
				int item = stuList.length + 1;
				insertStudent(stuList, item, stu);
				system("CLS");
				cout<<"����ɹ���"<<endl;
				system("pause");
				system("CLS");
				break;
			}
			case 8:{
				char sNumber[10];
				int location;
				cout<<"������ѧ�ţ�"<<endl;
				cin>>sNumber;
				location = locateStudent(stuList, sNumber);
				if (location == 0) {
					cout<<"û�и�ѧ����"<<endl;
					system("pause");
					system("CLS");
					break;
				} else {
					deleteStudent(stuList, location);
					cout<<"ɾ���ɹ���"<<endl;
					system("pause");
					system("CLS");
				}
				break;
			}
				
		} 
	} while(choose != 9);
	return 0;
}
