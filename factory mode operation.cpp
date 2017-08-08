#include <string>
#include <iostream>
using namespace std;
//������� 
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
	virtual double GetResult()=0; //���麯����ʵ������ʵ���򱨴� 

};
//����ʵ�������� + 
class AddOperation: public Operation 
{
public:
	virtual double GetResult()
	{
		return (Get_A()+Get_B());
	}
};

//��������Creator-�ӿ�,��������� 
class OperationFactory
{
public:
	virtual Operation* CreateOperation()=0;

};
//����ʵ���� Concrete
class AddOperationFactory : public OperationFactory
{
public : 
	virtual AddOperation* CreateOperation()
	{
		return new AddOperation();
	}
};

//�ͻ���
int main()
{   //����+����������������չ���뼴�ɣ������޸�ԭ���κ��� 
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
