#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�������վ
class WebSite
{
public:
	virtual void Use()=0;
};

//����Ĺ�����վ
class ConcreteWebSite : public WebSite
{
private:
	string name;
public:
	ConcreteWebSite(string strName)
	{
		name = strName;
	}
	virtual void Use()
	{
		cout<<"��վ���ࣺ"<<name<<endl;
	}
};

//���������վ
class UnShareWebSite : public WebSite
{
private:
	string name;
public:
	UnShareWebSite(string strName)
	{
		name = strName;
	}
	virtual void Use()
	{
		cout<<"���������վ��"<<name<<endl;
	}
};

//��վ�����࣬���ڴ�Ź����WebSite����
class WebFactory
{
private:
	vector<WebSite*> websites;
public:
	WebSite* GetWeb()
	{
		vector<WebSite*>::iterator p = websites.begin();
		return *p;
	}
	WebFactory()
	{
		websites.push_back(new ConcreteWebSite("����"));
	}
};

//�ͻ���
int main()
{
	WebFactory* f= new WebFactory();
	WebSite* ws= f->GetWeb();
	ws->Use();

	WebSite* ws2 = f->GetWeb();
	ws2->Use();

	//���������
	WebSite* ws3 = new UnShareWebSite("����");
	ws3->Use();
	system("pause");
	return 0;
}
