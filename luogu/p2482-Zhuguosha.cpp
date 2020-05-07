#include <cstdio>
#include <iostream>

using namespace std;

enum ID {MP,FP,ZP};

struct Cards{

	char plarcards[2003] = "\n";
	int num = 1;

	Cards operator+ (char add){
		plarcards[num] = add;
		num ++;
		return *this;
	}

	void printf(){
		for(int i=num;i>=0;i--){
			std::printf("%s",plarcards[i-1]);
		}
	}

};

istream& operator>> (istream &in,Cards& cards){
		char ch;
		in >> ch;

		while(ch != '\n'){
			cards.plarcards[cards.num] = ch;
			cards.num++;
			in >> ch;
		}

		return in;
}

class Pig{
	public:
	Pig(Cards cards,ID nid):mycards(cards),id(nid){};
	private:
	Cards mycards;
	ID id;
	ID be_konwn;
	short heart;
};

int main(){
	
	// #ifdef _DEBUG
	// freopen("./p2482.in","r",stdin);
	// freopen("./p2482.out","w",stdout);
	// #endif

	Cards cards;
	/*input*/{
		int n,m;
		cin>>n>>m;
		// input pigs
		// for(int i=0;i<n;i++){
		// 	char id[3];
		// 	cin >> id;
			
		// }
		// input playcards
		// for(int i=0;i<m;i++){
			// char card;
			// cin >> card;
			// cards = cards + card;
			cin >> cards;
		// }
	}
	return 0;
}