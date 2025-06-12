#include <iostream>
#include <fstream>
using namespace std;
const int N = 1000;
const int T = 3;
int main() {
	int tab[T][N];
	ifstream in("liczby.txt");
	ofstream out("wyniki.txt");
	for (int i = 0; i < N; i++) {
		in >> tab[0][i] >> tab[1][i] >> tab[2][i];
	}
	out << "ZADANIE 1" << endl;
	int ile_rosnie = 0;
	for(int i = 0; i < N; i++) {
		if(tab[0][i] < tab[1][i] && tab[1][i] < tab[2][i]) {
			ile_rosnie++;
		}
	}
	out << ile_rosnie << endl;
	out << "ZADANIE 2" << endl;
	int suma_dzielnikow = 0;
	for(int i = 0; i < N; i++) {
		int a = tab[0][i];
		int b = tab[1][i];

		while(b!=0) {
			int temp = b;
			b = a%b;
			a = temp;
		}
		int c = tab[2][i];
		while(c!=0) {
			int temp = c;
			c = a%c;
			a = temp;
		}
		suma_dzielnikow+=a;
	}
	out << suma_dzielnikow << endl;
	out << "ZADANIE 3" << endl;

	int suma_cyfr_rowna_35;
	int najwieksza_suma = 0;
	int poprzednia_suma = 0;
	int ile_razy_najwieksza_suma = 0;
	for(int i = 0; i < N; i++) {
		int a = tab[0][i];
		int b = tab[1][i];
		int c = tab[2][i];
		int suma_cyfr = 0;
		while(a!=0) {
			suma_cyfr+=a%10;
			a/=10;
		}
		while(b!=0) {
			suma_cyfr+=b%10;
			b/=10;
		}
		while(c!=0) {
			suma_cyfr+=c%10;
			c/=10;
		}
		if(suma_cyfr == 35) {
			suma_cyfr_rowna_35++;
		}
		poprzednia_suma = suma_cyfr;
		if (suma_cyfr > najwieksza_suma) {
			najwieksza_suma = suma_cyfr;
			ile_razy_najwieksza_suma = 1;
		} else if (suma_cyfr == najwieksza_suma) {
			ile_razy_najwieksza_suma++;
		}
	}
	out << suma_cyfr_rowna_35 << endl;
	out << najwieksza_suma << endl;
	out << ile_razy_najwieksza_suma << endl;
}
