#include <string>
#include <iostream>
#include <vector>//��������
using namespace std;

class SecretaryBase;
//����۲���
class CObserverBase
{
protected:
	string name;
	SecretaryBase* sub;
public:
	CObserverBase(string strname,SecretaryBase* strsub)
	{
		name=strname;
		sub=strsub;
	}
	virtual void Update()=0;
};
//����Ĺ۲��ߣ�����Ʊ��
class StockObserver : public CObserverBase
{
public://���캯���̳��Ի���Ĺ��캯��
	StockObserver(string strname,SecretaryBase* strsub) : CObserverBase(strname,strsub)
	{
	}
	virtual void Update();
};

//����۲��ߣ���NBA��
class NBAObserver : public CObserverBase
{
public:
	NBAObserver(string strname,SecretaryBase* strsub) : CObserverBase(strname,strsub){}
	virtual void Update();
};


//����֪ͨ��
class SecretaryBase
{
public:
	string action;
	vector<CObserverBase*> observers;//�ۺϹ�ϵ ���������������Ӧ������ 
public:
	virtual void Attach(CObserverBase* observer)=0;
	virtual void Notify()=0;
};

//����֪ͨ��
class Secretary :public SecretaryBase
{
public:
	void Attach(CObserverBase* ob)
	{
		observers.push_back(ob);
	}
	void Notify()
	{
        vector<CObserverBase*>::iterator p = observers.begin();
		while (p!=observers.end())
		{
			(*p)->Update();
			p++;
		}
	}
};
void StockObserver::Update()
{
	cout<<name<<":"<<sub->action<<",��Ҫ���Ʊ�ˣ�Ҫ��ʼ������"<<endl;
}
void NBAObserver::Update()
{
	cout<<name<<":"<<sub->action<<",��Ҫ��NBA�ˣ��ϰ�����"<<endl;
}


//�ͻ��ˣ�
int main()
{
    SecretaryBase *p=new Secretary();  //�����۲���
	
	//���۲�Ķ��󣬹��캯������������ 
	CObserverBase *s1= new NBAObserver("С��",p);
	CObserverBase *s2 = new StockObserver("С��",p);
    //����۲����
	p->Attach(s1);
	p->Attach(s2);
    //�¼�
	p->action="�ϰ�����";
	//֪ͨ
	p->Notify();
    system("pause");
	return 0;
}

