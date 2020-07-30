#include <iostream>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "manager.h"
#include <fstream>
#include <string>
using namespace std;

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity * &teacher) {
	while (true) {
		//���ý�ʦ���Ӳ˵�
		teacher->operMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Teacher * tea = (Teacher*)teacher;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) {//�鿴����ԤԼ			
			tea->showAllOrder();
		}
		else if (select == 2) {//���ԤԼ		

			tea->validOrder();
		}		
		else {
			//ע��
			delete teacher;//���ٵ������Ķ���
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//����ѧ���Ӳ˵�����

void studentMenu(Identity * &student) {
	while (true) {
		//����ѧ�����Ӳ˵�
		student->operMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Student * stu = (Student*)student;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) {//����ԤԼ			
			stu->applyOrder();
		}
		else if (select == 2) {//�鿴����ԤԼ			

			stu->showMyOrder();
		}
		else if (select == 3) {//�鿴����ԤԼ			
			stu->showAllOrder();
		}
		else if (select == 4) {//ȡ��ԤԼ			
			stu->cancelOrder();
		}
		else {
			//ע��
			delete student;//���ٵ������Ķ���
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//�������Ա�Ӳ˵�����
void managerMenu(Identity * &man) {
	while (true) {
		//���ù���Ա���Ӳ˵�
		man->operMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		manager * m = (manager*)man;

		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1) {//����˺�
			cout << "����˺ţ�" << endl;
			m->addPerson();
		}
		else if(select==2) {//�鿴�˺�
			cout << "�鿴�˺ţ�" << endl;
			m->showPerson();
		}
		else if (select == 3) {//�鿴����
			cout << "�鿴������" << endl;
			m->showComputer();
		}
		else if (select == 4) {//���ԤԼ
			cout << "���ԤԼ��" << endl;
			m->clearFile();
		}
		else {
			//ע��
			delete man;//���ٵ������Ķ���
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}



//��¼���� ����һ���ļ������� �������� �����������
void LoginIn(string fileName, int type) {

	//����ָ�룬����ָ���������
	Identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close(); 
		return;
	}
	
	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����,����Աû��id��������Ҫ�ж�һ��
	if (type == 1)//ѧ�����
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)//ѧ�����
	{
		//��ǰ��student.txt��д������������
		//������������ĵ�����������
		//1 zhangpanpan 123
		//2 ���� 456----��֤�������⣨��Ϊ���ģ�

		//ѧ�������֤
		int fId;//���ļ��ж�ȡ��Id��
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��ж�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//���û��������Ϣ���Ա�
			if (id == fId && name== fName && pwd==fPwd) {
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");//����
				person = new Student(id,name,pwd);
				//����ѧ���Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {

		//��ʦ�����֤
		int fId;//���ļ��ж�ȡ��Id��
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��ж�ȡ������

		//ifs�Կո���зָ�
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//���û��������Ϣ���Ա�
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");//����
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {

		//����Ա�����֤		
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��ж�ȡ������
		while (ifs >> fName && ifs >> fPwd) {
			//���û��������Ϣ���Ա�
			if (name == fName && pwd == fPwd) {
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");//����
				person = new manager(name, pwd);
				//�������Ա�Ӳ˵�
				managerMenu(person);

				return;
			}
		}
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");

	return;
}



int main() {
	int select = 0;
	while (true) {
		cout << "=======================��ӭ��������ԤԼϵͳ=======================";
		cout << endl;
		cout << endl << "�������������:" << endl;
		cout << "\t\t--------------------------------------\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             1.ѧ������             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             2.��    ʦ             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             3.�� �� Ա             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             0.��    ��             |\n";
		cout << "\t\t--------------------------------------\n";
		cout << "����������ѡ��";

		cin >> select;//�����û�ѡ��
		switch (select)
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://����Ա���
			cout << "��ӭ��һ��ʹ�ã�" << endl;
			system("pause");//����������˳�
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		} 
	}	
	cout << endl;
	system("pause");
	return 0;
}