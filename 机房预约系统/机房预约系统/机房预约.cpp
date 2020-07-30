#include <iostream>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "manager.h"
#include <fstream>
#include <string>
using namespace std;

//进入教师子菜单界面
void teacherMenu(Identity * &teacher) {
	while (true) {
		//调用教师的子菜单
		teacher->operMenu();

		//将父类指针 转为子类指针，调用子类里其他接口
		Teacher * tea = (Teacher*)teacher;

		int select = 0;
		//接受用户选项
		cin >> select;

		if (select == 1) {//查看所有预约			
			tea->showAllOrder();
		}
		else if (select == 2) {//审核预约		

			tea->validOrder();
		}		
		else {
			//注销
			delete teacher;//销毁掉堆区的对象
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入学生子菜单界面

void studentMenu(Identity * &student) {
	while (true) {
		//调用学生的子菜单
		student->operMenu();

		//将父类指针 转为子类指针，调用子类里其他接口
		Student * stu = (Student*)student;

		int select = 0;
		//接受用户选项
		cin >> select;

		if (select == 1) {//申请预约			
			stu->applyOrder();
		}
		else if (select == 2) {//查看自身预约			

			stu->showMyOrder();
		}
		else if (select == 3) {//查看所有预约			
			stu->showAllOrder();
		}
		else if (select == 4) {//取消预约			
			stu->cancelOrder();
		}
		else {
			//注销
			delete student;//销毁掉堆区的对象
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//进入管理员子菜单界面
void managerMenu(Identity * &man) {
	while (true) {
		//调用管理员的子菜单
		man->operMenu();

		//将父类指针 转为子类指针，调用子类里其他接口
		manager * m = (manager*)man;

		int select = 0;
		//接受用户选项
		cin >> select;
		if (select == 1) {//添加账号
			cout << "添加账号！" << endl;
			m->addPerson();
		}
		else if(select==2) {//查看账号
			cout << "查看账号！" << endl;
			m->showPerson();
		}
		else if (select == 3) {//查看机房
			cout << "查看机房！" << endl;
			m->showComputer();
		}
		else if (select == 4) {//清空预约
			cout << "清空预约！" << endl;
			m->clearFile();
		}
		else {
			//注销
			delete man;//销毁掉堆区的对象
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}



//登录功能 参数一：文件操作名 参数二： 操作身份类型
void LoginIn(string fileName, int type) {

	//父类指针，用于指向子类对象
	Identity * person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close(); 
		return;
	}
	
	//准备接受用户的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份,管理员没有id，所以需要判断一下
	if (type == 1)//学生身份
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)//学生身份
	{
		//提前在student.txt中写两个测试用例
		//发现如果是中文的姓名会乱码
		//1 zhangpanpan 123
		//2 杨洋 456----验证出现问题（因为中文）

		//学生身份验证
		int fId;//从文件中读取的Id号
		string fName;//从文件中读取的姓名
		string fPwd;//从文件中读取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//与用户输入的信息做对比
			if (id == fId && name== fName && pwd==fPwd) {
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");//清屏
				person = new Student(id,name,pwd);
				//进入学生子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {

		//教师身份验证
		int fId;//从文件中读取的Id号
		string fName;//从文件中读取的姓名
		string fPwd;//从文件中读取的密码

		//ifs以空格进行分割
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//与用户输入的信息做对比
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");//清屏
				person = new Teacher(id, name, pwd);
				//进入教师子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {

		//管理员身份验证		
		string fName;//从文件中读取的姓名
		string fPwd;//从文件中读取的密码
		while (ifs >> fName && ifs >> fPwd) {
			//与用户输入的信息做对比
			if (name == fName && pwd == fPwd) {
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");//清屏
				person = new manager(name, pwd);
				//进入管理员子菜单
				managerMenu(person);

				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");

	return;
}



int main() {
	int select = 0;
	while (true) {
		cout << "=======================欢迎来到机房预约系统=======================";
		cout << endl;
		cout << endl << "请输入您的身份:" << endl;
		cout << "\t\t--------------------------------------\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             1.学生代表             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             2.老    师             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             3.管 理 员             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             0.退    出             |\n";
		cout << "\t\t--------------------------------------\n";
		cout << "请输入您的选择：";

		cin >> select;//接受用户选择
		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://管理员身份
			cout << "欢迎下一次使用！" << endl;
			system("pause");//按任意键会退出
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		} 
	}	
	cout << endl;
	system("pause");
	return 0;
}