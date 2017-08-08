#include <iostream>
#include <string>
#include <vector>
using namespace std;

//����ʦ��
class Barbucer
{
public:
	void MakeMutton()
	{
		cout<<"������"<<endl;
	}
	void MakeChickenWing()
	{
		cout<<"�������"<<endl;
	}
};

//����������
class Command
{
protected:
	Barbucer* receiver;
public:
	Command(Barbucer* temp)
	{
		receiver = temp;
	}
	virtual void ExecuteCmd()=0;
};

//����������
class BakeMuttonCmd : public Command
{
public:
	BakeMuttonCmd(Barbucer* temp) : Command(temp){}
	virtual void ExecuteCmd()
	{
		receiver->MakeMutton();
	}
};

//������
class ChickenWingCmd : public Command
{
public:
	ChickenWingCmd(Barbucer* temp) : Command(temp){}

	virtual void ExecuteCmd()
	{
		receiver->MakeChickenWing();
	}
};

//����Ա��
class Waiter
{
protected:
	vector<Command*> m_commandList;
public:
	void SetCmd(Command* temp)
	{
		m_commandList.push_back(temp);
		cout<<"���Ӷ���"<<endl;
	}
   void DelCmd(Command* temp)
   {
   vector<Command*>::iterator p=m_commandList.begin();
		while(p!=m_commandList.end())// p����������ָ���������ָ�� 
		{
            if((*p) == temp)
            {
                m_commandList.erase(p);
          		cout<<"�Ƴ�����"<<endl;
                break;    
            }                         
			p++;
		}        
   }
	//ִ֪ͨ��
	void Notify()
	{
		vector<Command*>::iterator p=m_commandList.begin();
		while(p!=m_commandList.end())
		{
			(*p)->ExecuteCmd();
			p++;
		}
	}
};

//�ͻ���
int main()
{
	//������ӿ���ʦ�����˵�������Ա�ȹ˿�
	Barbucer* barbucer=new Barbucer();
	Command* cmd= new BakeMuttonCmd(barbucer);
	Command* cmd2=new ChickenWingCmd(barbucer);
	Command* cmd3=new ChickenWingCmd(barbucer);
	Waiter* girl = new Waiter();
    //���
	girl->SetCmd(cmd);
	girl->SetCmd(cmd2);
	girl->SetCmd(cmd3);
    //����Ա֪ͨ
	girl->Notify();
	girl->DelCmd(cmd3);	
	girl->Notify();	
	system("pause");
	return 0;
}
