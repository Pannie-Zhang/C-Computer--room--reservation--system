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
	//默认构造
	manager();

	//有参构造 参数：学号、姓名、密码
	manager(string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//添加账号
	//给学生或者老师添加新的账号
	//添加时学生学号不能重复，教师职工号不能重复
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void clearFile();


	//去重操作：添加新账号时，如果是重复的学生编号，或者是重复的教师编号，提示有误


	//初始化容器
	void initVector();

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//存放机房信息的容器
	vector<ComputerRoom> vCom;

	//检测重复 参数（传入id，传入类型）返回值（true: 代表有重复，false代表没有重复）
	bool checkRepeat(int id,int type);

	



};

