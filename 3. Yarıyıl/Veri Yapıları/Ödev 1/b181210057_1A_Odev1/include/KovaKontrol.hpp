/**
* @file b181210057_1A_Odev1
* @description Kovaları ve kovaların içinde oluşturulan topların kontrolünün yapılması.
* @course 1. Öğretim A Grubu
* @assignment 1. Ödev
* @date 03.11.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr 
*/

#ifndef KOVAKONTROL_H
#define KOVAKONTROL_H
#include "Kova.hpp"
#include "Top.hpp"


class KovaKontrol{
public:	
	void kovaDegistir(int a, int b, Kova *kovaDizi[]);
	void kovalariTersDondur(int a, Kova *kovaDizi[]);
	void topDegistir(int a, int b, Kova *kovaDizi[]);
	void toplariTerstenYerlestir(int a, Kova* kovaDizi[]);
};	
#endif