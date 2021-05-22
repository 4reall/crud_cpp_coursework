#include "Functions.h"
void DataInitialization()
{
	ofstream _buf("buffer.txt");
		if (!_buf)
			cout << "������ �������� ��������� �����" << endl;
	_buf.close();
}
void DataEntry()
{
	string name, date, sex, group, faculty,markName;
	int entryYear, markBook, mark,sessNum,markNum;
	int n, sessCount =1;
	cout << "������� ���������� ���������, ������� �� ������ �������� ";
	cin >> n;
	ofstream record("Buffer.txt", ios::app);
	if (record)
	{
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "������� �.�.� ";
			cin.ignore();
			getline(cin, name);

			cout << "������� ���� �������� (�����,�����,���) ";
			getline(cin, date);

			cout << "������� ��� ����������� � �������� ";
			cin >> entryYear;

			cout << "������� ���������, ������� ";
			cin.ignore();
			getline(cin, faculty);

			cout << "������� ������ ";
			getline(cin, group);

			cout << "������� ����� �������� ������ ";
			cin >> markBook;

			cout << "������� ��� ";
			cin.ignore();
			getline(cin, sex);

			cout << "������� ���������� ������ ";
			cin >> sessNum;


			record << name << endl;
			record << date << endl;
			record << entryYear << endl;
			record << faculty << endl;
			record << group << endl;
			record << markBook << endl;
			record << sex << endl;
			record << sessNum << endl;
			for (int i = 0; i < sessNum; i++)
			{
				cout << "������ ����� " << sessCount << endl;
				record << sessCount << endl;
				sessCount++;
				cout << "������� ���������� ��������� ";
				cin >> markNum;
				record << markNum << endl;
				for (int j = 0; j < markNum; j++)
				{
					cout << "������� �������� �������� � ������ ";
					cin >> markName >> mark;
					record << markName << " " << mark << endl;
				}
			}
			sessCount = 1;
			cout << "__________________________________" << endl;
		}
	}
	else
		cout << "������ �������� �����";
	record.close();
}
void DataReading(string fileName)
{
	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);
		if (reading)
		{
			if (record)
			{
				string name, date, sex, group, faculty, markName;
				int entryYear, markBook, mark, sessNum,markNum;
				int n, sessCount=0;

				reading >> n;
				record << n << endl;
				for (int i = 0; i < n; i++)
				{
					reading.ignore();
					getline(reading, name);
					reading >> date;
					reading >> entryYear;
					reading.ignore();
					getline(reading,  faculty);
					reading >> group;
					reading >> markBook;
					reading >> sex;
				
					record << name << endl;
					record << date << endl;
					record << entryYear << endl;
					record << faculty << endl;
					record << group << endl;
					record << markBook << endl;
					record << sex << endl;
					reading >> sessNum;
					record << sessNum << endl;
					for (int i = 0; i < sessNum; i++)
					{
						reading >> sessCount;
						record << sessCount << endl;
						reading >> markNum;
						record << markNum << endl;
						for (int j = 0; j < markNum; j++)
						{
							reading >> markName >> mark;
							record << markName << " " << mark << endl;
						}
					}
				}
				cout << "������ �������" << endl;
			}
			else 
				cout<< "������ �������� �������" << endl;
		}
		else
			cout<< "������ �������� �����" << endl;
		reading.close();
		record.close();
}
void Print(string fileName)
{

	ifstream reading(fileName);
	if (reading)
	{
		if (reading.peek() != EOF)
		{
			string name, date, sex, group, faculty, markName;
			int n, entryYear, markBook, mark, sessNum, sessCount =0, markNum;

			reading >> n;
			cout << "���������� c�������� " << n << endl << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "������ �� c������� �" << i + 1 << endl;
				reading.ignore();
				getline(reading, name);
				cout << "�.�.� " << name << endl;
				reading >> date;
				cout << "���� �������� " << date << endl;
				reading >> entryYear;
				cout << "���� ����������� " << entryYear << endl;
				reading.ignore();
				getline(reading, faculty);
				cout << "���������, ������� " << faculty << endl;
				reading >> group;
				cout << "������ " << group << endl;
				reading >> markBook;
				cout << "����� �������� ������ " << markBook << endl;
				reading >> sex;
				cout << "��� " << sex << endl;
				reading >> sessNum;
				cout << "���������� ������ " << sessNum<<endl;
				for (int i = 0; i < sessNum; i++)
				{
					reading >> sessCount;
					cout << "����� ������ " << sessCount << endl;
					reading >> markNum;
					cout << "���������� ��������� " << markNum << endl;
					for (int j = 0; j < markNum; j++)
					{
						reading >> markName >> mark;
						cout <<"�������� �������� "<< markName << " ������ " << mark << endl;
					}
				}
				cout << "________________________________________________" << endl;
			}
		
		}
		else
			cout << "���� ������" << endl;
	}
	else
		cout << "������ �������� �����" << endl;
	reading.close();
}
void DataChange()
{
	Copy();
	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string name, date, sex, group, faculty, markName;
			int entryYear, markBook, mark, sessNum, sessCount, markNum;
			int n, _n;

			reading >> n;
			cout << "����� ����������� �� 1 �� "<<n<<" "; 
			cin >> _n;
			_n--;
			system("cls");
			record << n << endl;
			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading.ignore();
						getline(reading, name);
						record << name << endl;
						reading >> date;
						record << date << endl;
						reading >> entryYear;
						record << entryYear << endl;
						reading.ignore();
						getline(reading, faculty);
						record << faculty << endl;
						reading >> group;
						record << group << endl;
						reading >> markBook;
						record << markBook << endl;
						reading >> sex;
						record << sex << endl;
						reading >> sessNum;
						record << sessNum << endl;
						for (int i = 0; i < sessNum; i++)
						{
							reading >> sessCount;
							record << sessCount << endl;
							reading >> markNum;
							record << markNum << endl;
							for (int j = 0; j < markNum; j++)
							{
								reading >> markName >> mark;
								record << markName << " " << mark << endl;
							}
						}
					}
					else
					{
						cout << "������� �.�.� ";
						cin.ignore();
						getline(cin, name);

						cout << "������� ���� �������� (�����,�����,���) ";
						getline(cin, date);

						cout << "������� ��� ����������� � �������� ";
						cin >> entryYear;

						cout << "������� ���������, ������� ";
						cin.ignore();
						getline(cin, faculty);

						cout << "������� ������ ";
						getline(cin, group);

						cout << "������� ����� �������� ������ ";
						cin >> markBook;

						cout << "������� ��� ";
						cin.ignore();
						getline(cin, sex);

						cout << "������� ���������� ������ ";
						cin >> sessNum;

						record << name << endl;
						record << date << endl;
						record << entryYear << endl;
						record << faculty << endl;
						record << group << endl;
						record << markBook << endl;
						record << sex << endl;
						record << sessNum << endl;
						sessCount = 1;
						for (int i = 0; i < sessNum; i++)
						{
							cout << "����� ���c�� " << sessCount << endl;
							record << sessCount << endl;
							sessCount++;
							cout << "������� ���������� ��������� ";
							cin >> markNum;
							record << markNum << endl;
							for (int j = 0; j < markNum; j++)
							{
								cout << "������� �������� �������� � ������ ";
								cin >> markName >> mark;
								record << markName << " " << mark << endl;
							}
						}
						reading.ignore();
						getline(reading, name);
						reading >> date;
						reading >> entryYear;
						reading.ignore();
						getline(reading, faculty);
						reading >> group;
						reading >> markBook;
						reading >> sex;
						reading >> sessNum;
						for (int i = 0; i < sessNum; i++)
						{
							reading >> sessCount;
							reading >> markNum;
							for (int j = 0; j < markNum; j++)
							{
								reading >> markName >> mark;
							}
						}
					}

				}
				cout << "������ ��������" << endl;
			}
			else
				cout<< "�������� �����" << endl;
		}
		else
			cout << "������ �������� �����" << endl;
	}
	else
		cout << "������ �������� �������" << endl;
	record.close();
	reading.close();
	remove("Buffer_.txt");
}
void Copy()
{
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string name, date, sex, group, faculty, markName;
			int entryYear, markBook, mark, sessNum, sessCount,markNum;
			int n;

			reading >> n;
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				reading.ignore();
				getline(reading, name);
				record << name << endl;
				reading >> date;
				record << date << endl;
				reading >> entryYear;
				record << entryYear << endl;
				reading.ignore();
				getline(reading, faculty);
				record << faculty << endl;
				reading >> group;
				record << group << endl;
				reading >> markBook;
				record << markBook << endl;
				reading >> sex;
				record << sex << endl;
				reading >> sessNum;
				record << sessNum << endl;
				for (int i = 0; i < sessNum; i++)
				{
					reading >> sessCount;
					record << sessCount << endl;
					reading >> markNum;
					record << markNum << endl;
					for (int j = 0; j < markNum; j++)
					{
						reading >> markName >> mark;
						record << markName << " " << mark << endl;
					}
				}
			}
		}
		else
			cout << "������ �������� �����" << endl;
	}
	else
		cout << "������ �������� ���������� �����" << endl;
	reading.close();
	record.close();
}
void DeleteData()
{
	Copy();
	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string name, date, sex, group, faculty, markName;
			int entryYear, markBook, mark, sessCount, sessNum,markNum;
			int n, _n;

			reading >> n;
			int b = n - 1;

			cout << "����� ��������, ������ � ������� �� ������ ������� �� 1 " << n <<" ";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;
			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading.ignore();
						getline(reading, name);
						record << name << endl;
						reading >> date;
						record << date << endl;
						reading >> entryYear;
						record << entryYear << endl;
						reading.ignore();
						getline(reading, faculty);
						record << faculty << endl;
						reading >> group;
						record << group << endl;
						reading >> markBook;
						record << markBook << endl;
						reading >> sex;
						record << sex << endl;
						reading >> sessNum;
						record << sessNum << endl;
						for (int i = 0; i < sessNum; i++)
						{
							reading >> sessCount;
							record << sessCount << endl;
							reading >> markNum;
							record << markNum << endl;
							for (int j = 0; j < markNum; j++)
							{
								reading >> markName >> mark;
								record << markName << " " << mark << endl;
							}
						}
					}
					else
					{
						reading.ignore();
						getline(reading, name);
						reading >> date;
						reading >> entryYear;
						reading.ignore();
						getline(reading, faculty);
						reading >> group;
						reading >> markBook;
						reading >> sex;
						reading >> sessNum;
						for (int i = 0; i < sessNum; i++)
						{
							reading >> sessCount;
							reading >> markNum;
							for (int j = 0; j < markNum; j++)
							{
								reading >> markName >> mark;
							}
						}
					}

				}
				cout << "������ �������" << endl;
			}
			else
				cout << "�������� �����" << endl;
		}
		else
			cout << "������ �������� �����" << endl;
	}
	else
		cout << "������ �������� �������" << endl;
	record.close();
	reading.close();
	remove("Buffer_.txt");
}
int AmountOfData()
{
	ifstream _buf("Buffer.txt");
	int n=0;
	if (_buf)
	{
		_buf >> n;
	}
	else
		cout << "������ �������� ����������� �����!";
	_buf.close();
	return n;
}
void AddData()
{
	string name, date, sex, group, faculty, markName;
	int n, entryYear, markBook, mark, sessCount=1, sessNum,markNum;
	n = AmountOfData() + 1;
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);
	if (record_)
	{
		record_ << n << endl;
	}
	else
		cout << "������ �������� ���������� �����!" << endl;
	if (record)
	{
		cout << "������� �.�.� ";
		cin.ignore();
		getline(cin, name);

		cout << "������� ���� �������� (�����,�����,���) ";
		getline(cin, date);

		cout << "������� ��� ����������� � �������� ";
		cin >> entryYear;

		cout << "������� ���������, ������� ";
		cin.ignore();
		getline(cin, faculty);

		cout << "������� ������ ";
		getline(cin, group);

		cout << "������� ����� �������� ������ ";
		cin >> markBook;

		cout << "������� ��� ";
		cin.ignore();
		getline(cin, sex);

		cout << "������� ���������� ������ ";
		cin >> sessNum;


		record << name << endl;
		record << date << endl;
		record << entryYear << endl;
		record << faculty << endl;
		record << group << endl;
		record << markBook << endl;
		record << sex << endl;
		record << sessNum << endl;
		for (int i = 0; i < sessNum; i++)
		{
			cout << "������ ����� " << sessCount << endl;
			record << sessCount << endl;
			cout << "������� ���������� ��������� ";
			cin >> markNum;
			record << markNum << endl;
			sessCount++;
			for (int j = 0; j < markNum; j++)
			{
				cout << "������� �������� �������� � ������ ";
				cin >> markName >> mark;
				record << markName << " " << mark << endl;
			}
		}
	}
	else
		cout << "������ �������� �����" << endl;
	record.close();
	record_.close();
}
void SaveData(string fileName)
{
	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading)
	{
		if (record)
		{
			string name, date, sex, group, faculty, markName;
			int n, entryYear, markBook, mark, sessCount, sessNum, markNum;
			
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading.ignore();
				getline (reading, name);
				record << name << endl;
				reading >> date;
				record << date << endl;
				reading >> entryYear;
				record << entryYear << endl;
				reading.ignore();
				getline(reading, faculty);
				record << faculty << endl;
				reading >> group;
				record << group << endl;
				reading >> markBook;
				record << markBook << endl;
				reading >> sex;
				record << sex << endl;
				reading >> sessNum;
				record << sessNum << endl;
				for (int i = 0; i < sessNum; i++)
				{
					reading >> sessCount;
					record << sessCount << endl;
					reading >> markNum;
					record << markNum << endl;
					for (int j = 0; j < markNum; j++)
					{
						reading >> markName >> mark;
						record << markName << " " << mark << endl;
					}
				}
			}
			cout << "������ ���������" << endl;
		}
		else
			cout << "������ �������� �����!"<<endl;
	}
	else
		cout << "������ �������� ���������� �����!"<<endl;
	reading.close();
	record.close();
}
bool DataCleaning()
{
	bool clear = false;
	fstream _buf("Buffer.txt", ios::out);
	if (!_buf)
		cout << "������ �������� ���������� ����� ��� ��� ��������";
	_buf.close();
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;
	_buf.close();
	return clear;
}
void DataReading(Data* (&d), int& n)
{
	ifstream reading("buffer.txt");
	if (reading)
	{
		Sess sess;
		University university;
		Student student;

		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++)
		{
			reading.ignore();
			getline(reading, student.name);
			reading >> student.date;
			reading >> university.entryYear;
			reading.ignore();
			getline(reading, university.faculty);
			reading >> university.group;
			reading >> university.markBook;
			reading >> student.sex;
			reading >> sess.sessCount;
			for (int i = 0; i < sess.sessCount; i++)
			{
				reading >> sess.sessNum;
				for (int j = 0; j < time; j++)
				{
					reading >> sess.markName[j] >> sess.mark[j];
				}
			}

			d[i].DataEntry(sess,student,university);
		}
	}
	else
		cout << "������ �������� �����" << endl;
	reading.close();
}
void SaveData(Data* d, int n)
{
	ofstream record("buffer.txt");
	if (record)
	{
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			record << d[i].GetStudent().name << endl;
			record << d[i].GetStudent().date << endl;
			record << d[i].GetUniversity().entryYear << endl;
			record << d[i].GetUniversity().faculty << endl;
			record << d[i].GetUniversity().group << endl;
			record << d[i].GetUniversity().markBook << endl;
			record << d[i].GetStudent().sex << endl;
			record << d[i].GetSess().sessCount << endl;
			int n = d[i].GetSess().sessCount;
			for (int m = 0; m < n; m++)
			{
				record<< d[i].GetSess().sessNum<<endl;
				for (int j = 0; j < time; j++)
				{
					record << d[i].GetSess().markName[j] << " " << d[i].GetSess().mark[j] << endl;
				}
			}
		}

	}
	else
		cout << "������ �������� �����!" << endl;
	record.close();
}
void SortingData(Data* d, int n)
{
	Data buf;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (AverageMark(d, i) > AverageMark(d, j)) {
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;
			}
		}
	}
}
float AverageMark(Data* d, int n)
{
	int sum=0;
	for (int i = 0; i < 10; i++)
	{
		sum += d[n].GetSess().mark[i];
	}
	sum /= 10;
	return (round(sum*100)/100);
}
int SessSum(Data* d, int n, int b)
{
	int sum;
	for (int i = 0; i < 10; i++)
	{
		sum += d[n].GetSess().sessNum[i];
	}
	return sum;
}