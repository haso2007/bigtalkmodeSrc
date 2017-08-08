#include <iostream> 
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
    virtual double GetResult()=0;//�麯����һ��ʵ�ָ���/������ʹ��ʵ���෽���Ķ�̬����
/*	{
		double dResult=0;
		return dResult;
	}*/
};
//�ӷ�
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
	virtual double GetResult()
	{
            if(m_nSecond == 0)
            {
            throw("��������Ϊ0��");
            }
		return m_nFirst/m_nSecond;
	}
};
//������,��Ψһ��ͬ�����Ժ���ܸ��ĵĲ��ַ��ڹ����С�����Ψһ��ͬ�ǲ����� 
//��Щ����Ҫ�ģ����ӵ������UML��������æ����������� 
class CCalculatorFactory
{
public:
	static COperation* Create(char cOperator);
};
//���з���ʵ����Ҫ����Ҳд�����м�::��C�ṹֻ���ú���ָ���������дʱ�ûص�������ʵ�� 
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

//�ͻ���
int main()
{
	int a,c;
	char b;
	cin>>a>>b>>c;
	COperation * op=CCalculatorFactory::Create(b);
	op->m_nFirst=a;
	op->m_nSecond=c;
	cout<<op->GetResult()<<endl;
	//return 0;
	system("cmd /k");
}
