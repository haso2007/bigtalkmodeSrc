#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Singelton
{
private:
	Singelton(){}//构造函数私有化，没人能创建实例了。 
	static Singelton* singel;

public:
	static Singelton* GetInstance()
	{
		if(singel == NULL)
		{
			singel = new Singelton();
		}
		return singel;//这是一个静态实例，所以只有一个了。 
	}

};
Singelton* Singelton::singel = NULL;//注意静态变量,只能类外初始化

//客户端：
int main()
{
	Singelton* s1=Singelton::GetInstance();
	Singelton* s2=Singelton::GetInstance();
	Singelton* s3=Singelton::GetInstance();	
	if(s1 == s3)
		cout<<"这是两个相同的实例"<<endl; 
	else
		cout<<"这两个实例不一样"<<endl;
		
		system("pause");
	return 0;
}
