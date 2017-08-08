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
	State* current;//聚合关系 
public:
	double hour;
public:
	Work();
	void SetState(State* temp)
	{
       current =temp;
	}
	void Writeprogram()//work和state都有写程序方法，实际上不是同一个，而是调用另一个 
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
			cout<<"还不错啦"<<endl;
		else
			cout<<"不行了，还是睡觉吧"<<endl;
	}
};

class ForenoonState : public State
{
public:
	virtual void WriteProgram(Work* w)
	{
		if((w->hour)<12)
			cout<<"现在的精神无敌好"<<endl;
		else
		{
			w->SetState(new NoonState());
			w->Writeprogram(); //注意加上这句,执行NoonState的方法 
		}
	}
};
//可以再增加AfterNoonState状态，NooState中的处理与ForenoonState一样，这样
//可以链式判断下去，与if else的作用是一样的。 

Work::Work()
{
		current = new ForenoonState();
}//work构造函数中设定当前（初始的）的状态 

//客户端：
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
