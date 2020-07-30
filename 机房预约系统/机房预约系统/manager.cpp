#include "manager.h"



manager::manager()
{

}


//有参构造 参数：学号、姓名、密码
manager::manager(string name, string pwd) {
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器，获取文件中的信息
	this->initVector();

	//初始化机房信息，如果后期需要添加机房信息之类的，像this->initVector();
	//封装成一个函数
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs>>com.m_ComId&&ifs>>com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量：" << vCom.size() << endl;

}

//菜单界面
void manager::operMenu() {
	cout << "欢迎管理员："<<this->m_Name<<"登录！"<<endl;
	cout << endl;
	cout << endl << "请输入您的身份:" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.添加账号             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.查看账号             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             3.查看机房             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             4.清空预约             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.注销登录             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "请输入您的选择：";

}

//添加账号
void manager::addPerson() {
	cout << "请输入添加账号的类型：" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加教师" << endl;

	string fileName;//操作的文件名
	string tip;//提示id号

	ofstream ofs;//文件操作对象
	int select = 0;
	cin >> select;

	string errorTip;//重复错误提示

	if (select == 1) {//添加的是学生
		fileName = STUDENT_FILE;
		tip = "请输入学号： ";
		errorTip = "学号重复，请重新输入";
	}
	else if (select == 2) {//添加的是教师
		fileName = TEACHER_FILE;
		tip = "请输入职工编号： ";
		errorTip = "职工号重复，请重新输入";
	}
	ofs.open(fileName, ios::out | ios::app);//追加的方式写文件
	int id;//学号/职工号
	string name;//姓名
	string pwd;//密码
	
	cout << tip << endl;

	while (true) {
		cin >> id;
		bool ret = this->checkRepeat(id,select);
		if (ret) {//有重复
			cout << errorTip << endl;			
		}
		else {
			break;
		}
	}
	

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//初始化容器
	this->initVector();//防止新添加的没有及时更新
	//如果不及时更新，一次如果一直加入id=1的信息，不报错，除非退出了才更新

}

void printStudent(Student & s) {
	cout << "学号：" << s.m_Id << "姓名：" << s.m_Name << "密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher & t) {
	cout << "职工号：" << t.m_EmpId << "姓名：" << t.m_Name << "密码：" << t.m_Pwd << endl;
}
//查看账号
void manager::showPerson() {
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有教师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//查看学生
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(),vStu.end(),printStudent);
		
	}
	else {
		//查看教师
		cout << "所有教师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	//任意键返回到上一层
	system("pause");
	system("cls");
}

//查看机房信息 
void manager::showComputer() {
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end();it++) {
		cout << "机房编号：" << it->m_ComId << "  机房最大容量：" << it->m_MaxNum << endl;
	}
	//任意键返回到上一层
	system("pause");
	system("cls");
}

//清空预约记录
//可以后期添加一些判断，问一下是否一定要清空
void manager::clearFile() {
	ofstream ofs(ORDER_FILE,ios::trunc);//trunc方式打开文件，如果文件存在，全部删除再重新创建
	ofs.close();
	//ofs.clear();写这个也行，代替ofs.close();
	cout << "清空成功！" << endl;

	//任意键返回到上一层
	system("pause");
	system("cls");
}

//初始化容器
void manager::initVector() {
	//打开成功，先确保文件容器清空
	vStu.clear();
	vTea.clear();

	//读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs>>s.m_Id&&ifs>>s.m_Name&&ifs>>s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();//学生初始化

	//读取教师文件信息
	ifs.open(TEACHER_FILE, ios::in);	

	if (!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId&&ifs >> t.m_Name&&ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "当前教师数量为：" << vTea.size() << endl;
	ifs.close();//学生初始化
}


bool manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end();it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}
	}
	return false;
}