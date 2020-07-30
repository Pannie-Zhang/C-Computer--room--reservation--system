#include "orderFile.h"

orderFile::orderFile()
{
	//���캯����ȡ������Ϣ���������������
	ifstream ifs;
	ifs.open(ORDER_FILE,ios::in);

	string date;    //����
	string interval;//ʱ���
	string stuId;   //ѧ�����
	string stuName; //ѧ������
	string roomId;  //�������
	string status;  //ԤԼ״̬

	this->m_Size = 0;//��ʼԤԼ��¼Ϊ0

	//���ζ�ȡÿ����¼
	while (ifs>>date&&ifs >> interval&&ifs >> stuId&&ifs >> stuName
		&&ifs >> roomId&&ifs >> status) {

		/*cout << "date" << date << endl;
		cout << "interval" << interval << endl;
		cout << "stuId" << stuId << endl;
		cout << "stuName" << stuName << endl;
		cout << "roomId" << roomId << endl;
		cout << "status" << status << endl;*/

		string key;
		string value;
		map<string, string> m;

		//�Զ����ļ�¼���в��
		int pos = date.find(":");//4
		if (pos != -1) {
			key = date.substr(0,pos);
			value = date.substr(pos+1,date.size()-pos-1);
			m.insert(make_pair(key,value));
		}

		pos = interval.find(":");
		if (pos!=-1) {
			key = interval.substr(0,pos);
			value = interval.substr(pos + 1, interval.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1 );
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos-1 );
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos-1);
			m.insert(make_pair(key, value));
		}
		//Сmap�����map
		this->m_orderDate.insert(make_pair(this->m_Size,m));
		this->m_Size++;

	}

	ifs.close();
	system("pause");
	system("cls");
}




//����ԤԼ��¼�����Ǳ���ԤԼ��¼��ɾ���ؽ�
void orderFile::updateOrder() {
	if (this->m_Size==0) {
		return;
	}
	//ofs.open(ORDER_FILE, ios::out | ios::trunc);����Ҳ������
	ofstream ofs(ORDER_FILE,ios::out||ios::trunc);//ɾ��������д��
	for (int i = 0; i < m_Size;i++) {
		ofs << "date:" << this->m_orderDate[i]["date"] << " "; //���ʵ�i����¼�µ�����
		ofs << "interval:" << this->m_orderDate[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderDate[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderDate[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderDate[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderDate[i]["status"] << " ";
		cout << endl;
	}
	ofs.close();
}