/*
����
������������ǣ�

10

�벹��Sample��ĳ�Ա�������������ӳ�Ա������

����
��

���
10
*/

#include <iostream>
using namespace std;

class Sample {
public:
    int v;
    Sample(int n) :v(n) { }
    // �ڴ˴�������Ĵ���
    Sample(Sample& s) 
    {
        v = 10;
    }
};
int main() {
    Sample a(5);
    Sample b = a; // ��Ҫһ���������캯��
    cout << b.v;
    return 0;
}

/*
�����������������ã�
1. ������������ֵ����ʱ
2. ����������һ������ʱ
3. ����һ������ȥ��ʼ����һ������ʱ������������
*/
