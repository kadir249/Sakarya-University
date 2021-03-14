/**
* @file b181210057_1A_Odev2
* @description Bir text dosyasýna atýlan verilerin okunmasý ve tekrar eden verilerin ekrana yazdýrýlmayarak elde edilen kazancýn hesaplanmasý.
* @course 1. Öðretim A Grubu
* @assignment 2. Ödev
* @date 27.11.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <string>
#include <iostream>
using namespace std;

class Dugum {
public:
	string veri;
	int sayi = 0;
	Dugum *sonraki;
	Dugum *onceki;
	Dugum(string veri = NULL, Dugum *sonraki = NULL, Dugum *onceki = NULL);
};
#endif