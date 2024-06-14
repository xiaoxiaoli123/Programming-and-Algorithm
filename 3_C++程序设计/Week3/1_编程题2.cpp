/*
描述
下面程序的输出是：

10

请补足Sample类的成员函数。不能增加成员变量。

输入
无

输出
10
*/

#include <iostream>
using namespace std;

class Sample {
public:
    int v;
    Sample(int n) :v(n) { }
    // 在此处补充你的代码
    Sample(Sample& s) 
    {
        v = 10;
    }
};
int main() {
    Sample a(5);
    Sample b = a; // 需要一个拷贝构造函数
    cout << b.v;
    return 0;
}

/*
拷贝函数的三个作用：
1. 当函数参数按值传递时
2. 当函数返回一个对象时
3. 当用一个对象去初始化另一个对象时（本题的情况）
*/
