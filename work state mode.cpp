#include <iostream>
using namespace std;

class Work;
class ForenoonState;
class NoonState;

class State
{
public:
	virtual void WriteProgram(Work* w)=0;
};

class Work
{
private:
	State* current;//�ۺϹ�ϵ 
public:
	double hour;
public:
	Work();
	void SetState(State* temp)
	{
       current =temp;
	}
	void Writeprogram()//work��state����д���򷽷���ʵ���ϲ���ͬһ�������ǵ�����һ�� 
	{
		current->WriteProgram(this);
	}

};

class NoonState :public State
{
public:
	virtual void WriteProgram(Work* w)
	{
		cout<<"execute"<<endl;
		if((w->hour)<13)
			cout<<"��������"<<endl;
		else
			cout<<"�����ˣ�����˯����"<<endl;
	}
};

class ForenoonState : public State
{
public:
	virtual void WriteProgram(Work* w)
	{
		if((w->hour)<12)
			cout<<"���ڵľ����޵к�"<<endl;
		else
		{
			w->SetState(new NoonState());
			w->Writeprogram(); //ע��������,ִ��NoonState�ķ��� 
		}
	}
};
//����������AfterNoonState״̬��NooState�еĴ�����ForenoonStateһ��������
//������ʽ�ж���ȥ����if else��������һ���ġ� 

Work::Work()
{
		current = new ForenoonState();
}//work���캯�����趨��ǰ����ʼ�ģ���״̬ 

//�ͻ��ˣ�
int main()
{
	Work* mywork=new Work();
	mywork->hour=9;
	mywork->Writeprogram();
	mywork->hour = 14;
	mywork->Writeprogram();
	system("pause");
	return 0;
}
