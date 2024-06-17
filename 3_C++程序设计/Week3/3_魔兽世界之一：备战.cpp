/*
����
ħ������������Ǻ�ħ����˾�����������ħ����˾�������˾�֮�����������е����ɳ��С�

��˾���City 1��City 2��������City n����˾�

������˾�����������ʿ����ʿһ���� dragon ��ninja��iceman��lion��wolf ���֡�ÿ����ʿ���б�š�����ֵ�����������������ԡ�

˫������ʿ��Ŷ��Ǵ�1��ʼ���㡣�췽��������ĵ�n����ʿ����ž���n��ͬ����������������ĵ�n����ʿ�����Ҳ��n��

��ʿ�ڸս�����ʱ����һ������ֵ��

��ÿ�����㣬˫����˾��и���һ����ʿ������

�췽˾�����iceman��lion��wolf��ninja��dragon��˳��ѭ��������ʿ��

����˾�����lion��dragon��ninja��iceman��wolf��˳��ѭ��������ʿ��

������ʿ��Ҫ����Ԫ��

����һ����ʼ����ֵΪm����ʿ��˾��е�����Ԫ��Ҫ����m����

���˾��е�����Ԫ����������ĳ����˳��Ӧ���������ʿ����ô˾�����ͼ������һ�������������ʿ�����������ˣ���˾�ֹͣ������ʿ��

����һ��ʱ�䣬��˫��˾��ĳ�ʼ����Ԫ��Ŀ��Ҫ���㽫��0��0�ֿ�ʼ��˫��˾�ֹͣ������ʿΪֹ�������¼���˳�������

һ���������¼������Ӧ������������£�

1) ��ʿ����

��������� 004 blue lion 5 born with strength 5,2 lion in red headquarter

��ʾ��4���������Ϊ5����ħlion��ʿ������������ʱ����ֵΪ5����������ħ˾��ﹲ��2��lion��ʿ����Ϊ������������ǵ��ʵĸ�����ʽ��ע�⣬ÿ�����һ���µ���ʿ����Ҫ�����ʱ˾��ﹲ�ж��ٸ�������ʿ��

2) ˾�ֹͣ������ʿ

��������� 010 red headquarter stops making warriors

��ʾ��10�������췽˾�ֹͣ������ʿ

����¼�ʱ��

���Ȱ�ʱ��˳�������

ͬһʱ�䷢�����¼����������˾��ģ��������˾��ġ�

����
��һ����һ�������������������������

ÿ��������ݹ����С�

��һ�У�һ������M���京��Ϊ�� ÿ��˾�һ��ʼ����M������Ԫ( 1 <= M <= 10000)��

�ڶ��У���������������� dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ�����Ƕ�����0С�ڵ���10000��

���
��ÿ��������ݣ�Ҫ�������0ʱ0�ֿ�ʼ����˫��˾���ֹͣ������ʿΪֹ�������¼���

��ÿ��������ݣ��������"Case:n" n�ǲ������ݵı�ţ���1��ʼ ��

��������ǡ����˳��͸�ʽ��������¼���ÿ���¼������¼�������ʱ�俪ͷ��ʱ����СʱΪ��λ������λ��

�������룺
1
20
3 4 5 6 7

���������
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
		m_inputOrder{2,3,4,1,0}, // ������strengthʱ��ʿ��˳���red�����ɵ���ʿ˳���γ�ӳ��
		m_canProduce(true)
	{}
	bool produce(int arr[], int size);

private:
	int m_index; // wirriors���������
	int m_totalCount; // ȫ����ʿ����
	int m_lifeElement;
	int m_typeCount[typeOfWorrior]; // һ�����ʿ����,��Ӧworriors������Ҳ��һ������
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
		int strength = arr[m_inputOrder[type]]; // ��ö�Ӧ��strength

		if (m_lifeElement >= strength) // ���㹻�������Ԫ������ʿ
		{
			m_canProduce = true;
			m_lifeElement -= strength;
			m_totalCount++; // ��ʿ��������
			m_typeCount[type]++; // �����ض���ʿ������ 
			// ��ӡ��ʿ��Ϣ
			cout << setw(3) << setfill('0') << m_totalCount - 1 << " " << "red" << " " << m_worriors[type] << " " << m_totalCount << " " << "born with strength" << " " << strength
				<< "," << m_typeCount[type] << " " << m_worriors[type] <<" " << "in red headquarter" << endl;
			m_index++; // ����ɹ�������������һ����ʿ����
			return true;
		}
		m_index++; // ����ʧ�ܣ�����������һ����ʿ����	
	}

	// ѭ��������һ�����Ͷ�û������ɹ�
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
	int m_index; // wirriors���������
	int m_totalCount; // ȫ����ʿ����
	int m_lifeElement;
	int m_typeCount[typeOfWorrior]; // һ�����ʿ����,��Ӧworriors������Ҳ��һ������
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
		int strength = arr[m_inputOrder[type]]; // ��ö�Ӧ��strength
		if (m_lifeElement >= strength) // ���㹻�������Ԫ������ʿ
		{
			m_lifeElement -= strength;
			m_totalCount++; // ��ʿ��������
			m_typeCount[type]++; // �����ض���ʿ������ 
			// ��ӡ��ʿ��Ϣ
			cout << setw(3) << setfill('0') << m_totalCount - 1 << " " << "blue" << " " << m_worriors[type] << " " << m_totalCount << " " << "born with strength" << " " << strength
				<< "," << m_typeCount[type] << " " << m_worriors[type] << " " << "in blue headquarter" << endl;
			m_index++; // ����ɹ�������������һ����ʿ����
			return true;
		}
		m_index++; // ����ʧ�ܣ�����������һ����ʿ����
	}

	// ѭ��������һ�����Ͷ�û������ɹ�
	cout << setw(3) << setfill('0') << m_totalCount << " " << "blue headquarter stops making warriors" << endl;
	m_canProduce = false;
	return false;
}

int main(void)
{
	int testCount = 0; // ���԰�������
	int testIndex = 1; // ���԰�����1��ʼ����
	cin >> testCount;
	
	while (testCount > 0)
	{
		// ��������������Ԫ����
		int lifeElement = 0;
		int caseIndex;
		int dragonHP, ninjaHP, icemanHP, lionHP, wolfHP;

		cin >> lifeElement;
		cin >> dragonHP >> ninjaHP >> icemanHP >> lionHP >> wolfHP;
		// ��õ�������һ��������
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
1) û��ʹ�ü̳кͶ�̬�������кܶ��ظ����룬�����ɸĽ�
2�� red��blue���д�ӡ���˺ܾã�����AI��֪�������������ķ�ʽ�������flag��Ӧ����㷺��
*/

