#include <cstdio>
#include <iostream>

using namespace std;

enum ID {MP,FP,ZP,null};

struct Cards{

	char plarcards[2003] = "\n";
	int num = 1;

	Cards operator+ (char add){
		plarcards[num] = add;
		num ++;
		return *this;
	}

	void printf(){
		for(int i=num;i>0;i--){
			std::cout << plarcards[i-1] ;
			if(i > 2)cout << " ";
		}
	}

};

istream& operator>> (istream &in,Cards& cards){
		char ch;
		in.get(ch);

		while(ch != '\n' && !in.eof()){
			
			if(ch != ' '){
				cards.plarcards[cards.num] = ch;
				cards.num++;
			}
			
			in.get(ch);
		}

		return in;
}

class Pig{
	public:
	Pig(Cards cards,ID nid):mycards(cards),id(nid){be_konwn = null;}
	private:
	Cards mycards;
	ID id;
	ID be_konwn;
	short heart;
};

int main(){
	
	#ifdef _DEBUG
	freopen("./luogu/p2482.in","r",stdin);
	freopen("./luogu/p2482.out","w",stdout);
	#endif

	Cards cards;
	/*input*/{
		int n,m;
		cin>>n>>m;
		// input pigs
		for(int i=0;i<n;i++){
			char id[3];
			Cards tcards;
			cin >> id;
			cin >> tcards;
			if(id == "MP"){

			}
			if(id == "ZP"){

			}
			if(id == "FP"){

			}
		}
		// input playcards
		// for(int i=0;i<m;i++){
			// char card;
			// cin >> card;
			// cards = cards + card;
			cin >> cards;
		// }

		cards.printf();
	}
	return 0;
}