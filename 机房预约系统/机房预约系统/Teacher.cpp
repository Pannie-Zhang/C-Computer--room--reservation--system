#include "Teacher.h"

Teacher::Teacher()
{
}


//�вι��� ������ѧ�š�����������
Teacher::Teacher(int empId, string name, string pwd) {
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu() {
	cout << "��ӭ��" << this->m_Name << "��¼��" << endl;
	cout << endl;
	cout << endl << "�������������:" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.�鿴����ԤԼ         |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.�� �� Ԥ Լ          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.ע �� �� ¼          |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "����������ѡ��";
}

//�鿴����ԤԼ  ����������һ������δ���֮��ͳ�����
void Teacher::showAllOrder() {
	orderFile of;//�õ��ָ�õ�����ԤԼ��¼
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "�� ";//��ʾ���
		cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << " ";
		cout << "ʱ�Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ�ţ�" << of.m_orderDate[i]["stuId"] << " ";
		cout << "������" << of.m_orderDate[i]["stuName"] << " ";
		cout << "������ţ�" << of.m_orderDate[i]["roomId"] << " ";
		string status = "״̬��";//0 ȡ��ԤԼ 1 ����� 2 ��ԤԼ -1 ԤԼʧЧ

		if (of.m_orderDate[i]["status"] == "1") {
			status += "�����......";
		}
		else if (of.m_orderDate[i]["status"] == "2") {
			status += "ԤԼ�ɹ���";
		}
		else if (of.m_orderDate[i]["status"] == "-1") {
			status += "���δͨ����ԤԼʧ�ܣ�";
		}
		else {
			status += "ԤԼ��ȡ����";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder() {
	orderFile of;//�õ��ָ�õ�����ԤԼ��¼
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵ļ�¼���£�" << endl;

	vector<int> v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderDate[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << "�� ";//��ʾ���
			cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << " ";
			cout << "ʱ�Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "������ţ�" << of.m_orderDate[i]["roomId"] << " ";
			string status = "״̬��";//0 ȡ��ԤԼ 1 ����� 2 ��ԤԼ -1 ԤԼʧЧ
			if (of.m_orderDate[i]["status"] == "1") {
				status += "�����......";
			}
			cout << status << endl;
		}		
	}

	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;
	int ret = 0;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��������˽��" << endl;
				cout << "1. ͨ���� " << endl;
				cout << "2. ��ͨ���� " << endl;

				cin >> ret;
				if (ret==1) {
					of.m_orderDate[v[select - 1]]["status"] = "2";//ע��������±��v�������Ķ�Ӧ
				}
				else {
					of.m_orderDate[v[select - 1]]["status"] = "-1";//ע��������±��v�������Ķ�Ӧ
				}
				
				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}