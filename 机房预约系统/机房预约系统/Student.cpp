#include "Student.h"
Student::Student()
{
}



//�вι��� ������ѧ�š�����������
Student::Student(int id, string name, string pwd) {
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ȡ������Ϣ
	ifstream ifs;//���ļ�
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs>>c.m_ComId&&ifs>>c.m_MaxNum) {
		//����ȡ����Ϣ�ŵ�������
		vCom.push_back(c);
	}
	ifs.close();
}

//�˵�����
void Student::operMenu() {
	cout << "��ӭ��" << this->m_Name << "��¼��" << endl;
	cout << endl;
	cout << endl << "�������������:" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.����ԤԼ             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.�鿴�ҵ�ԤԼ         |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             3.�鿴����ԤԼ         |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             4.ȡ��ԤԼ             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.ע����¼             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "����������ѡ��";
}


//����ԤԼ
void Student::applyOrder() {
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int date = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//�������

	while (true) {
		cin >> date;
		if (date >=1&& date <=5) {
			break;
		}
		cout << "�����������������룡" << endl;
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	while (true) {
		cin >> interval;
		if (interval>=1&&interval<=2) {
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << vCom[i].m_ComId << "�Ż���������" << vCom[i].m_MaxNum << endl;
	}

	while (true) {
		cin >> room;
		if (room>=1&&room<= 3) {
			break;
		}
		cout << "�����������������룡" << endl;
	}
	cout << "ԤԼ�ɹ��� �����......" << endl;

	ofstream ofs(ORDER_FILE,ios::app);//app׷�ӵķ�ʽ��

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";//ʱ���
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;//1�ű�ʾ�����

	ofs.close();

	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showMyOrder() {
	orderFile of;
	cout << of.m_Size << endl;
	
	if (of.m_Size==0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size;i++) {
		//string ����.c_str()תconst char*
		//����atoi��const char*��תint	
		
		if (this->m_Id==atoi(of.m_orderDate[i]["stuId"].c_str())) {//�ҵ�������ѧ��һ���ļ�¼�ҳ���
			cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"];
			cout << "ʱ��" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����");
			cout << "������" << of.m_orderDate[i]["roomId"];
			string status = "״̬��";//0 ȡ��ԤԼ 1 ����� 2 ��ԤԼ -1 ԤԼʧЧ
			if (of.m_orderDate[i]["status"]=="1") {
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
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder() {
	orderFile of;//�õ��ָ�õ�����ԤԼ��¼
	if (of.m_Size==0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size;i++) {
		cout << i + 1 << "�� ";//��ʾ���
		cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << " ";
		cout << "ʱ�Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ�ţ�" << of.m_orderDate[i]["stuId"] << " ";
		cout << "������" << of.m_orderDate[i]["stuName"] << " ";
		cout << "������" << of.m_orderDate[i]["roomId"] << " ";
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

//ȡ��ԤԼ
void Student::cancelOrder() {
	orderFile of;
	if (of.m_Size==0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v;//�����������е��±���
	int index = 1;
	for (int i = 0; i < of.m_Size;i++) {
		if (this->m_Id == atoi(of.m_orderDate[i]["stuId"].c_str())) {//ֻ��ȡ���Լ���
			if (of.m_orderDate[i]["status"]=="1"|| of.m_orderDate[i]["status"]=="2") {//����л�ԤԼ�ɹ��ļ�¼����ȡ��
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << " ";
				cout << "ʱ�Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����") << " ";
				cout << "������" << of.m_orderDate[i]["roomId"] << " ";
				string status = "״̬��";//0 ȡ��ԤԼ 1 ����� 2 ��ԤԼ -1 ԤԼʧЧ

				if (of.m_orderDate[i]["status"] == "1") {
					status += "�����......";
				}
				else if (of.m_orderDate[i]["status"] == "2") {
					status += "ԤԼ�ɹ���";
				}
				cout << status << endl;
			}		
		}
	}
	cout << "������ȡ���ļ�¼��0��ʾ����" << endl;
	int select = 0;

	while (true) {
		cin >> select;
		if (select>=0&&select<=v.size()) {
			if (select == 0) {
				break;
			}
			else {
				//cout << "��¼����λ�ã� " << v[select - 1] << endl;
				of.m_orderDate[v[select-1]]["status"] = "0";//ע��������±��v�������Ķ�Ӧ
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}

	system("pause");
	system("cls");
}