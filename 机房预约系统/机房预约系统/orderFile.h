#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>
#include<string>
class orderFile
{
public:
	orderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������
	//key---�ļ���ԤԼ��¼������(int)��value---�����¼�ļ�ֵ����Ϣ
	//map<string, string>(key-���ԣ�value-ʵֵ)--��¼����һ����¼
	map<int, map<string, string>> m_orderDate;

	//ԤԼ��¼����
	int m_Size;
};

//������������ʾԤԼ��¼ʱ����Ҫ���ļ��л�ȡ���м�¼��
//������ʾ������ԤԼ�����������¼�Լ�����

