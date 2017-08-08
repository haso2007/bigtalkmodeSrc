
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Component
{
protected:
	string m_strName;
	Component(string strName)
	{
		m_strName = strName;
	}
//	virtual void Add(Component* com)=0;//不声明它则是安全模式 
public:
       	virtual void Display(int nDepth)=0;
};

class Leaf : public Component
{
public:
	Leaf(string strName): Component(strName){}

/*	virtual void Add(Component* com)//统一的接口，透明模式 
	{
		cout<<"leaf can't add"<<endl;
	}
*/
	virtual void Display(int nDepth)
	{
		string strtemp;
		for(int i=0; i < nDepth; i++)
		{
			strtemp+="-";
		}
		strtemp += m_strName; //m_strName直接来自基类，无需子类再定 
		cout<<strtemp<<endl;
	}
};

class Composite : public Component
{
private:
	vector<Component*> m_component;
public:
	Composite(string strName) : Component(strName){}

	virtual void Add(Component* com)
	{
		m_component.push_back(com);// 
	}
    virtual void Remove(Component* com)
    {
		vector<Component*>::iterator p=m_component.begin();
		while (p!=m_component.end())
		{
			if(*p == com)
            {
                  m_component.erase(p);
                  break;
            } 
			p++;
		}
    }
	virtual void Display(int nDepth)
	{
		string strtemp;
		for(int i=0; i < nDepth; i++)
		{
			strtemp+="-";
		}
		strtemp += m_strName;
		cout<<strtemp<<endl;

		vector<Component*>::iterator p=m_component.begin();
		while (p!=m_component.end())
		{
			(*p)->Display(nDepth+2); 
			p++;
		}
	}

};

//客户端
//#include "Model.h"

int main()
{   //创建节点 
	Composite* p=new Composite("IKA 广州总公司");
	p->Add(new Leaf("人事部"));
	p->Add(new Leaf("财务部"));
	//Composite* p1 = p->Add(new Composite("北京分公司") 链式操作)

	Composite* p1 = new Composite("北京分公司");
	p1->Add(new Leaf("人事部"));
	p1->Add(new Leaf("财务部"));
	
	Composite* p2 = new Composite("南京办事处");
	p2->Add(new Leaf("人事部"));
	p2->Add(new Leaf("财务部"));	
//组建结构	
	p->Add(p1);
	p1->Add(p2);
//全部历遍	
	p->Display(1);//客户端可引用，其实客户端也是一个类 
	
	p->Remove(p1);
	p1->Remove(p2);
	p->Display(1);
	system("pause");
	return 0;
}

