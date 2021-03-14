/**
* @file b181210057_1A_Odev3
* @description Ýki text dosyasýndan alýnan verilerin ikili arama aðaçlarýyla karþýlaþtýrýlmasý.
* @course 1. Öðretim A Grubu
* @assignment 3. Ödev
* @date 15.12.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr
*/

#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>

using namespace std;

class Dugum {
public:
	Dugum *sag;
	Dugum *sol;
	int sayi;
	Dugum(const int &sayi, Dugum *sag = NULL, Dugum *sol = NULL);
};
#endif