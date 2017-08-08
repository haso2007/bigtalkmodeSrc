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
             virtual string softFun() = 0;//��Ҫ��{},��{}�򲻼�=0 
};
class Soft1 : public AbstractSoft
{
      public:
             Soft1(string m_strname) : AbstractSoft( m_strname){};//���ò��ټ�string 
             
             virtual string softFun()
              {
                   string m_string;
                   m_string = str_name;//+":������ϵ�˵�ַ";
                  // cout<<str_name<<"����һ��С��Ϸ"<<endl; 
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
                   m_string = str_name;//+":����һ��С��Ϸ";
                  // cout<<str_name<<"����һ��С��Ϸ"<<endl; 
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
                  cout<<"����һ��MƷ���ֻ�װ�����" <<soft->softFun()<<endl;  
             }  
};

class PhoneN : public AbstractPhone
{

      public:
             PhoneN(AbstractSoft* m_soft) : AbstractPhone( m_soft){}

             virtual void PhoneBrand() 
             {
                  cout<<"����һ��NƷ���ֻ�װ�����" <<soft->softFun()<<endl;  
             }  
};


//�ͻ��ˣ�
int main()
{
 AbstractSoft *psoft1 = new Soft1("ͨѶ¼");   
 AbstractPhone *pms1 = new PhoneM(psoft1);
 pms1->PhoneBrand();
 
 AbstractSoft *psoft2 = new Soft2("С��Ϸ");   
 AbstractPhone *pms2 = new PhoneN(psoft2);
 pms2->PhoneBrand();
 system("pause");
	return 0;
}
