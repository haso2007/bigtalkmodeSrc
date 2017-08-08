#include <iostream>
using namespace std;

class Target
{
public:
	virtual void Request()
	{
		cout<<"��ͨ������"<<endl;
	}
};

class Adaptee
{
public:
	void SpecificalRequest()
	{
		cout<<"��������"<<endl;
	}
};

class Adapter :public  Target
{
private:
	Adaptee* ada;
public:
	virtual void Request()
	{
		ada->SpecificalRequest();
		Target::Request();
	}
	Adapter()
	{
		ada=new Adaptee();
	}
	~Adapter()
	{
		delete ada;
	}
};

//�ͻ��ˣ�
int main()
{
	Adapter * ada=new Adapter();
	ada->Request();
	delete ada;
	system("pause");
	return 0;
}
