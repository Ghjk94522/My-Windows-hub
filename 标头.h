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

	// ���ز�������ʹ��������ԱȽϴ�С
	bool operator <(const Card &other) const;
	bool operator >(const Card &other) const;
};

class DDZPlayer {
protected:
	string name;  // �����
	int position;  // ���λ�ñ�ţ�0Ϊ������1Ϊ�����¼ң�2Ϊ�����ϼ�
	vector<Card> hand;  // ����

	int prePos;  //��һ�����Ƶ���λ�ñ�ţ�-1��ʾ��û���˳�����
	vector<Card> prePlay;  // ��һ�����Ƶ��˳���ʲô�ƣ�

	bool legal(vector<Card> cards);  // �жϵ�ǰ���cards�Ƿ�Ϸ�
	void substractFromHand(vector<Card> cards);  // �ӵ�ǰ������ɾȥcards�е���
public:
	DDZPlayer(string name);  // ���캯������ʼ�������
	string getName();
	virtual void draw(Card card);  // ��cards�е��Ƽ�������
	virtual void draw(vector<Card> cards);  // ��cards�е��Ƽ�������
	virtual void setPosition(int pos);  // ��ʼ���ã���������������
	virtual void showHand();  // ��ӡ����
	virtual void observed(int pos, vector<Card> cards);  // �۲⵽��ҳ���
	virtual vector<Card> play();  // �ֵ��Լ�ʱ������ʲô��
	bool leftNoCard();  // �����Ƿ�������ƣ�
};


class DDZGame {
private:
	static int my_random(int i);  // ϴ��ʱ�õ����������
	vector<DDZPlayer*> players;  // ����������ҵ�ָ��
	void showCards(vector<Card> cards);  // ���һ����

public:
	DDZGame(DDZPlayer *p1, DDZPlayer *p2, DDZPlayer *p3);  // ���캯��
	void run();  // ִ����Ϸ����
};


class DDZHumanPlayer : public DDZPlayer {
public:
	DDZHumanPlayer(string name) : DDZPlayer(name) {};
	vector<Card> play();
};

