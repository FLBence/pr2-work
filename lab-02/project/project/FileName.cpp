#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<ctime>

using namespace std;


int main() 
{
	int f = 10;
	int *mut;
	int &fi = f;
	mut = &f;
	cout << "f = " << f << ", fi = "<< fi << ", *mut = " << *mut << endl;
	fi = 20;
	cout << "f = " << f << ", fi = " << fi << ", *mut = " << *mut << endl;

	cout << &f << " " << &fi << " " << mut << " " << &mut << endl;

	//vektor
	vector <int> jegyek(3);
	char betu;
	int szam;
	for (int i = 0; i < 3; i++)
	{
		cout << "Adja meg az " << i + 1 << ". tanulo jegyet(1-5): " << endl;
		cin >> jegyek[i];
		cin.ignore();
	}
	int t = 0;
	cout << "akar meg jegyet felvenni? (y/n)\n";
	cin >> betu;
	cin.ignore();
	if (betu == 'y')
	{
		do
		{
			cout << "Jegy (1-5): ";
			cin >> szam;
			cin.ignore();
			jegyek.push_back(szam);
			cout << "Akar meg egyet? (y/n)\n";
			cin >> betu;
			cin.ignore();
			t++;
		} while (betu == 'y');
	}
	cout << "A jegyek szama :" << jegyek.size() << endl;
	cout << "Osztalyzatok: \n";
	for (int i = 0; i < jegyek.size(); i++)
		cout << jegyek.at(i) << ", ";

	cout << endl;
	jegyek.pop_back();
	cout << "Osztalyzatok: \n";
	for (int i = 0; i < jegyek.size(); i++)
		cout << jegyek.at(i) << ", ";
	jegyek.insert(jegyek.begin() + 1 , 5);
	cout << "Osztalyzatok: \n";
	for (int i = 0; i < jegyek.size(); i++)
		cout << jegyek.at(i) << ", ";
	










}
