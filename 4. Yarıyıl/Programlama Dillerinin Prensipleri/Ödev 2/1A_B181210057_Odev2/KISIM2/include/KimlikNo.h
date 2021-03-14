/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın kimlik kısmının başlık dosyası
* </p>
*/

#ifndef KIMLIKNO_H
#define KIMLIKNO_H

//Gerekli kütüphaneler ekleniyor
#include "Rastgele.h"
#include "stdbool.h"
#include "string.h"

//KimlikNo yapısı oluşturuluyor
struct KIMLIKNO
{
	//Değişkenler tanımlanıyor
	int tcNoTemp[11];
	char* tcNo;
	char temp[11];
	int teklerinToplami;
	int ciftlerinToplami;
	int kimlikDegiskeni;
	Rastgele r2;
	
	//Fonksiyon göstericileri tanımlanıyor
	char* (*kimlikNoUret)(struct KIMLIKNO*);
	bool (*kimlikNoKontrolEt)(char*);
	void (*kyoket)(struct KIMLIKNO*);  
};

typedef struct KIMLIKNO* KimlikNo;

//Kullanılacak fonksiyonlar tanımlanıyor
KimlikNo KimlikNoOlustur(int);
char* _KimlikNoUret(const KimlikNo);
bool _KimlikNoKontrolEt(char*);
void KimlikYokEt(KimlikNo);

#endif