#include <string>
#include <iostream>
using namespace std;
//运算基类 
class Operation 
{
private:
        double Number_A ;
        double Number_B ;      
public:
    double Get_A(){return Number_A;}
    double Set_A(int avalue){Number_A = avalue;}
    double Get_B(){return Number_B;}  
    double Set_B(int bvalue){Number_B = bvalue;}
	virtual double GetResult()=0; //纯虚函数，实现类无实现则报错 

};
//具体实现运算类 + 
class AddOperation: public Operation 
{
public:
	virtual double GetResult()
	{
		return (Get_A()+Get_B());
	}
};

//工场基类Creator-接口,赖运算基类 
class OperationFactory
{
public:
	virtual Operation* CreateOperation()=0;

};
//工场实现类 Concrete
class AddOperationFactory : public OperationFactory
{
public : 
	virtual AddOperation* CreateOperation()
	{
		return new AddOperation();
	}
};

//客户端
int main()
{   //创建+对象，如需其它，扩展加入即可，不需修改原来任何类 
    int a,b;
	OperationFactory *ofP=new AddOperationFactory ();
	Operation *s=ofP->CreateOperation();
	cin>>a>>b;
	s->Set_A(a);
	s->Set_B(b);
	cout << s->GetResult()<< endl;
	delete s;
	delete ofP;
	system("pause"); 
	return 0;
}
