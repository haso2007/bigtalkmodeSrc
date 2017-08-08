#include <string>
#include <iostream>
using namespace std;
//ʵ�����࣬�൱��Product(Ϊ�˷��㣬û�ó���)
//sean ��ѭ���ྡ���ǳ�����ԭ��ʵ���������ʵ��
//�кܶ�ô���LeiFenFactoryֻ��һ���ӿ��� 
//LeifengҲֻ��һ�������࣬�������ڲ��ֶΣ�����򻯡� 
class LeiFeng
{
public:
	virtual void Sweep()=0;
//	{
//		cout<<"�׷�ɨ��"<<endl;
//	}
};

//ѧ�׷�Ĵ�ѧ�����൱��ConcreteProduct
class Student: public LeiFeng
{
public:
	virtual void Sweep()
	{
		cout<<"��ѧ��ɨ��"<<endl;
	}
};

//ѧ�׷��־Ը�ߣ��൱��ConcreteProduct
class Volenter: public LeiFeng
{
public :
	virtual void Sweep()
	{
		cout<<"־Ը��"<<endl;
	}
};
//��������Creator-�ӿ�,�����д���һ�������������Product 
class LeiFengFactory
{
public:
	virtual LeiFeng* CreateLeiFeng()=0;
//	{
//		return new LeiFeng();
//	}
};
//����һ����ķ���������һ����Ķ���
//����������ϵ��ע����ۺϵ����� 
class StudentFactory : public LeiFengFactory
{
public ://ԭ���������ζ���LeiFeng,����ʵ���ã����ֻ��Student��������ϵ��Ҫ����� 
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
//�ͻ���
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
