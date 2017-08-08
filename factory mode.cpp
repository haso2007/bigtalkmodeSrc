#include <string>
#include <iostream>
using namespace std;
//实例基类，相当于Product(为了方便，没用抽象)
//sean 遵循父类尽量是抽象类原则，实现类才是真实类
//有很多好处。LeiFenFactory只是一个接口类 
//Leifeng也只是一个抽象类，可能有内部字段，这里简化。 
class LeiFeng
{
public:
	virtual void Sweep()=0;
//	{
//		cout<<"雷锋扫地"<<endl;
//	}
};

//学雷锋的大学生，相当于ConcreteProduct
class Student: public LeiFeng
{
public:
	virtual void Sweep()
	{
		cout<<"大学生扫地"<<endl;
	}
};

//学雷锋的志愿者，相当于ConcreteProduct
class Volenter: public LeiFeng
{
public :
	virtual void Sweep()
	{
		cout<<"志愿者"<<endl;
	}
};
//工场基类Creator-接口,工厂中创建一个基类对象，依赖Product 
class LeiFengFactory
{
public:
	virtual LeiFeng* CreateLeiFeng()=0;
//	{
//		return new LeiFeng();
//	}
};
//这种一个类的方法返回另一个类的对象，
//就是依赖关系，注意跟聚合的区别。 
class StudentFactory : public LeiFengFactory
{
public ://原来返回类形都是LeiFeng,但其实不好，最好只跟Student有依赖关系不要与基类 
	virtual Student* CreateLeiFeng()
	{
		return new Student();
	}
};
class VolenterFactory : public LeiFengFactory
{
public:
	virtual Volenter* CreateLeiFeng()
	{
		return new Volenter();
	}
};
//客户端
int main()
{
	LeiFengFactory *sf=new VolenterFactory ();
	LeiFeng *s=sf->CreateLeiFeng();
	s->Sweep();
	delete s;
	delete sf;
	system("pause"); 
	return 0;
}
