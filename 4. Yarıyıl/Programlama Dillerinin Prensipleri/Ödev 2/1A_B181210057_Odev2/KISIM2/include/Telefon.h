/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın telefon kısmının başlık dosyası
* </p>
*/

#ifndef TELEFON_H
#define TELEFON_H

//Gerekli kütüphaneler ekleniyor
#include "Rastgele.h"
#include "IMEINo.h"

//Telefon yapısı oluşturuluyor
struct TELEFON
{
	//Değişkenler tanımlanıyor
	ImeiNo oImeiNo;
    int telefonNoTemp[11];
	char telefonNo[11];
	int telefonDegiskeni;
	Rastgele r3;
	
	//Fonksiyon göstericileri tanımlanıyor
	char* (*telefonNoUret)(struct TELEFON*);
	void (*yoket)(struct TELEFON*);	
};

typedef struct TELEFON* Telefon;

//Kullanılacak fonksiyonlar tanımlanıyor
Telefon TelefonNoOlustur(int);
char* _telefonNoUret(const Telefon);
void telefonYoket(Telefon);

#endif