/*
描述
下面程序的输出结果是：

5,5

5,5

请填空：

输入
无

输出
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

// 封闭类
class Big { 
public:
    int v; Base b;
    // 在此处补充你的代码
    // 封闭类的构造函数
    Big(int n) :v(n),b(n){}
};

int main() {
    Big a1(5); Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}

/*
封闭类：包含成员对象（一个类的成员变量是另一个类的对象）的类。
定义封闭类的构造函数时, 添加初始化列表:
构造函数(参数表):成员变量1(参数表), 成员变量2(参数表), … {}
*/
