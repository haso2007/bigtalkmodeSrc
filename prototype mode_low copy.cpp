#include<iostream>
#include <vector>
#include <string>
using namespace std;

class WorkExp
{
public:
        string m_workdate;
        string m_company;
/*        
public:
        void Set_WorkDate(string strwork)
        {
            m_workdate = strwork;                
        }       
        void Set_Company(string strcom)
        {
            m_company = strcom;                
        }   */       
};
class Prototype //������� 
{ 
private:
	string m_strName;
	WorkExp *workp;
public: 
	Prototype(string strName)//ֻ�й��캯���������� 
    { 
    m_strName = strName; 
    workp =  new WorkExp();
    }
	Prototype()//ֻ�й��캯���������� 
    { 
    m_strName = "����"; 
    workp =  new WorkExp();
    }    
    void SetWorkExp(string workdata, string company)
    {
     //  Prototype(this.workp);   
     // workp->Set_WorkDate(workdata);
      workp->m_workdate = workdata;
      //workp->Set_Company(company);
      workp->m_company = company;
    }
	void Show() //private���ֶ�ֻ������Щ�������á���ʹ�����ط�������һ������Ҳ������private�ֶΡ� 
	{
		cout<<m_strName<<workp->m_workdate<<workp->m_company<<endl;
	}
	virtual Prototype* Clone() = 0 ; 
} ; 

// class ConcretePrototype1 
class ConcretePrototype : public Prototype 
{ 
public: 
	ConcretePrototype(string strName) : Prototype(strName){}
	ConcretePrototype(){}

	virtual Prototype* Clone() 
	{ 
		ConcretePrototype *p = new ConcretePrototype() ; 
		*p = *this ; //���ƶ���ע����p=this������ 
		return p ; 
	} 
} ; 



//�ͻ���
int main()
{
	ConcretePrototype* test = new ConcretePrototype();
	test -> SetWorkExp("2008-2012","IKA");
	test->Show();
	ConcretePrototype* test2 = (ConcretePrototype*)test->Clone();
	test2 -> SetWorkExp("2004-2008","Jetta");
	test2->Show();
	ConcretePrototype* test3 = (ConcretePrototype*)test->Clone();
	test3 -> SetWorkExp("2004-2008","xxxx");
	test3->Show();




	delete(test);
	delete(test2);
	delete(test3);
	system("pause");
	return 0;
}
