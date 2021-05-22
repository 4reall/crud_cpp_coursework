#include "Functions.h"
Data::Data()
{
	university.group = "";
	university.faculty = "";
	student.sex = "";
	student.date = "";
	student.name = "";
	university.markBook = 0;
	university.entryYear=0;
	sess.mark[10] = {};
	sess.markName[10] = {};
	sess.sessCount = 0;
}
Data::Data (Sess sess_,University university_, Student student_)
{
	student.date = student_.date;
	student.name=student_.name;
	student.sex = student_.sex;
	university.group = university_.group;
	university.faculty = university_.faculty;
	university.entryYear = university_.entryYear;
	university.markBook = university_.markBook;
	for (int i = 0; i < sess.markNum; i++)
	{
		sess.mark[i] = sess_.mark[i];
		sess.markName[i] = sess_.markName[i];
	}
	sess.sessCount = sess_.sessCount;
}

Data::~Data()
{

}

void Data::Print()
{
	cout << "�.�.� " << student.name << endl;
	cout << "���� �������� " << student.date << endl;
	cout << "���� ����������� " << university.entryYear << endl;
	cout << "���������, ������� " << university.faculty << endl;
	cout << "������ " << university.group << endl;
	cout << "����� �������� ������ " << university.markBook << endl;
	cout << "��� " << student.sex << endl;
	cout << "���������� ������ " << sess.sessCount << endl;
	for (int i = 0; i < sess.sessCount; i++)
	{
		cout << "����� ������ " << sess.sessNum << endl;
		cout << "���������� ��������� " << sess.markNum << endl;
		for (int j = 0; j < sess.markNum; j++)
		{
			cout << "�������� �������� " << sess.markName[j] << " ������ " << sess.mark[j] << endl;
		}
	}
}
void Data::DataEntry(Sess sess_, Student student_, University university_)
{
	student.date = student_.date;
	student.name = student_.name;
	student.sex = student_.sex;
	university.group = university_.group;
	university.faculty = university_.faculty;
	university.entryYear = university_.entryYear;
	university.markBook = university_.markBook;
	for (int i = 0; i < sess.markNum; i++)
	{
		sess.mark[i] = sess_.mark[i];
		sess.markName[i] = sess_.markName[i];
	}
	sess.sessCount = sess_.sessCount;
	sess.sessNum = sess_.sessNum;
}
Data& Data::operator=(Data d_o)
{
	this->student.date = d_o.student.date;
	this->student.name = d_o.student.name;
	this->student.sex = d_o.student.sex;
	this->university.group = d_o.university.group;
	this->university.faculty = d_o.university.faculty;
	this->university.entryYear = d_o.university.entryYear;
	this->university.markBook = d_o.university.markBook;
	for (int i = 0; i < 10; i++)
	{
		this->sess.mark[i] = d_o.sess.mark[i];
		this->sess.markName[i] = d_o.sess.markName[i];
	}
	this->sess.sessCount = d_o.sess.sessCount;
	this->sess.sessNum = d_o.sess.sessNum;
	return *this;
}
