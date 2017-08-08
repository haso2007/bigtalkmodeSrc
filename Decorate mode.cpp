
#include <string>
#include <iostream>
using namespace std;
//�� ��һ������Ľӿ�,C++��û��abstract,Ҳû�г����ֻ࣬����virtualֻ�����η���
//�����Ůͬ��������һ��Ҫ�ȴ����µģ��Ǿ�Ҫ����ConcretComponent�ˡ� 
class Person                                                         //�����������һ�������࣬���������Ƶ�ʵ������ 
{
      
//private:
//	string m_strName;
public:   
//	Person(string strName)
//	{
//		m_strName=strName;
//	}
//	Person(){}//�������أ�����û������ 
	virtual void Show()=0;//���麯��,�൱��abstractҲ����ֻ��һ��������.����=0������ 
//	{�̳�������ͼ�飬��MalePersonдΪ show�ᱨ���������Ų��ᡣ 
//		cout<<"װ�����:"<<m_strName<<endl;//C++��β��ʾ��C#ֱ����+�� ����Console.Write(""+m_strname) 
//	}
};

class FemalePerson:public Person
{
      private:
              string m_strName;  
      public:
             FemalePerson(string strName)   //������newʱʹ�õĹ��캯��,�������� 
             {
                  m_strName =  strName;               
             }
             FemalePerson()
             {
                 m_strName = "����";          
             }            
             virtual void Show()
             {
             cout<<"װ�����:����"<<m_strName<<endl;
             }
};

class MalePerson:public Person
{
      private:
              string m_strName; 
    //  protected:
            //   Person* m_component; //C#������Ӵ��ֶΣ����ø���Ĺ��캯��ֻ����base���� 
      public:
             MalePerson(string strName)   //������newʱʹ�õĹ��캯��,�������� 
             {
                  m_strName =  strName;               
             }
             MalePerson()
             {
                 m_strName = "����";          
             }            
             virtual void Show()
             {
             cout<<"����\n"<<"װ�����:Ů��"<<m_strName<<endl;
             }
};
//װ����,�ڿͻ������ǲ��ó��ֵģ����������ǲ�ͬ�ġ��ۺ�+�̳еĹ�ϵ 
class Finery : public Person //C++ ���������publicҪ��,c#�в��ü� 
{
protected:
	Person* m_component;
public://����������ֱ��ʹ�� 
	void Decorate(Person* component) 
	{
		m_component=component;
	}
	virtual void Show()
	{
		   m_component->Show();
	}
};
//T�� �ȵȶ������ݵ���˳�����ʽ��ʾ������ֻҪ����˳��Ϳ��Եõ���ͬ˳�� 
class TShirts: public Finery
{
public:
	virtual void Show()
	{
		cout<<"T Shirts"<<endl;
		m_component->Show();//ֱ��ʹ�ø�����protected���ֶ�,�����show����ʵ�־�Ҫ��m_component�ˡ� 
	}//���m_component���� TShirt��������� ������ѭ�� 
};
//����
class BigTrouser :public  Finery
{
public:
	virtual void Show()
	{
		cout<<"Big Trouser"<<endl;
		m_component->Show();
	}
};

//�ͻ���
int main()
{
	MalePerson *p=new MalePerson();
	FemalePerson *p1 =  new FemalePerson("С��"); 
	BigTrouser *bt=new BigTrouser();
	TShirts *ts=new TShirts();
  //���bt �ķ���Decorate(arg),arg ����bt�������ѭ���� ��ȫ����������������� 
	ts->Decorate(p);// ע���� bt���û����ˣ���һ������,����ʾts�����show()��� 
	bt->Decorate(ts);//Ȼ��ts�ֵ�����bt,���������� 
	bt->Show();      //����show������
    //ts->Show(); 
	system("pause");
	//return 0;
}
