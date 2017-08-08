#include <string>
#include <iostream>
#include <vector>//容器向量
using namespace std;

class SecretaryBase;
//抽象观察者
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
//具体的观察者，看股票的
class StockObserver : public CObserverBase
{
public://构造函数继承自基类的构造函数
	StockObserver(string strname,SecretaryBase* strsub) : CObserverBase(strname,strsub)
	{
	}
	virtual void Update();
};

//具体观察者，看NBA的
class NBAObserver : public CObserverBase
{
public:
	NBAObserver(string strname,SecretaryBase* strsub) : CObserverBase(strname,strsub){}
	virtual void Update();
};


//抽象通知者
class SecretaryBase
{
public:
	string action;
	vector<CObserverBase*> observers;//聚合关系 ，两个抽象类耦合应尽量少 
public:
	virtual void Attach(CObserverBase* observer)=0;
	virtual void Notify()=0;
};

//具体通知者
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
	cout<<name<<":"<<sub->action<<",不要玩股票了，要开始工作了"<<endl;
}
void NBAObserver::Update()
{
	cout<<name<<":"<<sub->action<<",不要看NBA了，老板来了"<<endl;
}


//客户端：
int main()
{
    SecretaryBase *p=new Secretary();  //创建观察者
	
	//被观察的对象，构造函数有两个参数 
	CObserverBase *s1= new NBAObserver("小李",p);
	CObserverBase *s2 = new StockObserver("小赵",p);
    //加入观察队列
	p->Attach(s1);
	p->Attach(s2);
    //事件
	p->action="老板来了";
	//通知
	p->Notify();
    system("pause");
	return 0;
}

