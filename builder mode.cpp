#include<iostream>
#include <vector>
#include <string>
using namespace std;
//������ģʽ
//ϸ����builde����������ʵ�֣����������������directorָ��builder����������ɡ� 
class Builder //end of class need ; always,to seperate class and fuction
{
public://all abstrcat mehtod need to be instantiation in all the subclass 
       virtual void BuildHead() = 0;
       virtual void BuildArm() = 0;
}; 

class FatBuilder: public Builder
{
private:
        string m_fatname;      
public:
       FatBuilder(string name)
       {
         m_fatname = name;               
         }
       FatBuilder()
       {
         m_fatname = "����" ;        
         }      
       virtual void BuildHead()
       {
         cout<<"build a fat man"<<m_fatname<<endl;       
       };
       virtual void BuildArm()
       {
          cout << "build a big arm"<<endl;       
          }
};
      
class Director //not inherit from Builder but contain one Builder Object
{
private:
         Builder *m_builder;
public:
       Director(Builder *arg1)
       {
           m_builder = arg1;  
                      
       }  
       //�ر��ǵ�CreatMan��Ҫ�����㷨ʱ������Щ�㷨�ɾ���build���ʱ�� 
       void CreatMan()//����һ��Bulderʹ�����ķ���ʵ��CreatMan 
       {
               m_builder->BuildHead();
               m_builder->BuildArm();
       }           
};   
      
int main()
{
    Builder *bp =  new FatBuilder("С��");
    Director *bd = new Director(bp);
    bd->CreatMan();//�������һ���ˡ��� 
    delete(bp);
    delete(bd);
    system("pause");
    return 0;
}       
  
