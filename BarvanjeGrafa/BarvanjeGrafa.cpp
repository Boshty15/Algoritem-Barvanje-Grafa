// BarvanjeGrafa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int vel;
bool C[50][50];
//int x[20];
vector<int> rezultat;

void meni() {
	cout << endl;
	cout << "Barvanje Grafa - izbira:" << endl;
	cout << "1 Preberi podatke iz datoteke" << endl;
	cout << "2 Pozeni" << endl;
	cout << "3 Konec" << endl;
	cout << endl;
	cout << "Vasa izbira: ";
}

void beri(string f)
{
	fstream dat(f.c_str(), fstream::in);
	int i = 0;
	int p, q;
	for (int k = 0; k < 20; k++) {
		for (int j = 0; j < 20; j++) {
			C[k][j] = false;
		}
	}

	while (!dat.eof())
	{
		dat >> p >> q;
		C[p - 1][q - 1] = true;
		C[q - 1][p - 1] = true;
		i++;
	}
	vel = i;

	dat.close();
}
void novaBarva(int m, int k, int x[]) {
	bool konec = false;
	while (!konec){
		int tmp = (x[k]+1)% (m + 1) ;
		x[k] = tmp;
		if (x[k] == 0) {
			konec = true;
			break;
		}
		int j = 0;
		while (j < vel && !(C[k][j] == true && x[k] == x[j])) {
			j++;
		}
		if (j == vel) {
			konec = true;
			break;
		}
	}
}

void barvanjeGrafa(int m, int k,int x[]) {
	bool konec = false;
	while(!konec) {
			novaBarva(m,k,x);
			if (x[k] == 0) {
				konec = true;
				break;
			}
			if (k == vel) {
				for (int i = 1; i <= vel; i++) {
					cout << x[i] << " ";
				}
				cout << endl;
			}
			else {
				barvanjeGrafa(m, k + 1,x);
			}
	}

}


int main()
{
	int vnos;
	int i = 0;
	int k = 0;
	int x[50];
	int m;
	do {
		meni();
		cin >> vnos;
		switch (vnos)
		{
		case 1:
			beri("graf2.txt");
			cout << "Velikost: " << vel << endl;
			for (int j = 0; j<vel; j++) {
				for (int i = 0; i < vel; i++) {
					if (C[i][j] == true) {
						cout << "T ";
						}
					if (C[i][j] == false) {
						cout << "F ";
					}

				}			
				cout << endl;
			}
			break;
		case 2:
			cout << "Vnesi stevilo barv!" << endl;
			cin >> m;
			for (; k < vel; k++) {
				x[k] = 0;
			}
			k = 1;
			barvanjeGrafa(m, k,x);
			
			cout << "Rezultat: " << endl;
			/*for (int j = 0; j < rezultat.size(); j++) {
				cout << j << " " << rezultat.front() << endl;
			}*/

			break;
		default:
			break;
		}
	} while (vnos != 3);


    return 0;
}

