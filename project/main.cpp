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
				initStudentList(stuList);
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
				insertStudent(stuList, 0, stu);
				Student stu2;
				getStudent(stuList, 0, stu2);
				system("CLS");
				cout<<"创建成功！"<<endl;
				cout<<"学号:"<<stu2.number<<endl; 
				cout<<"姓名:"<<stu2.name<<endl; 
				cout<<"性别:"<<stu2.gender<<endl; 
				cout<<"生日:"<<stu2.birth<<endl; 
				cout<<"生源地:"<<stu2.from<<endl; 
				cout<<"政治面貌:"<<stu2.face<<endl; 
				cout<<"手机号:"<<stu2.mobile<<endl; 
				cout<<"住址:"<<stu2.address<<endl; 
				
		} 
	} while(choose != 9);
	return 0;
}
void readTxt(string file)
{
    ifstream infile; 
    infile.open(file.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    char c;
    infile >> noskipws;
    while (!infile.eof())
    {
        infile>>c;
        cout<<c;

    }
    infile.close();             //关闭文件输入流 
}
