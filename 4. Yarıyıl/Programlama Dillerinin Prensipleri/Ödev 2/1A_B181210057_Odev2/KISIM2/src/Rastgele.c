/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın rastgeleliği sağlayan kısmının kaynak dosyası
* </p>
*/

#include "Rastgele.h"

//Rastgele yapısını oluşturacak fonksiyon yazılıyor.
Rastgele RastgeleOlustur()
{	
	Rastgele this;
	//Rastgele için bellekte gerekli yer ayrılıyor
	this = (Rastgele)malloc(sizeof(struct RASTGELE));
	this->sayi = 0;
	
	//Fonksiyonlara ilgili göstericiler atanıyor
	this->xorshift64 = &_Xorshift64;
	this->rastgeleUret = &_RastgeleUret;
	this->yoket = &RastgeleYoket;
	return this;
}

//xorshift64 algoritmasıyla çalışan fonksiyon oluşturuluyor
uint64_t _Xorshift64(Rastgele this)
{
	uint64_t x = this->sayi;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	this->sayi = x;
	return x;
}

//Rastgele sayı üreten fonksiyon yazılıyor
int _RastgeleUret(Rastgele this, int min, int max)
{
	int aralik = max - min + 1;
	int sonuc = this->xorshift64(this) % aralik;
	sonuc += min;
	return sonuc;
}

//Rastgele yapısını yok eden metod yazılıyor
void RastgeleYoket(Rastgele this)
{
	if(this == NULL) return;
	free(this);
}