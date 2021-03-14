/**
* @file b181210057_1A_Odev1
* @description Kovaları ve kovaların içinde oluşturulan topların kontrolünün yapılması.
* @course 1. Öğretim A Grubu
* @assignment 1. Ödev
* @date 03.11.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr 
*/

#ifndef KOVA_H
#define KOVA_H
#include "Top.hpp"

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <locale.h>

using namespace std;

class Kova {
private:
	int kovaRengi = 0;
	Top* top = NULL;
public:
	HANDLE renkVer = GetStdHandle(STD_OUTPUT_HANDLE);
	Kova();
	void kovaUret();
	Top* topGetir();
	void topuBelirle(Top* top);

};
#endif