#include "szyfrowanie.h"

szyfr::szyfr()
{

}

szyfr::~szyfr()
{

}

string szyfr::cezara(string t_wejsc)
{
	int klucz;
	
	string temp_string;
	
	cout << "Podaj klucz szyfrowania od min. 1 do max. 26\n";
	
	cin >> klucz;
	
	for (int i = 0; i < t_wejsc.size(); i++)
	{
		if (t_wejsc[i] > 96)
		{
			unsigned char temp;
			temp = t_wejsc[i] + klucz;
			if (temp >= 123)
			{
				temp = (temp % 123) + 97;
			}
			temp_string += temp;
		}
		else
		{
			temp_string += t_wejsc[i];
		}
	}
	return temp_string;
}

string szyfr::przestawny(string t_wejsc)
{
	string temp_string;
	char temp1, temp2;
	for (int i = 0; i < t_wejsc.size() - 1; i += 2)
	{
		swap(t_wejsc[i], t_wejsc[i + 1]);
		temp1 = t_wejsc[i];
		temp_string += temp1;
		temp1 = t_wejsc[i + 1];
		temp_string += temp1;
	}
	if (t_wejsc.size() % 2 == 1)
	{
		temp1 = t_wejsc[t_wejsc.size() - 1];
		temp_string += temp1;
	}
	return temp_string;
}

string szyfr::cezaraprzestawny(string t_wejsc)
{
	string t_wyjsc;

	t_wyjsc = cezara((przestawny(t_wejsc)));
	return t_wyjsc;
}

string szyfr::deszyfrowanie(string t_wejsc)
{
	int klucz;
	string temp_string;
	for (int klucz = 0; klucz < 26; klucz++)
	{
		for (int i = 0; i < t_wejsc.size(); i++)
		{
			if (t_wejsc[i] > 96)
			{
				unsigned char temp;
				temp = t_wejsc[i] - klucz;
				if (temp <= 96)
				{
					char x = (t_wejsc[i] % 97) + 123;
					x -= klucz;
					temp = x;
				}
				temp_string += temp;
			}
			else
			{
				temp_string += t_wejsc[i];
			}
		}
		cout << "Tekst wychodzacy: " << temp_string << endl;
		temp_string = "";
	}
	return temp_string;
}

int modInverse(int a, int b)
{
	for (int x = 1; x < b; x++)
		if (((a%b) * (x%b)) % b == 1)
			return x;
}

string szyfr::rsa(string t_wejsc)
{
	int liczb1, liczb2;
	cout << "Podaj pierwsza liczbe\n";
	cin >> liczb1;
	
	cout << "Podaj druga liczbe (inna)\n";
	cin >> liczb2;
	
	int n = liczb1 * liczb2;
	int euler = (liczb1 - 1) * (liczb2 - 1);
	
	cout << "Wybierz liczbe E przedzialu od 1 do " << euler << ". Liczby E i " << euler << " powinny byc wzglednie pierwsze\n";
	
	int e; 
	cin >> e;
	int d; d = modInverse(e, euler);

	pair<int, int> publiczna;
	
	publiczna.first = n;
	publiczna.second = e;
	cout << "Klucz publiczny: " << publiczna.first << "   " << publiczna.second << endl;
	
	pair<int, int> prywatna;
	
	prywatna.first = n;
	prywatna.second = d;
	cout << "Klucz prywatny: " << prywatna.first << "   " << prywatna.second << endl;
	return " ";
}