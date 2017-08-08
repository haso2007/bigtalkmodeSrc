#include <iostream>
#include <string>
using namespace std;

class Memo;

//�������ֻ࣬�������ܷ��ʱ���¼��Ϊʲô��������һ��Memo�����أ�
//��ΪҪ�ڷ�����֮�Ᵽ�����״̬�����������Ǳ���ģ�����һЩoriginator����
//���棬��������������ǽ�ռ�ܴ���Դ�������ģʽ��������Ҫʱ���ɹ����ߴ���
//��Ҳ�Ƿ��϶�һְ��ԭ�� 
class Originator
{
public:
	string state;
    Memo* CreateMemo();
	void SetMemo(Memo* memo);
	void Show()
	{
		cout<<"��ǰ״̬��"<<state<<endl;
	}
};
//����¼�࣬��֪��originator��Caretaker����ֻ��һ�����ӣ����Բ�Ҫ�㸴������
//��������������������������ı��棬û����ϾͿ��Ա�����ʹ��
//���Ա�������һ��Caretaker�� ���ӱ���ֻ�����ݣ�û�����񷽷��ġ� 
class Memo
{
public:
	string state; 
	Memo(string strState)
	{
		state = strState;
	}
};

Memo* Originator::CreateMemo()
{
    cout<<"���ڱ���Ŀǰ״̬"<<endl;  
	return new Memo(state);
}

void Originator::SetMemo(Memo* memo)
{
	cout<<"���ڴӶϵ�ָ�"<<endl; 
    state = memo->state;
}

//�������࣬�����ý����ǰ���һ��Memo����ΪMemo�����ǿͻ��˴����ģ�
//��ֻ���Ƿ����˴���������һ����Ҫһ��ֻ��һ��Memo�Ĺ�����������һ��
//����ָ�룬����orginal������Memo��ֵ���� 
class Caretaker
{
public:
	Memo* memo;
};

//�ͻ��ˣ�
int main()
{
	Originator* on=new Originator();
	on->state = "״̬0";
	on->Show();
    //��mem�����ߴ���һ��mem���ӣ����ҽ������˵�״̬�������ݣ����ں����� 
	Caretaker* c= new Caretaker();
	c->memo = on->CreateMemo();
   /* Memo *mP = new Memo();
    mp = on->CreateMemo();Ϊ�β�ֱ�Ӵ���һ��Memo�أ���ΪMemo��original���ܴ�����*/
	on->state = "״̬1";
	on->Show();

	on->SetMemo(c->memo);//ֻ�з����˲��ܶԺ��Ӳ�������ȡ�������ݻָ�����ǰ�� 
	on->Show();
	system("pause");
	return 0;
}
