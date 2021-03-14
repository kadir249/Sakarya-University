/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın IMEI kısmının başlık dosyası
* </p>
*/
#ifndef IMEINO_H
#define IMEINO_H

//Gerekli kütüphaneler ekleniyor
#include "Rastgele.h"
#include "stdbool.h"
#include "string.h"

//ImeiNo yapısı oluşturuluyor
struct IMEINO
{
	//Değişkenler tanımlanıyor
	int imeiNoTemp[15];
	char* imeiNo;
	char temp[15];
	Rastgele r1;

	//Fonksiyon göstericileri tanımlanıyor
	char* (*imeiNoUret)(struct IMEINO*, int);
	int (*basamaklarinToplami)(int);
	bool (*imeiNoKontrolEt)(char*);
	void (*yoket)(struct IMEINO*); 
};

typedef struct IMEINO* ImeiNo;

//Kullanılacak fonksiyonlar tanımlanıyor
ImeiNo ImeiNoOlustur();
char* _ImeiNoUret(const ImeiNo, int);
int _BasamaklarinToplami(int);
bool _ImeiNoKontrolEt(char*);
void ImeiYokEt(ImeiNo);

#endif