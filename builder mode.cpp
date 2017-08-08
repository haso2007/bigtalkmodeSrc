#include<iostream>
#include <vector>
#include <string>
using namespace std;
//创建者模式
//细节在builde或其子类中实现，而完成整个工程由director指近builder的主法来完成。 
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
         m_fatname = "无名" ;        
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
       //特别是当CreatMan需要复杂算法时，而这些算法由具体build组成时。 
       void CreatMan()//包含一个Bulder使用它的方法实现CreatMan 
       {
               m_builder->BuildHead();
               m_builder->BuildArm();
       }           
};   
      
int main()
{
    Builder *bp =  new FatBuilder("小李");
    Director *bd = new Director(bp);
    bd->CreatMan();//发命令建造一个人。。 
    delete(bp);
    delete(bd);
    system("pause");
    return 0;
}       
  
