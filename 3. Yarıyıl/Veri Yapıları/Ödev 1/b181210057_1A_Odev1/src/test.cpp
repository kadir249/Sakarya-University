/**
* @file b181210057_1A_Odev1
* @description Kovaları ve kovaların içinde oluşturulan topların kontrolünün yapılması.
* @course 1. Öğretim A Grubu
* @assignment 1. Ödev
* @date 03.11.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr 
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <locale.h>
#include "Kova.hpp"
#include "Top.hpp"
#include "KovaKontrol.hpp"

using namespace std;
HANDLE renkDegistir = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));

	
	int kovaSayisi;
	cout << "Kova Sayisi: ";

	cin >> kovaSayisi;


	Kova **kovaDizisi = new Kova*[kovaSayisi];
	Top **topDizisi = new Top*[kovaSayisi];
	Kova *tempDizi;


	for (int i = 0; i < kovaSayisi; i++)
	{
		tempDizi = new Kova();
		kovaDizisi[i] = tempDizi;
	}

	for (int i = 0; i < kovaSayisi; i++)
	{
		cout << i + 1 << ". Kova" << endl;
		kovaDizisi[i]->kovaUret();
		cout << "Kova Adresi:" << kovaDizisi[i] << endl;
		
		cout << "Top Adresi:" << "NULL" << endl;
		SetConsoleTextAttribute(renkDegistir, 15);
	}
	
	int cevap;

	do {
		cout << endl;
		cout << "[1] Toplari Yerlestir" << endl;
		cout << "[2] Toplari Yoket" << endl;
		cout << "[3] Kova Degistir" << endl;
		cout << "[4] Top Degistir" << endl;
		cout << "[5] Kovalari Tersten Yerlestir" << endl;
		cout << "[6] Toplari Tersten Yerlestir" << endl;
		cout << "[7] Cikis";
		cout << endl;
		cout << ">>";
	
		cin >> cevap;

		switch (cevap)
		{
		case 1:
			//system("cls");
			for (int i = 0; i < kovaSayisi; i++)
			{
				cout << i + 1 << ". Kova" << endl;
				Kova* k = kovaDizisi[i];
				if (k->topGetir() == NULL)
				{
					Top* yeniTop = new Top();
					k->topuBelirle(yeniTop);
				}
				k->kovaUret();
				cout << "Kova Adresi:" << kovaDizisi[i] << endl;
				if (k->topGetir() == NULL)
				{
					cout << "Top Adresi:" << "NULL" << endl;
				}
				else
				{
					cout << "Top Adresi:" << k->topGetir() << endl;
				}
				SetConsoleTextAttribute(renkDegistir, 15);
			}
			break;
			
		case 2:
			//system("cls");
			for (int i = 0; i < kovaSayisi; i++)
			{
				cout << i + 1 << ". Kova" << endl;
				Kova* k = kovaDizisi[i];
				if (k->topGetir() != NULL)
				{
					delete k->topGetir();
					k->topuBelirle(NULL);
				}
				k->kovaUret();
				cout << "Kova Adresi:" << kovaDizisi[i] << endl;
				cout << "Top Adresi:" << "NULL" << endl;
				SetConsoleTextAttribute(renkDegistir, 15);
			}
			break;
			
		case 3:
			//system("cls");
			int m;
			int n;
			cout << "Hangi Kova :";
			cin >> m;
			cout << "Hangi Kova ile :";
			cin >> n;
			cout << endl;

			KovaKontrol newKovaKontrol2;
			newKovaKontrol2.kovaDegistir(m, n, kovaDizisi);
			for (int i = 0; i < kovaSayisi; i++)
			{
				cout << i + 1 << ". Kova" << endl;

				kovaDizisi[i]->kovaUret();

				cout << "Kova Adresi:" <<kovaDizisi[i] << endl;
				
				if (kovaDizisi[i]->topGetir() == NULL)
				{
					cout << "Top Adresi:" << "NULL" << endl;
				}
				else
				{
					cout << "Top Adresi:" << kovaDizisi[i]->topGetir()<<endl;
				}
				SetConsoleTextAttribute(renkDegistir, 15);
			}
			break;

		case 4:
			//system("cls");
			int k;
			int l;
			cout << "Hangi Top: ";
			cin >> k;
			cout << "Hangi Top ile: ";
			cin >> l;

			KovaKontrol newKovaKontrol3;
			newKovaKontrol3.topDegistir(k, l, kovaDizisi);
			for (int i = 0; i < kovaSayisi; i++)
			{
				cout << i + 1 << ". Kova" << endl;

				kovaDizisi[i]->kovaUret();

				cout << "Kova Adresi:" << kovaDizisi[i] << endl;

				if (kovaDizisi[i]->topGetir() == NULL)
				{
					cout << "Top Adresi:" << "NULL" << endl;
				}
				else
				{
					cout << "Top Adresi:" << kovaDizisi[i]->topGetir() << endl;
				}
				SetConsoleTextAttribute(renkDegistir, 15);
			}
			break;
		
		case 5:
			//system("cls");
			KovaKontrol newKovaKontrol4;
			newKovaKontrol4.kovalariTersDondur(kovaSayisi, kovaDizisi);
			for (int i = 0; i < kovaSayisi; i++)
			{
				cout << i + 1 << ". Kova" << endl;
				kovaDizisi[i]->kovaUret();
				cout << "Kova Adresi:" << kovaDizisi[i] << endl;
				if (kovaDizisi[i]->topGetir() == NULL)
				{
					cout << "Top Adresi:" << "NULL" << endl;
				}
				else
				{
					cout << "Top Adresi:" << kovaDizisi[i]->topGetir() << endl;
				}
				SetConsoleTextAttribute(renkDegistir, 15);
			}
			break;
		
		case 6:
			//system("cls");
			KovaKontrol newKovaKontrol5;
			newKovaKontrol5.kovalariTersDondur(kovaSayisi, kovaDizisi);
			
			for (int i = 0; i < kovaSayisi; i++)
			{
				cout << i + 1 << ". Kova" << endl;
				kovaDizisi[i]->kovaUret();
				cout << "Kova Adresi:" << kovaDizisi[i] << endl;
				if (kovaDizisi[i]->topGetir() == NULL)
				{
					cout << "Top Adresi:" << "NULL" << endl;
				}
				else
				{
					cout << "Top Adresi:" << kovaDizisi[i]->topGetir() << endl;
				}
				SetConsoleTextAttribute(renkDegistir, 15);
			}
			break;
		default:cout << "Menu sayilarini kullaniniz..!"<<endl;continue;
		}
	} while (cevap != 7);
	
	delete kovaDizisi, tempDizi, topDizisi;
	system("cls");
	
	cin.get();
	cin.ignore();
	return 0;
}