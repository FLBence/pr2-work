#include<iostream>
#include<fstream>
#include<string>
#include<ctime>

using namespace std;

struct Majus
{
	string Nev;
	int Szulev;
	int Oraszam;
	int Fizetes;
};

void Kiir(Majus* tmb, int db)
{
	for (int i = 0; i < db; i++)
		cout << tmb[i].Nev << "\t\t" << tmb[i].Szulev << "\t" << tmb[i].Oraszam << "\t" << tmb[i].Fizetes << "\t" << endl;
}

int Osszora(Majus* tmb, int db)
{
	int osszeg = 0;
	for (int i = 0; i < db; i++)
		osszeg += tmb[i].Oraszam;

	return osszeg;
}

void legoregebb(Majus* tmb, int db)
{
	int min = 2004;
	string nev;
	for (int i = 0; i < db; i++)
	{
		if (min > tmb[i].Szulev)
		{
			min = tmb[i].Szulev;
			nev = tmb[i].Nev;
		}
	}
	cout << "A legidosebb dolgozo: " << nev << "ennyi eves: " << 2024-min << endl;
}
void ABC(Majus* tmb, int db)
{
	ofstream ki("majus_teljes.txt");
	string seged;
	int s1, s2, s3;
	for (int i = 0; i < db-1; i++)
	{
		for (int j = i+1; j < db; j++)
		{
			if (tmb[i].Nev > tmb[j].Nev)
			{

				seged = tmb[i].Nev;
				tmb[i].Nev = tmb[j].Nev;
				tmb[j].Nev = seged;
				s1 = tmb[i].Fizetes;
				tmb[i].Fizetes = tmb[j].Fizetes;
				tmb[j].Fizetes = s1;
				s2 = tmb[i].Oraszam;
				tmb[i].Oraszam = tmb[j].Oraszam;
				tmb[j].Oraszam = s2;
				s3 = tmb[i].Szulev;
				tmb[i].Szulev = tmb[j].Szulev;
				tmb[j].Szulev = s3;
			}
		}
	}
	for (int i = 0; i < db; i++)
	{
		ki << tmb[i].Nev << " " << tmb[i].Szulev << " " << tmb[i].Oraszam << " " << tmb[i].Fizetes << endl;
	}
}
int main()
{
	Majus majus[20];
	ifstream be("majus.txt");
	srand((unsigned int)time(NULL));
	int db = 0;
	for (int i = 0; i < 20 && !be.eof(); i++)
	{
		be >> majus[i].Nev;
		do
		{
			cout << "Kerem a "<< i+1 << ". dolgozo szuletesi evet : \n";
			cin >> majus[i].Szulev;
			if (majus[i].Szulev < 1957 || majus[i].Szulev > 2004)
				cout << "Hiba a megadott szam nem megfelelo.\n";
		} while (majus[i].Szulev < 1957 || majus[i].Szulev > 2004);
		majus[i].Oraszam = rand() % 161;
		majus[i].Fizetes = majus[i].Oraszam * 2800;
		db++;
	}
	cout << "A dolgozok szama: " << db << endl;
	Kiir(majus, db);
	cout << "Az osszes ledolgozott ora: " << Osszora(majus, db) << endl;
	legoregebb(majus, db);
	int tobbmintszaz = 0;
	for (int i = 0; i < db; i++)
	{
		if (majus[i].Oraszam > 100)
			tobbmintszaz++;
	}
	cout << "Ennyien dolgoztak tobb mint szaz orat: " << tobbmintszaz << endl;
	ABC(majus, db);
	



}