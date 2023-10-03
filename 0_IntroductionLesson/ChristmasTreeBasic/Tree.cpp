#include <iostream>

using namespace std;

int main()
{
	int vyska, kmen_v, kmen_s;
	cout << "Zadejte vysku koruny: ";
	cin >> vyska;
	cout << "Zadeje vysku kmene: ";
	cin >> kmen_v;
	cout << "Zadejte sirku kmene: ";
	cin >> kmen_s;

	for (int i = 1; i <= vyska; i++) {
        for (int m = 0; m < vyska-i; m++)
        {
            cout << " ";
        }
        
        for (int j = 0; j < i; j++)
        {
            if (j==0) cout << "*";
            else cout << "**";
            
        }
        
		cout << endl;
	}

	for (int i = 0; i < kmen_v; i++) {
        for (int i = 0; i < (vyska-(kmen_s+1)/2); i++)
        {
            cout << " ";
        }
        for (int i = 0; i < kmen_s; i++)
        {
            cout << "#";
        }
        cout<<endl;
	}

}