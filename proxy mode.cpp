#include <string>
#include <iostream>
using namespace std;
//����ӿڣ�ʹ�ô��麯�����޷�ʵ���� 
class Interface
{
public:
	virtual void Request()=0;//=0��ʾ�Ӻ���virtual��������ʵ�֣���0��һ�� 
	//��Ӹ���Ĺ��������� 
};
//��ʵ��
class RealClass : public Interface
{
public:
	virtual void Request()
	{
		cout<<"��ʵ������"<<endl;
	}
	//����������ְ�� 
};
//������
class ProxyClass : public Interface
{
private:
	RealClass* m_realClass;
public:
	virtual void Request()
	{
        cout<<"�Ҵ��������������"<<endl;    
	    m_realClass= new RealClass();//��ʼ���������ˣ���Ϲ�ϵ 
		m_realClass->Request();
		delete m_realClass;//����������ɺ󣬻��տռ� ��ǳ���Ҫ 
	}
};

//�ͻ��ˣ�
int main()
{
	ProxyClass* test=new ProxyClass();
	test->Request();
	system("pause");
	return 0;
}
