/**
* @file b181210057_1A_Odev1
* @description Kovaları ve kovaların içinde oluşturulan topların kontrolünün yapılması.
* @course 1. Öğretim A Grubu
* @assignment 1. Ödev
* @date 03.11.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr 
*/

#ifndef TOP_H
#define TOP_H

#include "pch.h"
#include "Top.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <locale.h>

class Top
{
private:
	char toplar;

public:
	Top();
	void topOlustur();	
};
#endif