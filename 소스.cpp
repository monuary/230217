#include<iostream>
#include<cstring>
using namespace std;

class Person
{
	char* name;
	int age = 0;
public:
	Person(char* myname, int myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
		age = myage;
	}
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char*myname,int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo()const
	{
		cout << "�̸�: " << name << ", ����: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main()
{
	Person parr[3];	//Ŭ������ ����ü�� ���� �� �ִ�. ��, �����ڸ� �� �� ����. ����Ʈ �����ڰ� �ڵ����� ����ȴ�.
	char namestr[100];
	char* strptr;
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸�: "; cin >> namestr;
		cout << "����: "; cin >> age;
		strptr = new char[strlen(namestr) + 1];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);	//�����ڸ� �� �� ������ ���� ������ �ٽ� �ۼ��ؾ� �Ѵ�. ��, for������ �������� �ݺ��� �� �ִ�.
	}
	for (int i = 0; i < 3; i++)
	{
		parr[i].ShowPersonInfo();
	}
	return 0;	//�Ҹ��ڸ� ������� �ʾ�����, return���� �ڵ����� ����ȴ�.
}