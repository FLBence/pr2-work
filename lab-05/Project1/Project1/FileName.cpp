#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Ugynok
{
	string Varos;
	int Tavolsag;
};
int beolvas(char *t, Ugynok *tmb)
{
	ifstream be(t);
	if (be.fail())
	{
		cout << "Hiba";
		exit(1);
	}
	int db =0;
	for (int i = 0; i < 20 && !be.eof(); i++)
	{
		be >> tmb[i].Varos;
		be >> tmb[i].Tavolsag;
		db++;
		cout << tmb[i].Varos << " " << tmb[i].Tavolsag << endl;
	}
	be.close();
	return db;	
}
int ossztav(Ugynok *tmb, int db)
{
	int max = 0;
	for (int i = 0; i < db; i++)
		max += tmb[i].Tavolsag;
	return max * 2;
}
string legtavolabb(Ugynok *tmb, int db) 
{
	int maxi = 0;
	for (int i = 0; i < db; i++)
		if (tmb[maxi].Tavolsag < tmb[i].Tavolsag)
			maxi = i;
	return tmb[maxi].Varos;
}
int kozeliekszama(Ugynok *tmb, int db)
{
	int kozeliszam = 0;
	for (int i = 0; i < db; i++)
		if (tmb[i].Tavolsag < 80)
			kozeliszam++;
	return kozeliszam;
}
void rendezvekiir(Ugynok *tmb, int db)
{
	ofstream ki("rendezett.txt");
	Ugynok seged;
	if (ki.fail())
	{
		cerr << "A hiba a keszulekeben van";
		exit(1);
	}
	for (int i = 0; i < db-1; i++)
	{
		for (int j = i+1; j < db; j++)
		{
			if (tmb[i].Tavolsag > tmb[j].Tavolsag)
			{
				seged = tmb[i];
				tmb[i] = tmb[j];
				tmb[j] = seged;
			}
		}
	}
	for (int i = 0; i < db; i++)
		ki << tmb[i].Varos << " " << tmb[i].Tavolsag << endl;
	ki.close();
}
void rendezcsokkeno(Ugynok *tmb, int db)0
{
	ofstream ki2("rendezett2.txt");
	Ugynok seged;
	if (ki2.fail())
	{
		cerr << "A hiba a keszulekeben van";
		exit(1);
	}
	for (int i = 0; i < db; i++)
	{
		for (int j = i + 1; j < db ; j++)
		{
			if (tmb[i].Varos < tmb[j].Varos)
			{
				seged = tmb[i];
				tmb[i] = tmb[j];
				tmb[j] = seged;
			}
		}
	}
	for (int i = 0; i < db; i++)
		ki2 << tmb[i].Varos << " " << tmb[i].Tavolsag << endl;
	ki2.close();
}

int main()
{
	char file_path[] = "vartav.txt";
	Ugynok A[20];
	int varosDB = beolvas(file_path, A);
	cout << endl << "A Januarban megtett osszes tavolsag: " << ossztav(A, varosDB) << endl;
	cout << "A legtavolabbi varos: " << legtavolabb(A, varosDB) << endl;
	cout << "A kozeli varosok szama: " << kozeliekszama(A, varosDB) << endl;
	rendezvekiir(A, varosDB);
	rendezcsokkeno(A, varosDB);

}