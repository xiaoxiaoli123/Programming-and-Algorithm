/*
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。

每组测试数据共两行。

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入：
1
20
3 4 5 6 7

样例输出：
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int typeOfWorrior = 5;

class RedHQ
{
public:
	RedHQ(int lifeElement):
		m_index(0),
		m_totalCount(0),
		m_lifeElement(lifeElement),
		m_typeCount{ 0 }, 
		m_worriors{ "iceman", "lion", "wolf", "ninja", "dragon" },
		m_inputOrder{2,3,4,1,0}, // 在输入strength时武士的顺序和red中生成的武士顺序形成映射
		m_canProduce(true)
	{}
	bool produce(int arr[], int size);

private:
	int m_index; // wirriors数组的索引
	int m_totalCount; // 全部武士计数
	int m_lifeElement;
	int m_typeCount[typeOfWorrior]; // 一类的武士计数,对应worriors，所以也是一个数组
	string m_worriors[typeOfWorrior];
	int m_inputOrder[typeOfWorrior];
	bool m_canProduce;
};

bool RedHQ::produce(int arr[], int size)
{
	if (!m_canProduce)
	{
		return false;
	}

	for (int i = 0; i < typeOfWorrior; i++)
	{
		int type = m_index % typeOfWorrior; // 0~4
		int strength = arr[m_inputOrder[type]]; // 获得对应的strength

		if (m_lifeElement >= strength) // 有足够多的生命元制造武士
		{
			m_canProduce = true;
			m_lifeElement -= strength;
			m_totalCount++; // 武士总数增加
			m_typeCount[type]++; // 更新特定武士的索引 
			// 打印武士信息
			cout << setw(3) << setfill('0') << m_totalCount - 1 << " " << "red" << " " << m_worriors[type] << " " << m_totalCount << " " << "born with strength" << " " << strength
				<< "," << m_typeCount[type] << " " << m_worriors[type] <<" " << "in red headquarter" << endl;
			m_index++; // 制造成功，尝试制造下一个武士类型
			return true;
		}
		m_index++; // 制造失败，尝试制造下一个武士类型	
	}

	// 循环结束，一个类型都没有制造成功
	cout << setw(3) << setfill('0') << m_totalCount << " " << "red headquarter stops making warriors" << endl;
	m_canProduce = false;
	return false;
}

class BlueHQ
{
public:
	BlueHQ(int lifeElement) :
		m_index(0),
		m_totalCount(0),
		m_lifeElement(lifeElement),
		m_typeCount{ 0 },
		m_worriors{ "lion","dragon","ninja","iceman","wolf" },
		m_inputOrder{ 3, 0, 1, 2, 4 },
		m_canProduce(true)
	{}
	bool produce(int arr[], int size);

private:
	int m_index; // wirriors数组的索引
	int m_totalCount; // 全部武士计数
	int m_lifeElement;
	int m_typeCount[typeOfWorrior]; // 一类的武士计数,对应worriors，所以也是一个数组
	string m_worriors[typeOfWorrior];
	int m_inputOrder[typeOfWorrior];
	bool m_canProduce;
};

bool BlueHQ::produce(int arr[], int size)
{
	if (!m_canProduce)
	{
		return false;
	}

	for (int i = 0; i < typeOfWorrior; i++)
	{
		int type = m_index % typeOfWorrior; // 0~4
		int strength = arr[m_inputOrder[type]]; // 获得对应的strength
		if (m_lifeElement >= strength) // 有足够多的生命元制造武士
		{
			m_lifeElement -= strength;
			m_totalCount++; // 武士总数增加
			m_typeCount[type]++; // 更新特定武士的索引 
			// 打印武士信息
			cout << setw(3) << setfill('0') << m_totalCount - 1 << " " << "blue" << " " << m_worriors[type] << " " << m_totalCount << " " << "born with strength" << " " << strength
				<< "," << m_typeCount[type] << " " << m_worriors[type] << " " << "in blue headquarter" << endl;
			m_index++; // 制造成功，尝试制造下一个武士类型
			return true;
		}
		m_index++; // 制造失败，尝试制造下一个武士类型
	}

	// 循环结束，一个类型都没有制造成功
	cout << setw(3) << setfill('0') << m_totalCount << " " << "blue headquarter stops making warriors" << endl;
	m_canProduce = false;
	return false;
}

int main(void)
{
	int testCount = 0; // 测试案例数量
	int testIndex = 1; // 测试案例从1开始计数
	cin >> testCount;
	
	while (testCount > 0)
	{
		// 输入任意组生命元点数
		int lifeElement = 0;
		int caseIndex;
		int dragonHP, ninjaHP, icemanHP, lionHP, wolfHP;

		cin >> lifeElement;
		cin >> dragonHP >> ninjaHP >> icemanHP >> lionHP >> wolfHP;
		// 获得的数存在一个数组中
		int strengths[typeOfWorrior] = { dragonHP, ninjaHP, icemanHP, lionHP, wolfHP };

		RedHQ red(lifeElement);
		BlueHQ blue(lifeElement);
		cout << "Case:" << testIndex << endl;

		bool redCanPrint = true;
		bool blueCanPrint = true;
		while (redCanPrint || blueCanPrint)
		{
			if (redCanPrint)
			{
				redCanPrint = red.produce(strengths, typeOfWorrior);
			}
			if (blueCanPrint)
			{
				blueCanPrint = blue.produce(strengths, typeOfWorrior);
			}
		}

		testCount--;
		testIndex++;

		if (testIndex > 24)
			break;
	}
	return 0;
}

/*
1) 没有使用继承和多态，所以有很多重复代码，后续可改进
2） red和blue逐行打印想了很久，问了AI才知道可以用这样的方式来解决。flag的应用真广泛。
*/

