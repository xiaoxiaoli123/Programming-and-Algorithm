/*
描述
在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。

（注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，请同学们严格按照题目要求完成，否则可能会影响作业成绩。）

输入
姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。

其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。

各部分内容之间均用单个英文逗号","隔开，无多余空格。

输出
一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。

各部分内容之间均用单个英文逗号","隔开，无多余空格。

样例输入
Tom,18,7817,80,80,90,70

样例输出
Tom,18,7817,80
*/


#include <iostream>
#include <string>
using namespace std;

const int sizeOfScores = 4;

class Student
{
public:
    void Initialize();
    void PrintInfo();

private:
    string name;
    string id;
    int age;
    unsigned int score1, score2, score3, score4, averageScore;
};

void Student::Initialize()
{
    char comma = ',';
    getline(cin, name, ','); // string只能以这种方式输入逗号
    cin >> age >> comma;
    getline(cin, id, ',');
    cin >> score1 >> comma >> score2 >> comma >> score3 >> comma >> score4;
    averageScore = (score1 + score2 + score3 + score4) / sizeOfScores;
}

void Student::PrintInfo()
{
    cout << name << ',' << age << ',' << id << ',' << averageScore << endl;
}

int main()
{   
    Student st;

    st.Initialize();
    st.PrintInfo();
    return 0;
}

/*
* 感想：
* 这道题原本想得太复杂，花了两个小时写了一堆，思路陷入了怎么把输入值全部赋给Student类的泥沼中，写了getter和setter，
* 还想着怎么把输入的scores以数组的方式赋值到Student成员变量的scores数组中。
* 最后终于跑通了，但是coursera报错complier error，实在不知是什么原因。因为在电脑上的Visual Studio 2022是跑通的。
* 可能是北大在coursera上的在线评分系统太过老旧了。
* 最后参考了GitHub上大佬的代码，发现竟然如此简单，于是自己又重写了一遍。
* 
* 学到的：
* getline按行读入字符串对我来说是新的，并且发现字符串只能这样读入，试过将全部信息都由cin读入，没有成功。
* 分析问题时还是要按照字面意思来，不要想得过于复杂了。
*/
