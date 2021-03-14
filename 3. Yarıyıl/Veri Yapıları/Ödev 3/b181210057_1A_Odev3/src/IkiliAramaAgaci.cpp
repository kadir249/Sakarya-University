/**
* @file b181210057_1A_Odev3
* @description Ýki text dosyasýndan alýnan verilerin ikili arama aðaçlarýyla karþýlaþtýrýlmasý.
* @course 1. Öðretim A Grubu
* @assignment 3. Ödev
* @date 15.12.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <string>
#include "IkiliAramaAgaci.h"
#include "Dugum.h"

using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci()
{
	soy_sayisi = 0;
	kok = NULL;
}

void IkiliAramaAgaci::elemanEkleme(Dugum *&altDugum, const int &veri)
{
	if (altDugum == NULL)
	{
		altDugum = new Dugum(veri);
	}

	else if (veri <= altDugum->sayi)
	{
		elemanEkleme(altDugum->sol, veri);
	}

	else
	{
		elemanEkleme(altDugum->sag, veri);
	}
}

void IkiliAramaAgaci::elemanEkle(const int &veri)
{
	elemanEkleme(kok, veri);
}

int IkiliAramaAgaci::maxSayisi(Dugum *altDugum)
{
	while (altDugum->sag != NULL)
	{
		altDugum = altDugum->sag;
	}
	return altDugum->sayi;
}

int IkiliAramaAgaci::maxSayi()
{
	return maxSayisi(kok);
}

int IkiliAramaAgaci::kokSayi()
{
	return kok->sayi;
}

int IkiliAramaAgaci::soySayisiHesapla(Dugum *altDugum)
{
	if (altDugum == NULL)
	{
		return 0;
	}

	else
	{
		return(soySayisiHesapla(altDugum->sol) + 1 + soySayisiHesapla(altDugum->sag));
	}
}

int IkiliAramaAgaci::soySayisi()
{
	return soy_sayisi;
}


bool IkiliAramaAgaci::elemanSilme(Dugum *&altDugum, const int &veri)
{
	if (altDugum == NULL)
	{
		return false;
	}
	if (altDugum->sayi == veri)
	{
		return dugumSil(altDugum);
	}
	else if (veri < altDugum->sayi)
	{
		return elemanSilme(altDugum->sol, veri);
	}
	else
	{
		return elemanSilme(altDugum->sag, veri);
	}
}

bool IkiliAramaAgaci::dugumSil(Dugum *&altDugum)
{
	Dugum *silinecekDugum = altDugum;
	if (altDugum->sag == NULL)
	{
		altDugum = altDugum->sol;
	}
	else if (altDugum->sol == NULL)
	{
		altDugum = altDugum->sag;
	}
	else 
	{
		silinecekDugum = altDugum->sol;
		Dugum *ebeveynDugum = altDugum;
		while (silinecekDugum->sag != NULL)
		{
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		altDugum->sayi = silinecekDugum->sayi;
		if (ebeveynDugum == altDugum)
		{
			altDugum->sol = silinecekDugum->sol;
		}
		else
		{
			ebeveynDugum->sag = silinecekDugum->sol;
		}
	}
	delete silinecekDugum;
	return true;
}

void IkiliAramaAgaci::elemanSil(const int &veri)
{
	if (elemanSilme(kok, veri) == false);
}

void IkiliAramaAgaci::yazdir(Dugum *altDugum)
{
	if (altDugum != NULL)
	{
		yazdir(altDugum->sol);
		yazdir(altDugum->sag);
		cout <<"<"<< altDugum->sayi << "," << soySayisiHesapla(altDugum) - 1 << "> ";
		soy_sayisi += soySayisiHesapla(altDugum) - 1;
	}
}

int IkiliAramaAgaci::soySayisiSifirlama()
{
	soy_sayisi = 0;
	return soy_sayisi;
}

void IkiliAramaAgaci::ekranaYazdir()
{
	yazdir(kok);
}

IkiliAramaAgaci::~IkiliAramaAgaci()
{
	while (kok != NULL)
	{
		dugumSil(kok);
		cout<<"yikildi";
	}

}