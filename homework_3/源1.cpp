#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

const bool USE_SUITS = false;

const int N_CARD_VALUES = 15;
const string CARD_VALUES[] = {
	"3", "4", "5", "6",
	"7", "8", "9", "10",
	"J", "Q", "K", "A", "2",
	"joker", "JOKER"
};
const int N_CARD_SUITS = 4;
const string CARD_SUITS[] = {
	"Spade", "Heart", "Diamond", "Club"
};

int my_random(int i) {
	return std::rand() % i;
}

vector<string> get_new_deck() {
	vector<string> deck;
	for (int i = 0; i < N_CARD_VALUES - 2; ++i) {
		for (int j = 0; j < N_CARD_SUITS; ++j) {
			string card = CARD_VALUES[i];
			if (USE_SUITS) card = CARD_SUITS[j] + "_" + card;
			deck.push_back(card);
		}
	}
	deck.push_back(CARD_VALUES[13]);
	deck.push_back(CARD_VALUES[14]);
	return deck;
}

char temp[15][6] = { "JOKER","joker","2","A","K","Q","J","10","9","8","7","6","5","4","3" };


int find_max(int a[])
{
	int max = -65535;
	for (int i = 0; i < 15; i++)
		if (a[i] >= max)
			max = a[i];
	return max;
}

int find_subscript(int a[])
{
	int max = -65535; int subs = -1;
	for (int i = 14; i >= 0; i--)
		if (a[i] >= max)
		{
			max = a[i];
			subs = i;
		}
	return subs;
}

//用int数组记录手牌,JOKER - 0
void record_list(int a[], char b[][6], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (0 == strcmp(b[i], "joker"))
			a[1]++;
		else if (0 == strcmp(b[i], "2"))
			a[2]++;
		else if (0 == strcmp(b[i], "A"))
			a[3]++;
		else if (0 == strcmp(b[i], "K"))
			a[4]++;
		else if (0 == strcmp(b[i], "Q"))
			a[5]++;
		else if (0 == strcmp(b[i], "J"))
			a[6]++;
		else if (0 == strcmp(b[i], "10"))
			a[7]++;
		else if (0 == strcmp(b[i], "9"))
			a[8]++;
		else if (0 == strcmp(b[i], "8"))
			a[9]++;
		else if (0 == strcmp(b[i], "7"))
			a[10]++;
		else if (0 == strcmp(b[i], "6"))
			a[11]++;
		else if (0 == strcmp(b[i], "5"))
			a[12]++;
		else if (0 == strcmp(b[i], "4"))
			a[13]++;
		else if (0 == strcmp(b[i], "3"))
			a[14]++;
		else if (0 == strcmp(b[i], "JOKER"))
			a[0]++;
	}
}

//排序后降序输出手牌
void show_list(int a[])
{
	for (int i = 0; i <= 15; i++)
		for (int j = 0; j < a[i]; j++)
			cout << temp[i] << " ";
	cout << endl;
}

void check_boomer(int a[])//判断炸弹和王炸
{
	for (int i = 14; i >= 2; i--)
		if (4 == a[i])
		{
			cout << temp[i] << " " << temp[i] << " " << temp[i] << " " << temp[i];
			a[i] -= 4;
			return;
		}

	if (a[0] == 1 && a[1] == 1)
	{
		cout << "JOKER joker "; 
		a[0]--; a[1]--;
		return;
	}

	//没有处理方案
	cout << "YAO BU QI ";
}

void play_card(int a[], int b[])//a为手牌，b为目标出牌
{
	int count_a = 0; int count_b = 0;//count分别表示两组牌的张数
	{for (int i = 0; i < 15; i++)
		count_a += a[i];
	for (int i = 0; i < 15; i++)
		count_b += b[i]; }//计数

	//这里是找出手牌和目标牌的最大值和下标
	int flag = find_max(b);//判断目标牌型
	int flag_a = find_subscript(a);//手牌最大下标
	int flag_lo = find_subscript(b);//目标最大下标

	switch (flag)
	{
	case 1: {
		if (1 == count_b) {//单张情况
			for (int i = flag_lo - 1; i >= 0; i--)
				if (1 <= a[i])
				{
					cout << temp[i]; 
					a[i]--;
					return;
				}

			check_boomer(a);
		}

		else if (2 == count_b)
			cout << "YAO BU QI"; //这里处理王炸

		else
		{
			//这里处理顺子
			for (int i = flag_lo - 1; i >= count_b + 1; i--)
			{
				int j = i; bool flag_l23 = 1;
				for (int num = 0; num < count_b; num++)
				{
					if (a[j] != 0)
						j--;
					else
					{
						flag_l23 = 0; break;
					}
				}
				if (1 == flag_l23)
				{
					for (int t = j + 1; t <= i; t++)
					{
						cout << temp[t] << " ";
						a[t]--;
					}
					return;
				}
			}

			check_boomer(a);
		}

	}break;//可能是单张，顺子，王炸

	case 2: {
		if (2 == count_b) {//处理对子
			for (int i = flag_lo - 1; i >= 2; i--)
				if (2 <= a[i])
				{
					cout << temp[i] << " " << temp[i]<<" "; 
					a[i] -= 2;
					return;
				}

			check_boomer(a);
		}

		else {//处理连对情况
			for (int i = flag_lo - 1; i >= (count_b / 2 + 1); i--)
			{
				int j = i; bool flag_l23 = 1;
				for (int num = 0; num < count_b / 2; num++)
				{
					if (a[j] >= 2)
						j--;
					else
					{
						flag_l23 = 0; break;
					}
				}
				if (1 == flag_l23)
				{
					for (int t = (j + 1); t <= i; t++)
					{
						cout << temp[t] << " " << temp[t] << " ";
						a[t] -= 2;
					}
					return;
				}
			}

			check_boomer(a);
		}
	}break;//可能是对子，连对

	case 3: {
		if (3 == count_b) {//处理三张单独的情况
			for (int i = flag_lo - 1; i >= 0; i--)
				if (3 <= a[i])
				{
					cout << temp[i] << " " << temp[i] << " " << temp[i]; 
					a[i] -= 3;
					return;
				}

			check_boomer(a);
		}

		else if (4 == count_b) {//三代一
			int tl = flag_lo;//找出目标牌中三张牌的下标
			for (int i = tl - 1; i >= 0; i--)
				if (3 <= a[i])
				{
					int j = 14; bool jljl = 0;
					for (; j >= 0; j--)
						if (a[j] > 0 && j != i)
						{
							jljl = 1; break;
						}
					if (1 == jljl)
					{
						cout << temp[i] << " " << temp[i] << " " << temp[i] << " " << temp[j] << " "; 
						a[i] -= 3; a[j]--;
						return;
					}
				}

			check_boomer(a);
		}

		else if (5 == count_b) {//三代二
			int tl = flag_lo;//找出目标牌中三张牌的下标
			for (int i = tl - 1; i >= 0; i--)
				if (3 <= a[i])
				{
					int j = 14; bool jljl = 0;
					for (; j >= 0; j--)
						if (a[j] > 1 && j != i)
						{
							jljl = 1; break;
						}
					if (1 == jljl)
					{
						cout << temp[i] << " " << temp[i] << " " << temp[i] << " " << temp[j] << " " << temp[j] << " "; 
						a[i] -= 3; a[j] -= 2;
						return;
					}
				}

			check_boomer(a);
		}

		else {//飞机
			int t = 0;//这里计算鸡翅
			for (int i = 2; i <= 14; i++)
				if (3 == b[i])t++;

			int tl = (count_b - 3 * t) / t;//飞机带的几张牌，1 or 2

			for (int i = flag_lo - 1; i >= (t + 1); i--)
			{
				int j = i; bool flag_l23 = 1;
				for (int num = 0; num < t; num++)
				{
					if (a[j] >= 3)
						j--;
					else
					{
						flag_l23 = 0; break;
					}
				}

				if (1 == flag_l23) {
					int *record_plane = new int[t];//利用数组记录目标三张牌型
					for (int i = 0; i < t; i++)
						record_plane[i] = ++j;

					if (1 == tl) {
						int plmm = 0;//做计数器使用，记录带的牌够不够
						int *record_burden = new int[t];//记录所带牌的下标
						int burden = 0;
						for (int i = 14; i >= 0; i--)//判断带牌
						{
							if (a[i] > 0)
							{
								bool sqgg = 1;
								for (int k = 0; k < t; k++)
									if (i == record_plane[k] && record_plane[k] != 4)
										sqgg = 0;
								if (1 == sqgg)
								{
									plmm++; record_burden[burden++] = i;
								}
							}
							if (t == plmm)
								break;
						}

						if (t == plmm)//如果带牌满足数量，则输出
						{
							for (int i = 0; i < t; i++)
							{
								cout << temp[j] << " " << temp[j] << " " << temp[j] << " ";
								a[j] -= 3; j--;
							}
							for (int i = 0; i < t; i++)
							{
								cout << temp[record_burden[--burden]] << " ";
								a[record_burden[burden]]--;
							}
							return;
						}
					}//带一张

					if (2 == tl) {
						int plmm = 0;//做计数器使用，记录带的牌够不够
						int *record_burden = new int[t];//记录所带牌的下标
						int burden = 0;

						for (int i = 14; i >= 0; i--)//判断带牌
						{
							if (a[i] > 1)
							{
								bool sqgg = 1;
								for (int k = 0; k < t; k++)
									if (i == record_plane[k])
										sqgg = 0;
								if (1 == sqgg)
								{
									plmm++; record_burden[burden++] = i;
								}
							}
							if (t == plmm)
								break;
						}

						if (t == plmm)//如果带牌满足数量，则输出
						{
							for (int i = 0; i < t; i++)
							{
								cout << temp[j] << " " << temp[j] << " " << temp[j] << " ";
								a[j] -= 3;
								j--;								
							}
							for (int i = 0; i < t; i++)
							{
								burden--; cout << temp[record_burden[burden]] << " " << temp[record_burden[burden]] << " ";
								a[record_burden[burden]] -= 2;
							}
							return;
						}
					}

					if (0 == tl) {//飞机不带翅膀
						for (int i = 0; i < t; i++)
						{
							cout << temp[j] << " " << temp[j] << " " << temp[j] << " "; 
							a[j] -= 3;
							j--;
						}
					}
				}

				check_boomer(a);
			}
		}
	}break;//可能是三张，可能是三代一，三代二，飞机

	case 4: {
		if (6 == count_b) {//四代二
			int tl = flag_lo;//找出目标牌中四张牌的下标
			for (int i = tl - 1; i >= 0; i--)
				if (4 == a[i])
				{
					int j = 14; int plmm = 0; int abc[2]; int abcs = 0;
					for (; j >= 0; j--)
					{
						if (a[j] > 0 && j != i)
						{
							plmm++; abc[abcs++] = j; break;
						}
						if (2 == plmm)break;
					}
					if (2 == plmm)
					{
						cout << temp[i] << " " << temp[i] << " " << temp[i] << " " << temp[i] << " ";
						cout << temp[abc[0]] << " " << temp[abc[1]] << " ";
						a[i] -= 4; a[abc[0]]--; a[abc[1]]--;
						return;
					}
				}

			check_boomer(a);
		}

		if (8 == count_b) {//四代两对
			int tl = flag_lo;//找出目标牌中四张牌的下标
			for (int i = tl - 1; i >= 2; i--)
				if (4 == a[i])
				{
					int j = 14; int plmm = 0; int abc[2]; int abcs = 0;
					for (; j >= 0; j--)
					{
						if (a[j] > 1 && j != i)
						{
							plmm++; abc[abcs++] = j; break;
						}
						if (2 == plmm)break;
					}
					if (2 == plmm)
					{
						cout << temp[i] << " " << temp[i] << " " << temp[i] << " " << temp[i] << " ";
						cout << temp[abc[0]] << " " << temp[abc[0]] << " " << temp[abc[1]] << " " << temp[abc[1]] << " ";
						a[i] -= 4; a[abc[0]] -= 2; a[abc[1]] -= 2;
						return;
					}
				}


			check_boomer(a);
		}

		else {//炸弹
			for (int i = flag_lo - 1; i >= 2; i--)
			{
				if (4 == a[i])
				{
					cout << temp[i] << " " << temp[i] << " " << temp[i] << " " << temp[i] << " ";
					a[i] -= 4;
					return;
				}
			}

			if (1 == a[0] && 1 == a[1])
			{
				cout << "JOKER joker ";
				a[0]--; a[1]--;
			}
			else
				cout << "YAO BU QI ";
		}
	}break;//可能是炸弹，四代二，四带两对
	}
}

int check_ending(int a[], int b[], int c[])
{
	for (int i = 0; i < 20; i++)
		if (a[i] != 0)
			return 0;
	for (int i = 0; i < 17; i++)
		if (b[i] != 0)
			return 0;
	for (int i = 0; i < 17; i++)
		if (c[i] != 0)
			return 0;
	return 1;
}

void play_first(int a[])
{
	for (int i = 14; i >= 0; i--)
		if (2 == a[i])
		{
			cout << temp[i] << " " << temp[i] << " " << endl; return;
		}
	for(int i = 14;i >= 0;i--)
		if (3 == a[i])
		{
			cout << temp[i] << " " << temp[i] << " " << temp[i] << " " << endl; return;
		}
	for(int i = 14;i >= 0;i--)
		if (1 == a[i])
		{
			cout << temp[i] << " " << endl; return;
		}
	for (int i = 14; i >= 0; i--)
		if (4 == a[i])
		{
			cout << temp[i] << " " << temp[i] << " " << temp[i] << " " << temp[i] << " " << endl; return;
		}
}

int main(int argc, char* argv[]) {
	unsigned int random_seed;
	cin >> random_seed;
	srand(random_seed);

	freopen("data_out.txt", "a+", stdout);
	freopen("data_in.txt", "r", stdin);

	vector<string> deck = get_new_deck();
	random_shuffle(deck.begin(), deck.end(), my_random);

	char p[21][6] = { '\0' };
	char q[21][6] = { '\0' };
	char r[21][6] = { '\0' };

	for (int i = 0; i < deck.size(); ++i) {
		cout << deck[i] << ((i == 19 || i == 36 || i == 53) ? "\n" : " ");
	}
	
	for (int i = 0; i < 20; i++)
		cin >> p[i];
	for (int i = 0; i < 17; i++)
		cin >> q[i];
	for (int i = 0; i < 17; i++)
		cin >> r[i];

	int rich[15] = { '\0' };
	int poorl[15] = { '\0' };
	int poor2[15] = { '\0' };

	record_list(rich, p, 20);
	record_list(poorl, q, 17);
	record_list(poor2, r, 17);

	int check_time = 0; char rubbish[100] = { '\0' };
	while (0 == check_ending(rich, poorl, poor2))
	{
		if (0 == check_time)
		{
			cout << "游戏开始，三位玩家初始手牌分别为：\n";
			cout << "landlord: "; show_list(rich);
			cout << "poor man 1: "; show_list(poorl);
			cout << "poor man 2: "; show_list(poor2);
			cout << endl;
			cout << "The rich man : ";
			for (int i = 0; i < 11; i++)
				cin >> rubbish[i];
			play_first(rich); check_time = 1;
		}

		char temp_in[20][6] = { '\0' };//利用字符数组记录出牌
		int temp_in_l[15] = { '\0' };

		for (int i = 0; i < 20; i++)
			cin >> temp_in[i];
		record_list(temp_in_l, temp_in, 20);

		cout << "The poor manl : ";
		for (int i = 0; i < 12; i++)
			cin >> rubbish[i];
		play_card(poorl, temp_in_l);

		char temp_in[20][6] = { '\0' };//重置字符数组记录出牌
		int temp_in_l[15] = { '\0' };

		for (int i = 0; i < 20; i++)
			cin >> temp_in[i];
		record_list(temp_in_l, temp_in, 20);

		cout << "The poor man2 : ";
		for (int i = 0; i < 12; i++)
			cin >> rubbish[i];
		play_card(poor2, temp_in_l);



	}

	return 0;
}