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

	//更新预约记录
	void updateOrder();

	//记录的容器
	//key---文件中预约记录的条数(int)，value---具体记录的键值对信息
	//map<string, string>(key-属性，value-实值)--记录其中一条记录
	map<int, map<string, string>> m_orderDate;

	//预约记录条数
	int m_Size;
};

//功能描述：显示预约记录时，需要从文件中获取所有记录，
//用来显示，创建预约的类来管理记录以及更新

