#include <iostream>
#include <string>
using namespace std;
int szyfr;
string odpowiedz;

string cezara(string odpowiedz)
{
	int podstawienie;
	cout << "O ile przesuwamy liter? (max. 26)" << endl;
	cin >> podstawienie;
	cout << endl;
	for (int i = 0; i < odpowiedz.size(); i++)
	{
		if (odpowiedz[i] < 123 && odpowiedz[i] > 96)
		{
			odpowiedz[i] += podstawienie;
			
			if (odpowiedz[i] > 122)
			{
				odpowiedz[i] = odpowiedz[i] % 123 + 97;
			}
		}
	}
	return odpowiedz;
}

string przestawieniowy(string odpowiedz)
{
	for (int i = 0; i < odpowiedz.size() - 1; i += 2)
	{
		swap(odpowiedz[i], odpowiedz[i + 1]);
	}
	return odpowiedz;
}


int main()
{
	int liczba;
	string szyfr3;
	string odpowiedz;

    cout << "Podaj ciag znakow z malych liter" << endl;
	getline(cin, odpowiedz);
    cout << "Wybierz sposob szyfrowania od 1 do 4: " << endl;
	cout << "1. Szyfr cezara" << endl;
	cout << "2. Szyfr przestawieniowy" << endl;
	cout << "3. Szyfr podstawieniowy i przestawieniowy" << endl;
	cout << "4. Odszyfruj tekst" << endl;
	cin >> szyfr;

	if (szyfr == 1)
	{
		odpowiedz = cezara(odpowiedz);
		cout << "Kod wyglada: " << odpowiedz << endl;
	}
	if (szyfr == 2)
	{
		odpowiedz = przestawieniowy(odpowiedz);
		cout << "Kod wyglada: " << odpowiedz << endl;
	}
	if (szyfr == 3)
	{
		szyfr3 = cezara(odpowiedz);
		szyfr3 = przestawieniowy(szyfr3);
		cout << szyfr3;
	}
	if (szyfr == 4)
	{
		odpowiedz = (odpowiedz);
		cout << "Kod wyglada: " << odpowiedz << endl;
	}
	
}


