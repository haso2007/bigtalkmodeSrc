#include<iostream>
#include <vector>
#include <string>
using namespace std;

class AbstractClass
{
public:
	void Show()
	{
		cout<<"我是"<<GetName()<<endl;
	}
protected:
	virtual string GetName()=0;
};

class Naruto : public AbstractClass
{
protected:
	virtual string GetName()
	{
		return "火影史上最帅的六代目---一鸣惊人naruto";
	}
};

class OnePice : public AbstractClass
{
protected:
	virtual string GetName()
	{
		return "我是无恶不做的大海贼---路飞";
	}
};

//客户端
int main()
{   //sean.定义一个抽象类的对象。抽象类实例不能创建即new,但可以被赋值。 
	AbstractClass* man = new Naruto();//new 的是什么对象，自然通过多态调用对应方法。 
	AbstractClass* man2 = new OnePice();
	man->Show();
	man2->Show();
    system("pause");
	return 0;
}
