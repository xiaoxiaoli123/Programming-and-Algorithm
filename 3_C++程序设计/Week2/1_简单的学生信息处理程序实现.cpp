/*
����
��һ��ѧ����Ϣ��������У�Ҫ��ʵ��һ������ѧ�����࣬�������г�Ա������Ӧ����˽�еġ�

��ע������ϵͳ�޷��Զ��жϱ����Ƿ�˽�С����ǻ��ڽ���֮��ͳһ����ҵ���м�飬��ͬѧ���ϸ�����ĿҪ����ɣ�������ܻ�Ӱ����ҵ�ɼ�����

����
���������䣬ѧ�ţ���һѧ��ƽ���ɼ����ڶ�ѧ��ƽ���ɼ�������ѧ��ƽ���ɼ�������ѧ��ƽ���ɼ���

����������ѧ��Ϊ�ַ����������ո�Ͷ��ţ�����Ϊ���������ɼ�Ϊ�Ǹ�������

����������֮����õ���Ӣ�Ķ���","�������޶���ո�

���
һ�У���˳����������������䣬ѧ�ţ�����ƽ���ɼ�������ȡ������

����������֮����õ���Ӣ�Ķ���","�������޶���ո�

��������
Tom,18,7817,80,80,90,70

�������
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
    getline(cin, name, ','); // stringֻ�������ַ�ʽ���붺��
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
* ���룺
* �����ԭ�����̫���ӣ���������Сʱд��һ�ѣ�˼·��������ô������ֵȫ������Student��������У�д��getter��setter��
* ��������ô�������scores������ķ�ʽ��ֵ��Student��Ա������scores�����С�
* ���������ͨ�ˣ�����coursera����complier error��ʵ�ڲ�֪��ʲôԭ����Ϊ�ڵ����ϵ�Visual Studio 2022����ͨ�ġ�
* �����Ǳ�����coursera�ϵ���������ϵͳ̫���Ͼ��ˡ�
* ���ο���GitHub�ϴ��еĴ��룬���־�Ȼ��˼򵥣������Լ�����д��һ�顣
* 
* ѧ���ģ�
* getline���ж����ַ���������˵���µģ����ҷ����ַ���ֻ���������룬�Թ���ȫ����Ϣ����cin���룬û�гɹ���
* ��������ʱ����Ҫ����������˼������Ҫ��ù��ڸ����ˡ�
*/
