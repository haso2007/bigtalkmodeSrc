#include <vector>
using namespace std;
void main(void)
{vector<int>array;
array.push_back(1);
array.push_back(2);
array.push_back(3);
array.push_back(4);
array.push_back(5);
vector<int>::iterator itr = array.begin();
while (itr != array.end)
{if (*itr == 3)array.erase(itr);//ɾ��ֵΪ3��Ԫ��++itr;
}
}//�������һ������array.pop_back()
