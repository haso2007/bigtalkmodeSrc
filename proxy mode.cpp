#include <string>
#include <iostream>
using namespace std;
//定义接口，使用纯虚函数，无法实例化 
class Interface
{
public:
	virtual void Request()=0;//=0表示子函数virtual用于它的实现，无0则不一定 
	//添加更多的工作在这里 
};
//真实类
class RealClass : public Interface
{
public:
	virtual void Request()
	{
		cout<<"真实的请求"<<endl;
	}
	//更多其它的职责 
};
//代理类
class ProxyClass : public Interface
{
private:
	RealClass* m_realClass;
public:
	virtual void Request()
	{
        cout<<"我代理被代理人提出："<<endl;    
	    m_realClass= new RealClass();//初始化被代理人，组合关系 
		m_realClass->Request();
		delete m_realClass;//代理任务完成后，回收空间 这非常重要 
	}
};

//客户端：
int main()
{
	ProxyClass* test=new ProxyClass();
	test->Request();
	system("pause");
	return 0;
}
