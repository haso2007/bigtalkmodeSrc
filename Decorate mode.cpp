
#include <string>
#include <iostream>
using namespace std;
//人 是一个抽象的接口,C++中没有abstract,也没有抽象类，只有用virtual只能修饰方法
//如果有女同事那她是一定要先穿胸衣的，那就要增加ConcretComponent了。 
class Person                                                         //这里真正变成一个抽象类，具体名字移到实现类中 
{
      
//private:
//	string m_strName;
public:   
//	Person(string strName)
//	{
//		m_strName=strName;
//	}
//	Person(){}//这里重载，可以没有名字 
	virtual void Show()=0;//纯虚函数,相当于abstract也可以只留一个大括号.但是=0有利于 
//	{继承类的类型检查，如MalePerson写为 show会报错，但大括号不会。 
//		cout<<"装扮的是:"<<m_strName<<endl;//C++串尾显示，C#直接用+号 ，如Console.Write(""+m_strname) 
//	}
};

class FemalePerson:public Person
{
      private:
              string m_strName;  
      public:
             FemalePerson(string strName)   //在引用new时使用的构造函数,无需类型 
             {
                  m_strName =  strName;               
             }
             FemalePerson()
             {
                 m_strName = "无名";          
             }            
             virtual void Show()
             {
             cout<<"装扮的是:男性"<<m_strName<<endl;
             }
};

class MalePerson:public Person
{
      private:
              string m_strName; 
    //  protected:
            //   Person* m_component; //C#中无需加此字段，调用父类的构造函数只需用base即可 
      public:
             MalePerson(string strName)   //在引用new时使用的构造函数,无需类型 
             {
                  m_strName =  strName;               
             }
             MalePerson()
             {
                 m_strName = "无名";          
             }            
             virtual void Show()
             {
             cout<<"胸衣\n"<<"装扮的是:女性"<<m_strName<<endl;
             }
};
//装饰类,在客户端中是不用出现的，与上下文是不同的。聚合+继承的关系 
class Finery : public Person //C++ 父类的类型public要加,c#中不用加 
{
protected:
	Person* m_component;
public://子类对象可以直接使用 
	void Decorate(Person* component) 
	{
		m_component=component;
	}
	virtual void Show()
	{
		   m_component->Show();
	}
};
//T恤 等等对象会根据调用顺序而链式显示出来。只要改下顺序就可以得到不同顺序 
class TShirts: public Finery
{
public:
	virtual void Show()
	{
		cout<<"T Shirts"<<endl;
		m_component->Show();//直接使用父类中protected的字段,而这个show具体实现就要看m_component了。 
	}//如果m_component还是 TShirt的引用则会 引起死循环 
};
//裤子
class BigTrouser :public  Finery
{
public:
	virtual void Show()
	{
		cout<<"Big Trouser"<<endl;
		m_component->Show();
	}
};

//客户端
int main()
{
	MalePerson *p=new MalePerson();
	FemalePerson *p1 =  new FemalePerson("小王"); 
	BigTrouser *bt=new BigTrouser();
	TShirts *ts=new TShirts();
  //如果bt 的方法Decorate(arg),arg 还是bt则会无限循环。 完全可用子类对象代替基类 
	ts->Decorate(p);// 注意是 bt调用基类人，第一次修饰,先显示ts本身的show()结果 
	bt->Decorate(ts);//然后ts又调用了bt,再修饰上面 
	bt->Show();      //最后才show出来。
    //ts->Show(); 
	system("pause");
	//return 0;
}
