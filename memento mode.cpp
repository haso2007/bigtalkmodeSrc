#include <iostream>
#include <string>
using namespace std;

class Memo;

//发起人类，只有它才能访问备忘录，为什么它不包含一个Memo对象呢？
//因为要在发起人之外保存这个状态，而且它不是必需的，可能一些originator无需
//保存，如果让它包含，那将占很大资源。而这个模式可以在需要时才由管理者创建
//这也是符合独一职责原则 
class Originator
{
public:
	string state;
    Memo* CreateMemo();
	void SetMemo(Memo* memo);
	void Show()
	{
		cout<<"当前状态："<<state<<endl;
	}
};
//备忘录类，不知道originator和Caretaker，它只是一个盒子，所以不要搞复杂它。
//这个盒子来可以用于其它东西的保存，没有耦合就可以被其它使用
//所以必需增加一个Caretaker。 盒子本身只有数据，没有任务方法的。 
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
    cout<<"现在保存目前状态"<<endl;  
	return new Memo(state);
}

void Originator::SetMemo(Memo* memo)
{
	cout<<"现在从断点恢复"<<endl; 
    state = memo->state;
}

//管理者类，作用用仅仅是包含一个Memo，国为Memo不能是客户端创建的，
//而只能是发起人创建，所以一定需要一个只含一个Memo的管理者来创建一个
//对象指针，并把orginal创建的Memo赋值给它 
class Caretaker
{
public:
	Memo* memo;
};

//客户端：
int main()
{
	Originator* on=new Originator();
	on->state = "状态0";
	on->Show();
    //由mem管理者创建一个mem盒子，并且将发起人的状态（或内容）存在盒子中 
	Caretaker* c= new Caretaker();
	c->memo = on->CreateMemo();
   /* Memo *mP = new Memo();
    mp = on->CreateMemo();为何不直接创建一个Memo呢，因为Memo是original才能创建的*/
	on->state = "状态1";
	on->Show();

	on->SetMemo(c->memo);//只有发起人才能对盒子操作，读取盒子内容恢复到当前中 
	on->Show();
	system("pause");
	return 0;
}
