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
	} while(choose != 9)
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
