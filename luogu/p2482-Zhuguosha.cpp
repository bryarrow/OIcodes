#include <cstdio>
#include <iostream>

using namespace std;

// 牌类
struct Card{
	Card* frount;
	char value;
	Card* next;
};

// 牌堆类
class Cards{
	public:

	int num = 1;
	// 构造函数初始化链表
	Cards(){
		value[0].next = &value[1];
		value[2002].value = '\n';
		value[2002].frount = &value[2001];
		for(int i=1;i<2002;i++){
			value[i].frount = &value[i-1];
			value[i].next = &value[i+1];
		}
	}
	Cards(int m){
		value[0].next = &value[1];
		value[m].value = '\n';
		value[m].frount = &value[m-1];
		for(int i=1;i<m;i++){
			value[i].frount = &value[i-1];
			value[i].next = &value[i+1];
		}
	}

	// 重载[]用来按秩访问
	Card& operator[] (int target){
		Card* t = &value[0];
		for(int i = 0;i!=target;i++){
			t = t->next;
		}
		return *t;
	}

	// 查找牌
	Card& search(char target){
		int i=num-1;
		for(;i>=0;i--){
			if(this->operator[](i).value == target)break;
		}

		return this->value[i];
	}

	// 插入牌
	Cards operator+ (char add){
		this->operator[](num).value = add;
		num++;
		return *this;
	}

	// 移除牌
	Cards operator- (char subtractor){
		search(subtractor);
	}

	// 输出牌堆
	void printf(){
		for(int i=0;i<num;i++){
			std::cout << this->operator[](i).value ;
			if(i < num-1)cout << " ";
		}
	}

	private:
	// 链表内存池
	Card value[2003];
};

// 重载>>用于cin读入牌堆
istream& operator>> (istream &in,Cards& cards){
		char ch;
		in.get(ch);

		while(ch != '\n' && !in.eof()){
			
			if(ch != ' '){
				cards[cards.num-1].value = ch;
				cards.num++;
			}
			
			in.get(ch);
		}

		return in;
}

// 猪的身份
enum ID {MP,FP,ZP,null};

// 猪类
class Pig{
	public:
	Pig(Cards cards,ID nid):mycards(cards),id(nid){be_konwn = null;}
	bool alive(){
		if(heart == 0)return false;else return true;
	}
	
	private:
	Cards mycards;
	ID id;
	ID be_konwn;
	short heart;
};

// 系统类（角色相当于玩游戏时的桌子，记录信息并分发）
class System{
	public:
	int n,m;
	Cards* cardslist;
	Pig* pigslist[11];

	System(){
		cin >> n >> m;
		cardslist = new Cards(m);
	}
	void cleaning(){}
};


int main(){
	
	#ifdef _DEBUG
	freopen("./luogu/p2482.in","r",stdin);
	freopen("./luogu/p2482.out","w",stdout);
	#endif

	
	System sys; // System在初始化时会读入n、m

	// input
	{
		// input pigs
		for(int i=0;i<sys.n;i++){
			char id[3];
			Cards tcards;
			cin >> id;
			cin >> tcards;
			if(id == "MP"){
				sys.pigslist[i] = new Pig(tcards,MP);
			}
			if(id == "ZP"){
				sys.pigslist[i] = new Pig(tcards,ZP);
			}
			if(id == "FP"){
				sys.pigslist[i] = new Pig(tcards,FP);
			}
		}
		// input playcards
		cin >> *sys.cardslist;

		
	}

	sys.cardslist->printf();
	// mainloop
	// while(1){
	// 	if(!sys.pigslist[0]->alive())sys.cleaning();
	// }

	return 0;
}