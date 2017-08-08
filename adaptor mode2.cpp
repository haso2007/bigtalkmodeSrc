#include <iostream>
#include <string>
using namespace std;

class Player
{
protected:
	string name;
public:
	Player(string strName) { name = strName+ ":"; }
	virtual void Attack()=0;
	virtual void Defense()=0;
};

class Forwards : public Player
{
public:
	Forwards(string strName):Player(strName){}
public:
	virtual void Attack()
	{
		cout<<name<<"Forwards attack"<<endl;
	}
	virtual void Defense()
	{
		cout<<name<<"Forwards defense"<<endl;
	}
};
//����з��������ģ�������д�ģ�����һ�������ǽӿڲ�һ������ô�� 
class Center 
{
private:
    string name;      
public:
	Center(string strName)
	{name = strName + ":";}
public://����з�ֻ����ChineseAttach���������������Attach����˼ 
	void JingGong()
	{
		cout<<name<<"�г�����"<<endl;
	}
	void FanShou()
	{
	    cout<<name<<"�г�����"<<endl;
	}
};

//Ϊ�г�����
class TransLater: public Player
{
private:
	Center *player;//ָ��Center�����player��Ҫ���룬�����˿���  
public://�̳и���Ĺ��캯����ͬʱ�������˿ڽӿ�ʵ�� 
	TransLater(string strName):Player(strName)
	{
		player = new Center(strName);
	}
	virtual void Attack()//������תΪӢ�ĵ�һ���Խӿ� 
	{
		player->JingGong();
	}
	virtual void Defense()
	{
		player->FanShou();
	}
};


//�ͻ���
int main()
{
	Player *Cp=new TransLater("Ҧ��");
	Player *Fp = new Forwards("Rose");
	Cp->Attack();//��ʱ�����˿ھͿ��Ժͱ�����һ��ʹ��Attach������
    Fp->Attack() ;//һ���ķ���ȴ����������, ����Rose��Ҧ�������ö��� 
    delete(Cp);
    delete(Fp);
	system("pause");
	return 0;
}
