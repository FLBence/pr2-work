#include <iostream>
#include <iomanip>
#include<string>
#include<fstream>
using namespace std;

struct Jatekos
{
	string nev;
	int szul;
	string poszt;
	int meccs, loves, gol;
};

class Labdarugo
{
	int db;
	Jatekos* tmb;

public:
	Labdarugo(string filename);
	~Labdarugo();
	void kiir();
	int Osszesloves();
	Jatekos Legtobbgol();
	void Fiatalok();
	string Egyforma();
};

int main()
{
	string filename = "jatekosok.txt";
	Labdarugo l(filename);
	l.kiir();
	cout << "Az osszes loves: " << l.Osszesloves() << endl;
	cout << "A legtobb golt lotte: " << l.Legtobbgol().nev << endl;
	l.Fiatalok();
	cout << "Egyenlo golokat rugak: \n";
	for (int i = 0; i < 6; i++)
	{
		cout << l.Egyforma();
	}
}

Labdarugo::Labdarugo(string filename)
{
	ifstream be(filename);
	if (be.fail())
	{
		cout << "Hiba a beolvasasban!";
		exit(1);
	}
	string sor;
	be >> db;
	tmb = new Jatekos[db];
	for (int i = 0; i < db; i++)
	{
		getline(be, tmb[i].nev, ':');
		getline(be, sor, ':');
		tmb[i].szul = stoi(sor);
		getline(be, tmb[i].poszt, ':');
		getline(be, sor, ':');
		tmb[i].meccs = stoi(sor);
		getline(be, sor, ':');
		tmb[i].loves = stoi(sor);
		getline(be, sor);
		tmb[i].gol = stoi(sor);
	}
	be.close();
}

Labdarugo::~Labdarugo()
{
	delete[] tmb;
}
void Labdarugo::kiir()
{
	cout.setf(ios::left);
	cout << setw(12) << "Nev" << setw(6) << "szul." << setw(8) << "Poszt" << setw(6) << "Meccs" << setw(6) << "Loves" << setw(6) << "Gol\n";
	for (int i = 0; i < db; i++)
	{
		cout << setw(12) << tmb[i].nev << setw(6) << tmb[i].szul << setw(8) << tmb[i].poszt << setw(6) << tmb[i].meccs << setw(6) << tmb[i].loves << setw(6) << tmb[i].gol << endl;
	}
}
int Labdarugo::Osszesloves()
{
	int ossz = 0;
	for (int i = 0; i < db; i++)
		ossz += tmb[i].loves;
	return ossz;
}
Jatekos Labdarugo::Legtobbgol()
{
	int max = 0;
	int maxindex = 0;
	for (int i = 0; i < db; i++)
	{
		if (max < tmb[i].gol)
		{
			max = tmb[i].gol;
			maxindex = i;
		}
	}
	return tmb[maxindex];

};

void Labdarugo::Fiatalok()
{
	int start = 1995;
	for (int i = 0; i < db; i++)
	{
		if (tmb[i].szul >= start)
			cout << "Fiatal: " << tmb[i].nev << ", " << tmb[i].szul << endl;
	}
}
string Labdarugo::Egyforma()
{
	const int db = 6;
	string tomb[db];
	for (int i = 0; i < db-1; i++)
		for (int j = 1; j < db; j++)
			if (tmb[i].gol == tmb[j].gol)
				tomb[i] = tmb[i].nev;
	return tmb->nev;
};