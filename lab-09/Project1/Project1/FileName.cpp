#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

struct Filmlista
{
	string Nev;
	int Evad, Epizod, Perc, Ar;
};

class Filmek
{
	int db;
	Filmlista* tmb;

public: 
	Filmek(string file_name);
	int Getadatdb();
	int Osszesreszszama();
	Filmlista Legdragabb();
	void Kiir();
	~Filmek();
};

int main()
{
	string file_name = "Filmsorozatok.txt";
	Filmek F(file_name);
	F.Kiir();
	cout << "Sorozatok szama: " << F.Getadatdb() <<endl;
	cout << "Reszek szama: " << F.Osszesreszszama() <<endl;
	Filmlista most_expensive = F.Legdragabb();
	cout << "Legdargabb film: " << most_expensive.Nev << " " << most_expensive.Ar << endl;
	return 0;
}

Filmek::Filmek(string file_name)
{
	db = 0;
	string row;
	ifstream be(file_name);
	if (be.fail())
	{
		cout << "Hiba a beolvasosban!";
		exit(1);
	}
	while (!be.eof())
	{
		getline(be, row);
		db++;
	}
	be.seekg(0, ios::beg);
	
	int i = 0;
	tmb = new Filmlista[db];
	while (!be.eof())
	{
		getline(be, tmb[i].Nev, ';');
		getline(be, row, ';');
		tmb[i].Evad = stoi(row);
		getline(be, row, ';');
		tmb[i].Epizod = stoi(row);
		getline(be, row, ';');
		tmb[i].Perc = stoi(row);
		getline(be, row);
		tmb[i].Ar = stoi(row);
		i++;
	}
	be.close();
}
Filmek::~Filmek()
{
	delete[] tmb;
}
int Filmek::Getadatdb() {
	return db;
}
int Filmek::Osszesreszszama()
{
	int all = 0;
	for (int i = 0; i < db; i++)
		all += tmb[i].Evad * tmb[i].Epizod;
	return all;
}

Filmlista Filmek::Legdragabb()
{
	int most_expensive = 0;
	for (int i = 1; i < db; i++)
	{
		if (tmb[most_expensive].Ar < tmb[i].Ar)
			most_expensive = i;
	}
	return tmb[most_expensive];
}

void Filmek::Kiir()
{
	cout << setw(16) << "Sorozat" << setw(8) << "Evad" << setw(10) << "Epizodok" << setw(8) << "Hossz" << setw(10) << "Ar\n";
	for (int i = 0; i < db; i++)
	{
		cout << setw(16) << tmb[i].Nev << setw(8) << tmb[i].Evad << setw(10) << tmb[i].Epizod << setw(8) << tmb[i].Perc << setw(10) << tmb[i].Ar << endl;
	}
}










