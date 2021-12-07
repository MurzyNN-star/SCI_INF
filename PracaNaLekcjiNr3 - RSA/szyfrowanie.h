#pragma once
#include <string>
#include <iostream>
using namespace std;

class szyfr

{
public:
	szyfr();
	~szyfr();
	string t_wejsc;
	string cezara(string t_wejsc);
	string przestawny(string t_wejsc);
	string cezaraprzestawny(string t_wejsc);
	string deszyfrowanie(string t_wejsc);
	string rsa(string t_wejsc);
};

