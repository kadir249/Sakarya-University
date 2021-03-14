/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın rastgele kişi kısmının başlık dosyası
* </p>
*/

#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H

//Gerekli kütüphaneler ekleniyor
#include "Kisi.h"
#include "DosyaOkuma.h"
#include "Rastgele.h"

//RastgeleKisi yapısı oluşturuluyor
struct RASTGELEKISI
{	
	//Değişkenler tanımlanıyor
	Kisi kisi;
	Rastgele rastgeleSayi;
	int degisken;
	
	//Fonksiyon göstericileri tanımlanıyor
	void (*rastgeleIsimUret)(struct RASTGELEKISI*, char*);
	void (*rastgeleYasUret)(struct RASTGELEKISI*);
	void (*yoket)(struct RASTGELEKISI*);	
};

typedef struct RASTGELEKISI* RastgeleKisi;

//Kullanılacak fonksiyonlar tanımlanıyor
RastgeleKisi RastgeleKisiOlustur();
void _rastgeleIsimUret(const RastgeleKisi, char* dosyaAdi);
void _rastgeleYasUret(const RastgeleKisi);
void rastgeleKisiYoket(RastgeleKisi);

#endif