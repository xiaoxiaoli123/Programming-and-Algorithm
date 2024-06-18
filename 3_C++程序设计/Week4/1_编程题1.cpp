/*
����
������������ǣ�

3+4i

5+6i

�벹��Complex��ĳ�Ա���������ܼӳ�Ա������

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// �ڴ˴�������Ĵ���
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}

����
��

���
3+4i

5+6i
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Complex {
private:
    double r, i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    // �ڴ˴�������Ĵ���
    // ��ֵ�����������
    Complex& operator=(const char* s)
    {
        int length = strlen(s);
        char* real = new char[length];
        char* imaginary = new char[length];
        int realIndex = 0;
        int imaginaryIndex = 0;
        bool isReal = true;
        for (int i = 0; i < length; i++)
        {
            if ('+' == s[i])
            {
                isReal = false;
            }

            if (isReal)
            {
                real[realIndex++] = s[i];
            }
            else
            {
                imaginary[imaginaryIndex++] = s[i];
            }
        }
        real[realIndex] = '\0'; // Ҫ��ÿ��char������油��0
        imaginary[imaginaryIndex] = '\0';
        r = atof(real);
        i = atof(imaginary);
        delete[] real;
        delete[] imaginary;
        return *this;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}

/*
- ע����ĿҪ��ֻ���ڿ�����д����ĵط��޸ģ����Բ������ͷ�ļ�����<string>��
- char*תΪdouble/floatҪ�õ�atof
- ʹ����new��һ��Ҫdelete
*/