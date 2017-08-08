#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Singelton
{
private:
	Singelton(){}//���캯��˽�л���û���ܴ���ʵ���ˡ� 
	static Singelton* singel;

public:
	static Singelton* GetInstance()
	{
		if(singel == NULL)
		{
			singel = new Singelton();
		}
		return singel;//����һ����̬ʵ��������ֻ��һ���ˡ� 
	}

};
Singelton* Singelton::singel = NULL;//ע�⾲̬����,ֻ�������ʼ��

//�ͻ��ˣ�
int main()
{
	Singelton* s1=Singelton::GetInstance();
	Singelton* s2=Singelton::GetInstance();
	Singelton* s3=Singelton::GetInstance();	
	if(s1 == s3)
		cout<<"����������ͬ��ʵ��"<<endl; 
	else
		cout<<"������ʵ����һ��"<<endl;
		
		system("pause");
	return 0;
}
