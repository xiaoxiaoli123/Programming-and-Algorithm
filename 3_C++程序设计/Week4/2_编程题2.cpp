/*
����
�����MyInt��ֻ��һ����Ա������MyInt���ڲ��Ĳ��ִ��뱻�����ˡ���������ĳ����ܱ���ͨ��������������:

4,1

��д�������صĲ��֡�����д�����ݱ�������ȫ���Ž� MyInt���ڲ��ģ�MyInt�ĳ�Ա�����ﲻ����ʹ�þ�̬��������

#include <iostream>
using namespace std;
class MyInt {
    int nVal;
    public:
        MyInt(int n) { nVal = n; }
        int ReturnVal() { return nVal; }
// �ڴ˴�������Ĵ���
};
int main () {
    MyInt objInt(10);
    objInt-2-1-3;
    cout << objInt.ReturnVal();
    cout <<",";
    objInt-2-1;
    cout << objInt.ReturnVal();
    return 0;
}

����
��

���
4,1
*/

#include <iostream>
using namespace std;

class MyInt {
    int nVal;
public:
    MyInt(int n) { nVal = n; }
    int ReturnVal() { return nVal; }
    // �ڴ˴�������Ĵ���
    // -�ŵ�����
    MyInt& operator-(int n)
    {
        nVal -= n;
        return *this;
    }
};
int main() {
    MyInt objInt(10);
    objInt - 2 - 1 - 3;
    cout << objInt.ReturnVal();
    cout << ",";
    objInt - 2 - 1;
    cout << objInt.ReturnVal();
    return 0;
}