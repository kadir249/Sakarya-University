/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın kişi kısmının kaynak dosyası
* </p>
*/


#include "Kisi.h"

//Kisi yapısını oluşturacak fonksiyon yazılıyor.
Kisi KisiOlustur()
{	
	Kisi this;
	//Kisi için bellekte gerekli yer ayrılıyor
	this = (Kisi)malloc(sizeof(struct KISI));
	
	//Fonksiyonlara ilgili göstericiler atanıyor
	this->yoket = &kisiYoket;	
}

//Kisi yapısını yok eden metod yazılıyor
void kisiYoket(Kisi this)
{	
	if(this == NULL) return;
	this->kimlikNo->kyoket(this->kimlikNo);
	this->telefon->yoket(this->telefon);
	free(this);
}