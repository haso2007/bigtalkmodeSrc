#include <iostream>   
#include <string>
#include <vector>   
using namespace std;  
//����ģ�棬 ����д��֮�󣬼���������һ�� T  a ���Ժ�Ϊ a��ֵ ���ͣ���TΪint 
//UML����bind�󶨱�ʾ  
//��� �㸳ֵΪ double���͵�������ʱ T��Ϊdouble ��
//���������뼯�����κι�ϵ�����������ɹ���������ʹ��  
template<class Item>  
class Iterator  
{  
public:  
    virtual void first()=0;  //�����Ǹ����϶���Ҫ��Щ����������ǳ��� 
    virtual void next()=0;  //�����ĳ���������� 
    virtual Item* currentItem()=0;  
    virtual bool isDone()=0;  
    virtual ~Iterator(){}  
};  
  
template<class Item>  
class ConcreteAggregate;  
  
template<class Item>  
class ConcreteIterator : public Iterator <Item>  //����ĵ����㷨�뼯���йأ������ù�ϵ��
{  
    ConcreteAggregate<Item> * aggr;  //���ڳ��������ã�������������õĺô���
    int cur;                  //��������㷨��ʵ���������о���������Ϊ�㷨 ��������Զ��
public:  
    ConcreteIterator(ConcreteAggregate<Item>*a):aggr(a),cur(0){}  
    virtual void first()  
    {  
        cur=0;  
    }  
    virtual void next()  
    {  
        if(cur<aggr->getLen())  
            cur++;  
    }  
    virtual Item* currentItem()  
    {  
        if(cur<aggr->getLen())  
            return &(*aggr)[cur];  
        else  
            return NULL;  
    }  
    virtual bool isDone()  
    {  
        return (cur>=aggr->getLen());  
    }  
};  
  
template<class Item>  
class Aggregate  
{  
public:  
    virtual Iterator<Item>* createIterator()=0;  
    virtual ~Aggregate(){}  
};  
  
template<class Item>  
class ConcreteAggregate:public Aggregate<Item>  
{  
    vector<Item >data;  
public:  
    ConcreteAggregate()  
    {  
        data.push_back("С��");  
        data.push_back("С��");  
        data.push_back("��ͷ");  
    }  
    virtual Iterator<Item>* createIterator()  
    {  
        return new ConcreteIterator<Item>(this);  
    }  
    Item& operator[](int index)  
    {  
        return data[index];  
    }  
    int getLen()  
    {  
        return data.size();  
    }  
};  
  
int main()  
{  //�ͻ��˵���ʱ��ȷ��Item�����ͣ���int ����string�ȡ� 
    Aggregate<string> * aggr =new ConcreteAggregate<string>();  
    Iterator<string> *it=aggr->createIterator();  
  
    for(it->first();!it->isDone();it->next())  
    {  
        cout<<*(it->currentItem())<<endl;  
    }  
    delete it;  
    delete aggr; 
    system("pause"); 
    return 0;  
}  

