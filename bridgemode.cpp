#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstractSoft
{
      protected:
              string str_name;
              
      public:
             AbstractSoft(string m_strname)
             {
               str_name = m_strname;                   
             }
             virtual string softFun() = 0;//不要加{},加{}则不加=0 
};
class Soft1 : public AbstractSoft
{
      public:
             Soft1(string m_strname) : AbstractSoft( m_strname){};//引用不再加string 
             
             virtual string softFun()
              {
                   string m_string;
                   m_string = str_name;//+":存诸联系人地址";
                  // cout<<str_name<<"这是一个小游戏"<<endl; 
                  return m_string; 
              }       
};
class Soft2 : public AbstractSoft
{
      public:
             Soft2(string m_strname) : AbstractSoft(m_strname){}
      virtual string softFun()
              {
                   string m_string;
                   m_string = str_name;//+":这是一个小游戏";
                  // cout<<str_name<<"这是一个小游戏"<<endl; 
                  return m_string;
              }       
};

class AbstractPhone
{
      protected:
              string str_name;
              AbstractSoft* soft;
      public:
             AbstractPhone(AbstractSoft* m_soft)
             {
               soft = m_soft;                   
             }
             virtual void PhoneBrand() = 0;
                
};

class PhoneM : public AbstractPhone
{

      public:
             PhoneM(AbstractSoft* m_soft) : AbstractPhone( m_soft){}

             virtual void PhoneBrand() 
             {
                  cout<<"这是一个M品牌手机装有软件" <<soft->softFun()<<endl;  
             }  
};

class PhoneN : public AbstractPhone
{

      public:
             PhoneN(AbstractSoft* m_soft) : AbstractPhone( m_soft){}

             virtual void PhoneBrand() 
             {
                  cout<<"这是一个N品牌手机装有软件" <<soft->softFun()<<endl;  
             }  
};


//客户端：
int main()
{
 AbstractSoft *psoft1 = new Soft1("通讯录");   
 AbstractPhone *pms1 = new PhoneM(psoft1);
 pms1->PhoneBrand();
 
 AbstractSoft *psoft2 = new Soft2("小游戏");   
 AbstractPhone *pms2 = new PhoneN(psoft2);
 pms2->PhoneBrand();
 system("pause");
	return 0;
}
