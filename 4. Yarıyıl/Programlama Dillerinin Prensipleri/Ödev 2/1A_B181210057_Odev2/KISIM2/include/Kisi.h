/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın kişi kısmının başlık dosyası
* </p>
*/

#ifndef KISI_H
#define KISI_H

//Gerekli kütüphaneler ekleniyor
#include "KimlikNo.h"
#include "Telefon.h"

//Kisi yapısı oluşturuluyor
struct KISI
{	
	//Değişkenler tanımlanıyor
	Telefon telefon;
	KimlikNo kimlikNo;
	char* isim;
	char* soyisim;
	int yas;
	
	//Fonksiyon göstericileri tanımlanıyor
	void (*yoket)(struct KISI*);	
};

typedef struct KISI* Kisi;

//Kullanılacak fonksiyonlar tanımlanıyor
Kisi KisiOlustur();
void kisiYoket(Kisi);

#endif