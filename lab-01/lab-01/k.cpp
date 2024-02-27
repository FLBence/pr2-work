#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

struct Adatok
{
	int szakitas = 0, lokes = 0, suly = 0, rajtszam = 0;
	string nev;
};

int main() 
{
	int letszam = 0, suly = 0, kevesebb = 0;
	fstream fajl("Nevek.txt");
	srand((unsigned)time(NULL));
	Adatok tomb[15];
	for (int i = 0; i < 15 && !fajl.eof(); i++)
	{
		fajl >> tomb[i].szakitas;
		fajl >> tomb[i].lokes;
		getline(fajl, tomb[i].nev);
		tomb[i].rajtszam = rand() % 89 + 10;
		do
		{
			cout << "Adja meg a " << tomb[i].nev << " versenyzo sulyat(95-150): " << endl;
			cin >> tomb[i].suly;
			cin.ignore();
			if (tomb[i].suly < 95 || tomb[i].suly > 150)
				cout << "Hibas adat, a sulynak 90 es 150 kozott kell lennie.\n";
		} while (tomb[i].suly < 95 || tomb[i].suly > 150);
		letszam++;
	}
	fajl.close();
	cout.setf(ios::right);
	cout << "A versenyen " << letszam << " versenyzo indult." << endl;
	for (int i = 0; i < letszam; i++)
	{
		cout << setw(20) << tomb[i].nev << "\t rajtszam: " << tomb[i].rajtszam << "\t suly: " << tomb[i].suly << "\t szakitas: " << tomb[i].szakitas << "\t lokes: " << tomb[i].lokes << "\t osszesitett: " << (tomb[i].lokes + tomb[i].szakitas) << endl;
	}
	
}