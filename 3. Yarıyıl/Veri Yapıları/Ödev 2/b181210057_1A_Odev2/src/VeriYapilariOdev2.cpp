/**
* @file b181210057_1A_Odev2
* @description Bir text dosyasına atılan verilerin okunması ve tekrar eden verilerin ekrana yazdırılmayarak elde edilen kazancın hesaplanması.
* @course 1. Öğretim A Grubu
* @assignment 2. Ödev
* @date 27.11.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Dugum.h"
#include "CiftYonluBagliListe.h"

using namespace std;

int main()
{
	int i = 0;
	string oku;
	CiftYonluBagliListe *eleman = new CiftYonluBagliListe();

	ifstream dosyaOku(".\\doc\\Odev.txt", ios::in);

	while (dosyaOku >> oku)
	{
		eleman->elemanEkleme(oku);
		i++;
	}
	dosyaOku.close();
	eleman->yazdir();
	
	delete eleman;
	return 0;
}