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
	} while(choose != 9)
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
