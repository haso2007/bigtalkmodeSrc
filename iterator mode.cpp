#include <iostream>   
#include <string>
#include <vector>   
using namespace std;  
//这是模版， 这样写了之后，加入你声明一个 T  a ；以后为 a赋值 整型，则T为int 
//UML中用bind绑定表示  
//如果 你赋值为 double类型的数，此时 T就为double 。
//抽象类层次与集合无任何关系，好外是它可供其它集合使用  
template<class Item>  
class Iterator  
{  
public:  
    virtual void first()=0;  //不管那个集合都需要这些方法，这就是抽象 
    virtual void next()=0;  //出来的抽象类的意义 
    virtual Item* currentItem()=0;  
    virtual bool isDone()=0;  
    virtual ~Iterator(){}  
};  
  
template<class Item>  
class ConcreteAggregate;  
  
template<class Item>  
class ConcreteIterator : public Iterator <Item>  //具体的迭代算法与集合有关，有适用关系。
{  
    ConcreteAggregate<Item> * aggr;  //不在抽象类引用，而在这里才引用的好处。
    int cur;                  //具体迭代算法的实现在子类中具体做，国为算法 可能相差很远。
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
        data.push_back("小王");  
        data.push_back("小明");  
        data.push_back("大头");  
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
{  //客户端凋用时才确定Item的类型，如int 或者string等。 
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

