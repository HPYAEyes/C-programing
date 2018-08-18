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
					initCourseList(stuList.elem[item-1].head);
					system("CLS");
					cout<<"�����ɹ���"<<endl;
				}
				break;
			case 2:
				{
				
					if (stuList.length == 0) {
						cout<<"����ѧ����Ϣ��"<<endl;
						break;
					} else {
						cout<<"ѧ��|����|�Ա�|����|��Դ��|������ò|�ֻ���|סַ"<<endl;
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
				}
				break;
			case 3:
				{
					char sNumber[10];
					int location;
					cout<<"������ѧ�ţ�"<<endl;
					cin>>sNumber;
					location = locateStudent(stuList, sNumber);
					if (location == 0) {
						 cout<<"û�и�ѧ����"<<endl;
						 break;
					}
					createCourse(stuList.elem[location-1].head);
					cout<<"��ӳɹ���"<<endl;
				}
				break;
			case 4:
				{
					char sNumber[10];
					int location;
					cout<<"������ѧ�ţ�"<<endl;
					cin>>sNumber;
					location = locateStudent(stuList, sNumber);
					if (location == 0) {
						 cout<<"û�и�ѧ����"<<endl;
						 break;
					}
					travelCourse(stuList.elem[location-1].head);
				}
				break;
			
				
		} 
	} while(choose != 9);
	return 0;
}
//void readTxt(string file)
//{
//    ifstream infile; 
//    infile.open(file.data());   //���ļ����������ļ��������� 
//    assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 
//
//    char c;
//    infile >> noskipws;
//    while (!infile.eof())
//    {
//        infile>>c;
//        cout<<c;
//
//    }
//    infile.close();             //�ر��ļ������� 
//}
