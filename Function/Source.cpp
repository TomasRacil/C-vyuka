/*
Ukázka použití funkcí
*/

#include <iostream>
#include <string>

using namespace std;

char posun(char posouvanyZnak, int posun) {
	int posouvanyZnakInt = int(posouvanyZnak);
	if (65 <= posouvanyZnakInt && posouvanyZnakInt <=90) {
		if (posouvanyZnakInt + posun > 90) {
			return char(posouvanyZnakInt + posun - 26);
		}
		else {
			return char(posouvanyZnakInt + posun);
		}
	}
	else if (97 <= posouvanyZnakInt && posouvanyZnakInt <= 122) {
		if (posouvanyZnakInt + posun > 122) {
			return char(posouvanyZnakInt + posun - 26);
		}
		else {
			return char(posouvanyZnakInt + posun);
		}
	}
	else if(posouvanyZnakInt==32){
		return char(posouvanyZnakInt);
	}
}

void main() {
	string sifrovanaVeta;
	getline(cin, sifrovanaVeta);
	int pos;
	cin >> pos;
	for (int i = 0; i <= sifrovanaVeta.size(); i++) {
		cout << posun(sifrovanaVeta[i], pos)<<"\n";
	}

}