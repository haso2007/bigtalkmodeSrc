#include <iostream> 
/*所谓namespace，是指标识符的各种可见范围。C++标准程序库中的所有标识符都被定义于一个名为std的namespace中。
c++标准为了和C区别开，也为了正确使用命名空间，规定头文件不使用后缀.h。 因 此，当使用<iostream.h>时，相当于在c中调用库函数，使用的是全局命名空间，也就是早期的c++实现；当使用< iostream>的时候，该头文件没有定义全局命名空间，必须使用namespace std；这样才能正确使用cout。
*/
using namespace std; 
//基类
class COperation
{
public:
	int m_nFirst;
	int m_nSecond;
//protected:	C#中要加protected 
    virtual double GetResult()=0;//虚函数是一种实现父类/抽象类使用实现类方法的多态法，
/*	{
		double dResult=0;
		return dResult;
	}*/
};
//加法
class AddOperation : public COperation
{
public:
	virtual double GetResult()
	{
		return m_nFirst+m_nSecond;
	}
};
//减法
class SubOperation : public COperation
{
public:
	virtual double GetResult()
	{
		return m_nFirst-m_nSecond;
	}
};
//乘法
class MulOperation : public COperation
{
public:
	virtual double GetResult()
	{
		return m_nFirst*m_nSecond;
	}
};
//除法
class DivOperation : public COperation
{
public:
	virtual double GetResult()
	{
            if(m_nSecond == 0)
            {
            throw("除数不能为0。");
            }
		return m_nFirst/m_nSecond;
	}
};
//工厂类,将唯一不同或者以后可能更改的部分放在工厂中。这里唯一不同是操作符 
//哪些可能要改，复杂的这就是UML工具来帮忙做分析与设计 
class CCalculatorFactory
{
public:
	static COperation* Create(char cOperator);
};
//类中方法实现需要将类也写出，中间::，C结构只能用函数指针或者需重写时用回调函数来实现 
COperation* CCalculatorFactory::Create(char cOperator)
{
	COperation *oper;
    //在C#中可以用反射来取消判断时用的switch，在C++中用什么呢？RTTI？？
	switch (cOperator)
	{
	case '+'://基类可直接使用实现类中的方法 
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
	return oper;//返回类指针，注意无法直接返回类，但C#中可以。 
}

//客户端
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
