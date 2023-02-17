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
		cout << "이름: " << name << ", 나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main()
{
	Person parr[3];	//클래스도 구조체를 만들 수 있다. 단, 생성자를 쓸 수 없다. 디폴트 생성자가 자동으로 실행된다.
	char namestr[100];
	char* strptr;
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: "; cin >> namestr;
		cout << "나이: "; cin >> age;
		strptr = new char[strlen(namestr) + 1];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);	//생성자를 쓸 수 없으니 위의 과정을 다시 작성해야 한다. 단, for문으로 여러개를 반복할 수 있다.
	}
	for (int i = 0; i < 3; i++)
	{
		parr[i].ShowPersonInfo();
	}
	return 0;	//소멸자를 사용하지 않았지만, return으로 자동으로 실행된다.
}