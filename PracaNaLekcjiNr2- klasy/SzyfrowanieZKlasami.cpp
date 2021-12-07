#include <iostream>
#include <string>
#include "szyfrowanie.h"

int wybor;

string t_wejsc, t_wyjsc;

int main ()
{
	cout << "Wprowadz tekst do szyfracji\n";
	
	getline(cin, t_wejsc);
	
	cout << "wybierz algorytm szyfrujacy: \n";
	
	cout << "1. Szyfr Cezara\n";
	
	cout << "2. Szyfr Przestawieniowy\n";
	
	cout << "3. Szyfr Cezara i Przestawieniowy\n";
	
	cout << "4. Odszyfruj szyfr Cezara\n";
	
	cin >> wybor;
	
	szyfr obiekt;
	
	if (wybor == 1)
	{
		t_wyjsc = obiekt.cezara(t_wejsc);
		cout << "Zaszyfrowany tekst: " << t_wyjsc;
	}
	
	if (wybor == 2)
	{
		t_wyjsc = obiekt.przestawny(t_wejsc);
		cout << "Zaszyfrowany tekst: " << t_wyjsc;
	}
	
	if (wybor == 3)
	{
		t_wyjsc = obiekt.cezaraprzestawny(t_wejsc);
		cout << "Zaszyfrowany tekst: " << t_wyjsc;
	}
	
	if (wybor == 4)
	{
		t_wyjsc = obiekt.deszyfrowanie(t_wejsc);
	}
}