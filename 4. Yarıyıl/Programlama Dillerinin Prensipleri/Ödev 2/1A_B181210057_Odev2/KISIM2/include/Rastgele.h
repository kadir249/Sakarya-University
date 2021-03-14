/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın rastgeleliği sağlayan kısmının başlık dosyası
* </p>
*/

#ifndef RASTGELE_H
#define RASTGELE_H

//Gerekli kütüphaneler ekleniyor
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "stdint.h"

//Rastgele yapısı oluşturuluyor
struct RASTGELE
{	
	//Değişken tanımlanıyor
	uint64_t sayi;
	
	//Fonksiyon göstericileri tanımlanıyor
	uint64_t (*xorshift64)(struct RASTGELE*);
    int (*rastgeleUret)(struct RASTGELE*, int min, int max);
	void (*yoket)(struct RASTGELE*);
};
typedef struct RASTGELE *Rastgele;

//Kullanılacak fonksiyonlar tanımlanıyor
Rastgele RastgeleOlustur();
uint64_t _Xorshift64(const Rastgele);
int _RastgeleUret(const Rastgele, int min, int max);
void RastgeleYoket(Rastgele);

#endif