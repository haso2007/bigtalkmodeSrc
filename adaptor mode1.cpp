#include <iostream>
using namespace std;

class Target
{
public:
	virtual void Request()
	{
		cout<<"普通的请求"<<endl;
	}
};

class Adaptee
{
public:
	void SpecificalRequest()
	{
		cout<<"特殊请求"<<endl;
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

//客户端：
int main()
{
	Adapter * ada=new Adapter();
	ada->Request();
	delete ada;
	system("pause");
	return 0;
}
