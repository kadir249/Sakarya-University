/**
* @file b181210057_1A_Odev2
* @description Bir text dosyasýna atýlan verilerin okunmasý ve tekrar eden verilerin ekrana yazdýrýlmayarak elde edilen kazancýn hesaplanmasý.
* @course 1. Öðretim A Grubu
* @assignment 2. Ödev
* @date 27.11.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr
*/
#ifndef CIFTYONLUBAGLILISTE_HPP
#define CIFTYONLUBAGLILISTE_HPP
#include "Dugum.h"
#include <iostream>
#include <string>

using namespace std;

class CiftYonluBagliListe {
private:
    int boyut;
	Dugum *bas;
	Dugum *kuyruk;
	int i = 1;
	int kazanc = 0;
	int basamakSayisi = 1;

public:
	CiftYonluBagliListe();
	void elemanEkleme(string& veri);
	void yazdir();
};
#endif