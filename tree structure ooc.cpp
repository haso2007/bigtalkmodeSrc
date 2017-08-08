
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
//	virtual void Add(Component* com)=0;//�����������ǰ�ȫģʽ 
public:
       	virtual void Display(int nDepth)=0;
};

class Leaf : public Component
{
public:
	Leaf(string strName): Component(strName){}

/*	virtual void Add(Component* com)//ͳһ�Ľӿڣ�͸��ģʽ 
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
		strtemp += m_strName; //m_strNameֱ�����Ի��࣬���������ٶ� 
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

//�ͻ���
//#include "Model.h"

int main()
{   //�����ڵ� 
	Composite* p=new Composite("IKA �����ܹ�˾");
	p->Add(new Leaf("���²�"));
	p->Add(new Leaf("����"));
	//Composite* p1 = p->Add(new Composite("�����ֹ�˾") ��ʽ����)

	Composite* p1 = new Composite("�����ֹ�˾");
	p1->Add(new Leaf("���²�"));
	p1->Add(new Leaf("����"));
	
	Composite* p2 = new Composite("�Ͼ����´�");
	p2->Add(new Leaf("���²�"));
	p2->Add(new Leaf("����"));	
//�齨�ṹ	
	p->Add(p1);
	p1->Add(p2);
//ȫ������	
	p->Display(1);//�ͻ��˿����ã���ʵ�ͻ���Ҳ��һ���� 
	
	p->Remove(p1);
	p1->Remove(p2);
	p->Display(1);
	system("pause");
	return 0;
}

