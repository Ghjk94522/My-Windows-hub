#include<vector>
#include<string>
using namespace std;

class Card : public string {
public:
	static const int N_CARD_VALUES;
	static const int N_CARD_SUITS;
	static const string CARD_VALUES[];
	static const string CARD_SUITS[];

	Card(const char* str) :string(str) {};
	Card() :string() {};
	Card(string str) :string(str) {};

	static vector<Card> get_new_deck();

	// 重载操作符，使得牌面可以比较大小
	bool operator <(const Card &other) const;
	bool operator >(const Card &other) const;
};

class DDZPlayer {
protected:
	string name;  // 玩家名
	int position;  // 你的位置编号，0为地主，1为地主下家，2为地主上家
	vector<Card> hand;  // 手牌

	int prePos;  //上一个出牌的人位置编号，-1表示还没有人出过牌
	vector<Card> prePlay;  // 上一个出牌的人出了什么牌？

	bool legal(vector<Card> cards);  // 判断当前打出cards是否合法
	void substractFromHand(vector<Card> cards);  // 从当前手牌中删去cards中的牌
public:
	DDZPlayer(string name);  // 构造函数，初始化玩家名
	string getName();
	virtual void draw(Card card);  // 将cards中的牌加入手牌
	virtual void draw(vector<Card> cards);  // 将cards中的牌加入手牌
	virtual void setPosition(int pos);  // 初始化用，决定地主后设置
	virtual void showHand();  // 打印手牌
	virtual void observed(int pos, vector<Card> cards);  // 观测到玩家出牌
	virtual vector<Card> play();  // 轮到自己时决定出什么牌
	bool leftNoCard();  // 返回是否打完了牌？
};


class DDZGame {
private:
	static int my_random(int i);  // 洗牌时用到的随机函数
	vector<DDZPlayer*> players;  // 保存三个玩家的指针
	void showCards(vector<Card> cards);  // 输出一组牌

public:
	DDZGame(DDZPlayer *p1, DDZPlayer *p2, DDZPlayer *p3);  // 构造函数
	void run();  // 执行游戏流程
};


class DDZHumanPlayer : public DDZPlayer {
public:
	DDZHumanPlayer(string name) : DDZPlayer(name) {};
	vector<Card> play();
};

