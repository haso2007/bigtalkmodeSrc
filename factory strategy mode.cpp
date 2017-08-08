#include <iostream> 
#include <math.h>
/*��νnamespace����ָ��ʶ���ĸ��ֿɼ���Χ��C++��׼������е����б�ʶ������������һ����Ϊstd��namespace�С�
c++��׼Ϊ�˺�C���𿪣�ҲΪ����ȷʹ�������ռ䣬�涨ͷ�ļ���ʹ�ú�׺.h�� �� �ˣ���ʹ��<iostream.h>ʱ���൱����c�е��ÿ⺯����ʹ�õ���ȫ�������ռ䣬Ҳ�������ڵ�c++ʵ�֣���ʹ��< iostream>��ʱ�򣬸�ͷ�ļ�û�ж���ȫ�������ռ䣬����ʹ��namespace std������������ȷʹ��cout��
*/
using namespace std; 
//����
class COperation
{
public:
	int m_nFirst;
	int m_nSecond;
//protected:	C#��Ҫ��protected 
    virtual double GetResult()//�麯����һ��ʵ�ָ���/������ʹ��ʵ���෽���Ķ�̬����
	{
		double dResult=0;
		return dResult;
	}

};
//�ӷ�ʵ���� 
class AddOperation : public COperation
{
public:
	virtual double GetResult()
	{
		return m_nFirst+m_nSecond;
	}
};
//����
class SubOperation : public COperation
{
public:
	virtual double GetResult()
	{
		return m_nFirst-m_nSecond;
	}
};
//�˷�
class MulOperation : public COperation
{
public:
	virtual double GetResult()
	{
		return m_nFirst*m_nSecond;
	}
};
//����
class DivOperation : public COperation
{
public:
	virtual double GetResult()   //he
	{
        //    if(m_nSecond == 0)
        //    {
         //   throw("��������Ϊ0��");
         //   }
		return sqrt(m_nFirst);///m_nSecond;
	}
};
/* ���ù�����ͻ�����Ҫ�õ�����͹����� 
//������,��Ψһ��ͬ�����Ժ���ܸ��ĵĲ��ַ��ڹ����С�����Ψһ��ͬ�ǲ����� 
//��Щ����Ҫ�ģ����ӵ������UML��������æ����������� 
class CCalculatorFactory
{
public:
	static COperation* Create(char cOperator);
};
COperation* CCalculatorFactory::Create(char cOperator)
{
	COperation *oper;
    //��C#�п����÷�����ȡ���ж�ʱ�õ�switch����C++����ʲô�أ�RTTI����
	switch (cOperator)
	{
	case '+'://�����ֱ��ʹ��ʵ�����еķ��� 
		oper=new AddOperation();
		break;
	case '-':
		oper=new SubOperation();
		break;
	case '*':
		oper=new MulOperation();
		break;	
	case '/':
		oper=new DivOperation();
		break;	        	
	default:
		oper=new AddOperation();
		break;
	}
	return oper;//������ָ�룬ע���޷�ֱ�ӷ����࣬��C#�п��ԡ� 
}
*/
//����һ�������ģ��������÷���ʱֻ��Ҫ���������ģ���������� 
class Context
{                     //C++�е�ָ����Cһ��ǿ�� 
private:              //C++��һ��Ҫָ��new���ܴ��ݣ�C#��ֱ��������                                      
	COperation *oper;//UML������һ��aggregation�ۺϹ�ϵ����������
public:
    Context(int nfirst,char cOperator,int nsecond)
	{
    	switch (cOperator)
    	{
    	case '+'://�����ֱ��ʹ��ʵ�����еķ��� 
    		oper=new AddOperation();
    		oper->m_nFirst = nfirst;
    		oper->m_nSecond = nsecond;
    		break;
    	case '-':
    		oper=new SubOperation();
    		oper->m_nFirst = nfirst;
    		oper->m_nSecond = nsecond;    		
    		break;
    	case '*':
    		oper=new MulOperation();
    		oper->m_nFirst = nfirst;
    		oper->m_nSecond = nsecond;    		
    		break;	
    	case '/':
    		oper=new DivOperation();
    		oper->m_nFirst = nfirst;
    		oper->m_nSecond = nsecond;    		
    		break;	        	
    	default:
    		oper=new AddOperation();
    		oper->m_nFirst = nfirst;
    		oper->m_nSecond = nsecond;    		
    		break;
    	}
     }
	double GetResult()
	{
		return oper->GetResult();//����ֱ��ʹ��private 
	}
};

//�ͻ���
int main()
{
	int a,c;
	char b;
	cin>>a>>b>>c;
	Context *pCon=new Context(a,b,c);
	cout<<pCon->GetResult()<<endl;
	//return 0;
	system("cmd /k");
}
