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
	FILE *fp1, *fp2;
	char str[100];
	int choose;
//	readTxt("d:\\test.txt");
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
				initStudentList(stuList);
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
				insertStudent(stuList, 0, stu);
				Student stu2;
				getStudent(stuList, 0, stu2);
				system("CLS");
				cout<<"�����ɹ���"<<endl;
				cout<<"ѧ��:"<<stu2.number<<endl; 
				cout<<"����:"<<stu2.name<<endl; 
				cout<<"�Ա�:"<<stu2.gender<<endl; 
				cout<<"����:"<<stu2.birth<<endl; 
				cout<<"��Դ��:"<<stu2.from<<endl; 
				cout<<"������ò:"<<stu2.face<<endl; 
				cout<<"�ֻ���:"<<stu2.mobile<<endl; 
				cout<<"סַ:"<<stu2.address<<endl; 
				
		} 
	} while(choose != 9);
	return 0;
}
void readTxt(string file)
{
    ifstream infile; 
    infile.open(file.data());   //���ļ����������ļ��������� 
    assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 

    char c;
    infile >> noskipws;
    while (!infile.eof())
    {
        infile>>c;
        cout<<c;

    }
    infile.close();             //�ر��ļ������� 
}
