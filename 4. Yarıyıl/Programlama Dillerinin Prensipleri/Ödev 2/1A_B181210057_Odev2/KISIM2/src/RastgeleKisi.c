/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın rastgele kişi kısmının kaynak dosyası
* </p>
*/

#include "RastgeleKisi.h"

//RastgeleKisi yapısını oluşturacak fonksiyon yazılıyor.
RastgeleKisi RastgeleKisiOlustur(int i)
{
	RastgeleKisi this;
	//RastgeleKisi için bellekte gerekli yer ayrılıyor
	this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
	this->degisken = i;
	this->kisi = KisiOlustur();
	this->rastgeleSayi = RastgeleOlustur();
	
	//Kisi yapısına atamalar yapılıyor
	this->kisi->telefon = TelefonNoOlustur(this->degisken);
	this->kisi->telefon->telefonNoUret(this->kisi->telefon);
	
	this->kisi->kimlikNo = KimlikNoOlustur(this->degisken);
	this->kisi->kimlikNo->kimlikNoUret(this->kisi->kimlikNo);
	
	//Fonksiyonlara ilgili göstericiler atanıyor
	this->rastgeleIsimUret = &_rastgeleIsimUret;
	this->rastgeleYasUret = &_rastgeleYasUret;
	this->yoket = &rastgeleKisiYoket;
	
	this->rastgeleIsimUret(this,"random_isimler.txt");
	this->rastgeleYasUret(this);
	return this;
}

//Rastgele isim ve soyisim üreten fonksiyon yazılıyor
void _rastgeleIsimUret(const RastgeleKisi this,char* dosyaAdi)
{
	//Dosya okumak için Dosya nesnesi çağrılıyor
    Dosya dosya = DosyaOlustur(dosyaAdi);
	//Programın çalıştığı andaki zaman hesaplanıyor
	clock_t current_time = time(NULL);
	
	//Hesaplanan zaman bir değişkenle çarpılarak rastgelSayi'nın kullanacağı sayı değerine atanıyor
	this->rastgeleSayi->sayi = (int)(current_time * this->degisken);
	//Dosyadan rastgele bir satır seçilerek isim ve soyisime atanıyor
    int rastgeleSayi =  this->rastgeleSayi->rastgeleUret(this->rastgeleSayi, 0, dosya->sayac);
	      
    char* isim = dosya->oku(dosya)[rastgeleSayi];
   
	char* temp =  strtok(isim," ");
	char* ad;
	char* soyad;
	
	ad=temp;
    temp = strtok(NULL, " ");
	soyad=temp;
	soyad[strlen(soyad)-1] = '\0';
    this->kisi->isim=ad;
    this->kisi->soyisim = soyad;
	dosya->yoket(dosya);
}

//Rastgele yaş üreten fonksiyon yazılıyor 
void _rastgeleYasUret(const RastgeleKisi this)
{
    this->kisi->yas = 0;
	//Programın çalıştığı andaki zaman hesaplanıyor
	clock_t current_time = time(NULL);
	
	//Hesaplanan zaman bir değişkenle çarpılarak rastgelSayi'nın kullanacağı sayı değerine atanıyor
	this->rastgeleSayi->sayi = (int)(current_time * this->degisken);
    this->kisi->yas = this->rastgeleSayi->rastgeleUret(this->rastgeleSayi, 0, 99);        
}

//RastgeleKisi yapısını yok eden metod yazılıyor
void rastgeleKisiYoket(RastgeleKisi this)
{	
	if(this == NULL) return;
	this->kisi->yoket(this->kisi);
	this->rastgeleSayi->yoket(this->rastgeleSayi);
	free(this);
}















