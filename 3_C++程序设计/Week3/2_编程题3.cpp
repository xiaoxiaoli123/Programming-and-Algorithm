/*
����
���������������ǣ�

5,5

5,5

����գ�

����
��

���
5,5

5,5
*/
#include <iostream>
using namespace std;

class Base {
public:
    int k;
    Base(int n) :k(n) { }
};

// �����
class Big { 
public:
    int v; Base b;
    // �ڴ˴�������Ĵ���
    // �����Ĺ��캯��
    Big(int n) :v(n),b(n){}
};

int main() {
    Big a1(5); Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}

/*
����ࣺ������Ա����һ����ĳ�Ա��������һ����Ķ��󣩵��ࡣ
��������Ĺ��캯��ʱ, ��ӳ�ʼ���б�:
���캯��(������):��Ա����1(������), ��Ա����2(������), �� {}
*/
