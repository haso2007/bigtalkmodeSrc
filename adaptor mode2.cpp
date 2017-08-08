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
//这个中锋是外来的，不是我写的，功能一样，但是接口不一样，怎么办 
class Center 
{
private:
    string name;      
public:
	Center(string strName)
	{name = strName + ":";}
public://这个中锋只懂得ChineseAttach这个方法，不明白Attach的意思 
	void JingGong()
	{
		cout<<name<<"中场进攻"<<endl;
	}
	void FanShou()
	{
	    cout<<name<<"中场防守"<<endl;
	}
};

//为中场翻译
class TransLater: public Player
{
private:
	Center *player;//指定Center类对象player需要翻译，外来人口啦  
public://继承父类的构造函数，同时将外来人口接口实现 
	TransLater(string strName):Player(strName)
	{
		player = new Center(strName);
	}
	virtual void Attack()//将中文转为英文的一般性接口 
	{
		player->JingGong();
	}
	virtual void Defense()
	{
		player->FanShou();
	}
};


//客户端
int main()
{
	Player *Cp=new TransLater("姚明");
	Player *Fp = new Forwards("Rose");
	Cp->Attack();//这时外来人口就可以和本地人一样使用Attach方法。
    Fp->Attack() ;//一样的方法却有两国语言, 这样Rose和姚明都听得懂了 
    delete(Cp);
    delete(Fp);
	system("pause");
	return 0;
}
