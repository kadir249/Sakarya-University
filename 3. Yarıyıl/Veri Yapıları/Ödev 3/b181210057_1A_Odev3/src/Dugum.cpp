/**
* @file b181210057_1A_Odev3
* @description Ýki text dosyasýndan alýnan verilerin ikili arama aðaçlarýyla karþýlaþtýrýlmasý.
* @course 1. Öðretim A Grubu
* @assignment 3. Ödev
* @date 15.12.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "Dugum.h"

using namespace std;

Dugum::Dugum(const int &sayi, Dugum *sag, Dugum *sol)
{
	this->sayi = sayi;
	this->sag = sag;
	this->sol = sol;
}