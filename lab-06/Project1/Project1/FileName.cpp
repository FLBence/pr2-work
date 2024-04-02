#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

inline double atvalt(double fok)
{
	return fok * 3.14159 / 180;
}

int main(int ArgDb, char* ArgTmb[])
{
	char nev[80];
	if (ArgDb == 2)
		strcpy_s(nev, ArgTmb[1]);
	else
	{
		cout << "Adja meg a file nevet: ";
		cin >> nev;
	}
	cout << "Az allomany neve: " << nev << endl;

	ifstream be;
	be.open(nev);
	if (be)
	{
		int db = 0;
		int szam;
		while (!be.eof())
		{
			be >> szam;
			db++;
		}
		cout << "Ennyi szam van a listaban: " << db << endl;
		be.clear();
		be.seekg(0, ios::beg);
		int* p = new int[db];
		if (p)
		{
			register int i;
			for (i = 0; i < db; i++)
				be >> p[i];
			be.close();
			cout << "A beolvasott szamok: " << endl;
			double s = 0.0;
			cout << endl;
			for (int i = 0; i < db; i++)
			{
				cout << setw(15) << atvalt(p[i]);
				s += p[i];
			}
			cout << endl<< "A szamok atlaga: " << s / db << endl;
			system("pause");
			delete[] p;
			return 0;
 		}
		else
		{
			cerr << "A tarfoglalas sikertelen!" << endl;
			system("pause");
			exit(3);
		}
	}
	else
	{
		cerr << "Fajlmegnyitasi hiba!" << endl;
		be.close();
		system("pause");
		exit(2);
	}
	system("pause");
	return 0;
}