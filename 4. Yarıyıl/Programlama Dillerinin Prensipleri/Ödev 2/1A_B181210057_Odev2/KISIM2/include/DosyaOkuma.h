/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın dosya okuma kısmının başlık dosyası
* </p>
*/

#ifndef DOSYA_H
#define DOSYA_H

//Gerekli kütüphaneler ekleniyor
#include "stdio.h"
#include "stdlib.h"

//Dosya yapısı oluşturuluyor
struct DOSYA
{
	//Değişkenler tanımlanıyor
    int sayac;	
	char* dosyaAdi;
	
	//Fonksiyon göstericileri tanımlanıyor
	char** (*oku)(struct DOSYA*);
	void (*yoket)(struct DOSYA*);
};

typedef struct DOSYA* Dosya;

//Kullanılacak fonksiyonlar tanımlanıyor
Dosya DosyaOlustur(char*);
char** verileriAl(const Dosya);
void DosyaYoket(Dosya);

#endif