#include "Functions.h"
using namespace std;
struct Student
{
	string name,date,sex;
};
struct University
{
	int markBook = 0,entryYear = 0;
	string group;
	string faculty;

};
struct Sess
{
	int mark[10] = {};
	int sessCount = 0, markNum = 0;
	int sessNum[9] = {};
	string markName[10];
};
class Data
{
private:
	Sess sess;
	University university;
	Student student;
public:
	Data();
	Data(Sess sess_, University university_, Student student_);
	~Data();
	void Print();
	void DataEntry(Sess sess_,Student student_,University university_);
	Sess GetSess() { return sess; };
	University GetUniversity() { return university; };
	Student GetStudent() { return student; };
	Data& operator = (Data d_o);
};
