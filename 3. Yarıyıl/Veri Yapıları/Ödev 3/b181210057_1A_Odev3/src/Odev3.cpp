/**
* @file b181210057_1A_Odev3
* @description İki text dosyasından alınan verilerin ikili arama ağaçlarıyla karşılaştırılması.
* @course 1. Öğretim A Grubu
* @assignment 3. Ödev
* @date 15.12.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <conio.h>
#include "Dugum.h"
#include "IkiliAramaAgaci.h"

using namespace std;

int main()
{
	IkiliAramaAgaci *benimAgac = new IkiliAramaAgaci();
	IkiliAramaAgaci *rakipAgac = new IkiliAramaAgaci();

	int okuBenim, okuRakip;
	ifstream dosyaOkuBenim(".\\doc\\benim.txt", ios::in);
	ifstream dosyaOkuRakip(".\\doc\\rakip.txt", ios::in);

	while (dosyaOkuBenim >> okuBenim)
	{
		benimAgac->elemanEkle(okuBenim);
	}

	ifstream dosyaOku("rakip.txt", ios::in);

	while (dosyaOkuRakip >> okuRakip)
	{
		rakipAgac->elemanEkle(okuRakip);
	}

	int benimSkor = 0;
	int rakipSkor = 0;
	int turSayisi = 1;
	char tus;

	do
	{
		system("cls");
		cout << "Benim Agac Postorder :" << endl;
		benimAgac->ekranaYazdir();
		cout << endl;
		cout << "Benim Agac Toplam Soy Sayisi : " << benimAgac->soySayisi() << endl;
		cout << "--------------------" << endl << endl;

		cout << "Rakip Agac Postorder :" << endl;
		rakipAgac->ekranaYazdir();
		cout << endl;
		cout << "Rakip Agac Toplam Soy Sayisi : " << rakipAgac->soySayisi() << endl << endl;

		if (benimAgac->soySayisi() < rakipAgac->soySayisi())
		{
			benimSkor++;
			cout << "--TEBRIKLER TURU KAZANDINIZ--" << endl << endl;
			cout << "SKOR" << endl;
			cout << "Benim : " << benimSkor << endl;
			cout << "Rakip : " << rakipSkor << endl << endl;
			
			benimAgac->elemanEkle(rakipAgac->maxSayi());
			rakipAgac->elemanSil(rakipAgac->maxSayi());
			
			rakipAgac->elemanEkle(benimAgac->kokSayi());
			benimAgac->elemanSil(benimAgac->kokSayi());		
		}
		else if(benimAgac->soySayisi() > rakipAgac->soySayisi())
		{
			rakipSkor++;
			cout << "--TURU KAYBETTINIZ--" << endl << endl;
			cout << "SKOR" << endl;
			cout << "Benim : " << benimSkor << endl;
			cout << "Rakip : " << rakipSkor << endl << endl;

			rakipAgac->elemanEkle(benimAgac->maxSayi());
			benimAgac->elemanSil(benimAgac->maxSayi());

			benimAgac->elemanEkle(rakipAgac->kokSayi());
			rakipAgac->elemanSil(rakipAgac->kokSayi());

		}
		else
		{
			cout << "--TUR BERABERE--" << endl << endl;
			cout << "SKOR" << endl;
			cout << "Benim : " << benimSkor << endl;
			cout << "Rakip : " << rakipSkor << endl << endl;

			benimAgac->elemanEkle(rakipAgac->kokSayi());
			rakipAgac->elemanSil(rakipAgac->kokSayi());

			rakipAgac->elemanEkle(benimAgac->kokSayi());
			benimAgac->elemanSil(benimAgac->kokSayi());
		}
		tus = _getch();
		turSayisi++;
		benimAgac->soySayisiSifirlama();
		rakipAgac->soySayisiSifirlama();

		if (benimSkor == 5 || rakipSkor == 5)
		{
			break;
		}
	} while (turSayisi <= 21);

	if (benimSkor > rakipSkor)
	{
		cout << "--TEBRIKLER OYUNU KAZANDINIZ--";
	}
	else if (benimSkor < rakipSkor)
	{
		cout << "--UZGUNUZ OYUNU KAYBETTINIZ--";
	}
	else
	{
		cout << "--OYUN BERABERE BITTI--";
	}

	delete benimAgac;
	delete rakipAgac;
	return 0;
}