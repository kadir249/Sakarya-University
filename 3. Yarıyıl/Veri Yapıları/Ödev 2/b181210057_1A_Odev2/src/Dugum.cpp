/**
* @file b181210057_1A_Odev2
* @description Bir text dosyasýna atýlan verilerin okunmasý ve tekrar eden verilerin ekrana yazdýrýlmayarak elde edilen kazancýn hesaplanmasý.
* @course 1. Öðretim A Grubu
* @assignment 2. Ödev
* @date 27.11.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "Dugum.h"

using namespace std;
Dugum::Dugum(string veri, Dugum *sonraki, Dugum *onceki)
{
	this->veri = veri;
	this->sonraki = sonraki;
	this->onceki = onceki;
}