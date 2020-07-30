#include "Teacher.h"

Teacher::Teacher()
{
}


//有参构造 参数：学号、姓名、密码
Teacher::Teacher(int empId, string name, string pwd) {
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu() {
	cout << "欢迎：" << this->m_Name << "登录！" << endl;
	cout << endl;
	cout << endl << "请输入您的身份:" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.查看所有预约         |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.审 核 预 约          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.注 销 登 录          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "请输入您的选择：";
}

//查看所有预约  问题出在这里，一加上这段代码之后就出错了
void Teacher::showAllOrder() {
	orderFile of;//拿到分割好的所有预约记录
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "、 ";//显示标号
		cout << "预约日期：周" << of.m_orderDate[i]["date"] << " ";
		cout << "时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号：" << of.m_orderDate[i]["stuId"] << " ";
		cout << "姓名：" << of.m_orderDate[i]["stuName"] << " ";
		cout << "机房编号：" << of.m_orderDate[i]["roomId"] << " ";
		string status = "状态：";//0 取消预约 1 审核中 2 已预约 -1 预约失效

		if (of.m_orderDate[i]["status"] == "1") {
			status += "审核中......";
		}
		else if (of.m_orderDate[i]["status"] == "2") {
			status += "预约成功！";
		}
		else if (of.m_orderDate[i]["status"] == "-1") {
			status += "审核未通过，预约失败！";
		}
		else {
			status += "预约已取消！";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::validOrder() {
	orderFile of;//拿到分割好的所有预约记录
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的记录如下：" << endl;

	vector<int> v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderDate[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << "、 ";//显示标号
			cout << "预约日期：周" << of.m_orderDate[i]["date"] << " ";
			cout << "时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房编号：" << of.m_orderDate[i]["roomId"] << " ";
			string status = "状态：";//0 取消预约 1 审核中 2 已预约 -1 预约失效
			if (of.m_orderDate[i]["status"] == "1") {
				status += "审核中......";
			}
			cout << status << endl;
		}		
	}

	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0;
	int ret = 0;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "请输入审核结果" << endl;
				cout << "1. 通过： " << endl;
				cout << "2. 不通过： " << endl;

				cin >> ret;
				if (ret==1) {
					of.m_orderDate[v[select - 1]]["status"] = "2";//注意输入的下标和v中索引的对应
				}
				else {
					of.m_orderDate[v[select - 1]]["status"] = "-1";//注意输入的下标和v中索引的对应
				}
				
				of.updateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}