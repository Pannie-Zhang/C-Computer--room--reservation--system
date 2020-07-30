#pragma once
//#include<cstdlib>  
//#include<windows.h>
#include<iostream>
#include <fstream>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "computerRoom.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class manager:public Identity
{
public:
	//Ĭ�Ϲ���
	manager();

	//�вι��� ������ѧ�š�����������
	manager(string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����˺�
	//��ѧ��������ʦ����µ��˺�
	//���ʱѧ��ѧ�Ų����ظ�����ʦְ���Ų����ظ�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void clearFile();


	//ȥ�ز�����������˺�ʱ��������ظ���ѧ����ţ��������ظ��Ľ�ʦ��ţ���ʾ����


	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��Ż�����Ϣ������
	vector<ComputerRoom> vCom;

	//����ظ� ����������id���������ͣ�����ֵ��true: �������ظ���false����û���ظ���
	bool checkRepeat(int id,int type);

	



};

