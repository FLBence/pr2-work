#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Teglalap
{
	private: int mag, alap;
	public: bool init(int a, int b)
	{
		if (a > 0 && b > 0)
		{
			mag = a;
			alap = b;
			return true;
		}
		cout << "Hiba!\n";
		return false;
	}
	public: int ter()
	{
		return alap * mag;
	}
	public: int ker()
	{
		return 2 * (alap + mag);
	}
	public: int getAlap()
	{
		return alap;
	}
	public: int getMag()
	{
		return mag;
	}
};

int main()
{
	int old1, old2;
	cout << "Adja meg a teglalap oldalait:\n";
	cin >> old1 >> old2;
	Teglalap t1, t2;
	t1.init(5, 10);
	t2.init(old1, old2);
	cout << "Az elso teglalap terulete: " << t1.ter() << ", kerulete: " << t1.ker() << endl;
	cout << "A masodik teglalap terulete: " << t2.ter() << ", kerulete: " << t2.ker() << endl;
	cout << "Az elso teglalap magassaga: " << t1.getMag() << endl;
}