#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
double Atlag(int*, int);
void Csere(int* x, int* y);
void Csere2(int& x, int& y);
void Feltolt(int tmb[], int n);
void Kiir(int tmb[], int);
int Max(int tmb[], int);
int main()
{
	int jegy1[10] = { 1,2,3,23,34,56,23,45,21,23 };
	int jegy2[10] = { 10,25,43,23,34,56,23,45,21,23 };
	cout << "\nSzamtani atlag: " << Atlag(jegy1, 10) << endl;
	cout << "\nSzamtani atlag: " << Atlag(jegy2, 10) << endl;
	//Érték szerinti átadás.
	/*int szam1, szam2;
	cout << "Elso szam: ";
	cin >> szam1;
	cin.ignore();
	cout << "Masodik szam: ";
	cin >> szam2;
	cin.ignore();
	cout << "Csere elott: " << szam1 << " " << szam2 << endl;
	Csere2(szam1, szam2);
	cout << "Csere utan: " << szam1 << " " << szam2 << endl;
	*/
	//tomb feltoltese adatokkal
	srand((unsigned)time(NULL));
	int db;
	do
	{
		cout << "Hany tanuloja van a csoportnak?";
		cin >> db;
		cin.ignore();
		if (db < 1 || db > 10)
			cout << "Nem jo a szam. (1-10)" << endl;
	} while (db < 1 || db > 10);
	int *jegy = new int[db];
	Feltolt(jegy, db);
	Kiir(jegy, db);
	cout << "\nA legjobb dolgozat pontszama: " << Max(jegy, db);
	return 0;
}
double Atlag(int* tmb, int db)
{
	double osszeg = 0;
	for (int i = 0; i < db; i++)
		osszeg += tmb[i];
	return osszeg / db;
}

void Csere(int* x, int* y)
{
	int seged;
	seged = *x;
	*x = *y;
	*y = seged;
}

void Csere2(int& x, int& y)
{
	int seged = x;
	x = y;
	y = seged;
}

void Feltolt(int tmb[], int n)
{
	for (int i = 0; i < n; i++) 
	{
		tmb[i] = (rand() % 100) + 1;
	}
}

void Kiir(int tmb[], int n) 
{
	cout << "\n A csoport pontjai: \n";
	for (int i = 0; i < n; i++)
		cout << setw(4) << tmb[i];
	cout << endl;
}

int Max(int tmb[], int n)
{
	int max = tmb[0];
	for (int i = 1; i < n; i++)
		if (max < tmb[i])
			max = tmb[i];
	return max;
}
