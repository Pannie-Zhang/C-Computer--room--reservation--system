#include "orderFile.h"

orderFile::orderFile()
{
	//构造函数获取所有信息，并存放在容器中
	ifstream ifs;
	ifs.open(ORDER_FILE,ios::in);

	string date;    //日期
	string interval;//时间段
	string stuId;   //学生编号
	string stuName; //学生姓名
	string roomId;  //机房编号
	string status;  //预约状态

	this->m_Size = 0;//初始预约记录为0

	//依次读取每条记录
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

		//对读到的记录进行拆分
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
		//小map放入大map
		this->m_orderDate.insert(make_pair(this->m_Size,m));
		this->m_Size++;

	}

	ifs.close();
	system("pause");
	system("cls");
}




//更新预约记录，不是保留预约记录，删了重建
void orderFile::updateOrder() {
	if (this->m_Size==0) {
		return;
	}
	//ofs.open(ORDER_FILE, ios::out | ios::trunc);这样也能运行
	ofstream ofs(ORDER_FILE,ios::out||ios::trunc);//删了再重新写入
	for (int i = 0; i < m_Size;i++) {
		ofs << "date:" << this->m_orderDate[i]["date"] << " "; //访问第i条记录下的日期
		ofs << "interval:" << this->m_orderDate[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderDate[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderDate[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderDate[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderDate[i]["status"] << " ";
		cout << endl;
	}
	ofs.close();
}