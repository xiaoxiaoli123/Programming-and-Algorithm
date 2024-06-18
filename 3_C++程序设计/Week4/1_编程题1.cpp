/*
描述
下面程序的输出是：

3+4i

5+6i

请补足Complex类的成员函数。不能加成员变量。

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
// 在此处补充你的代码
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}

输入
无

输出
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
    // 在此处补充你的代码
    // 赋值运算符的重载
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
        real[realIndex] = '\0'; // 要在每个char数组后面补上0
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
- 注意题目要求只能在可以填写代码的地方修改，所以不能添加头文件（如<string>）
- char*转为double/float要用到atof
- 使用了new后一定要delete
*/