/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: Ödev 4
**				ÖÐRENCÝ ADI...............: Kadir Çelik
**				ÖÐRENCÝ NUMARASI.: B181210057
**				DERS GRUBU…………: 1C Grubu
****************************************************************************/

//strcopyde hata verdiði için projenin özellikleri penceresindeki c/c++ içindeki öniþlemci kýsmýna "_CRT_SECURE_NO_WARNINGS" yazdým.

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

#define limit 500 //Limit adýnda 500 deðerinde bir sabit oluþturur

char metin[limit];//metin adlý dizinin uzunluðu belirtilir
char sifre[limit];//sifre adlý dizinin uzunluðu belirtilir
int alfabeBoyutu;
int bul(char alfabe[], char arananHarf)//Harflerin alfabedeki konumlarýný bulur
{
	int i, sayac = -1;

	for (i = 0; i < alfabeBoyutu; i++)//i'yi alfabe boyutu kadar arttýrýr
	{
		if (arananHarf == alfabe[i])//Aradýðýmýz harfi alfabede bulur
			sayac = i;//sayaca i'yi atar
	}
	return sayac;//sayacý geri döndürür
}

//Þifre adýnda bir class tanýmlanýyor
class Sifre
{
public:
	Sifre(char *alfabe, char *sifre);
	Sifre();

	char* sifrele(char*);
	char* sifreCoz(char*);
	void sifreKelimesiAta(char*);

private:
	char* alfabe;
	char* sifreKelimesi;
};

Sifre::Sifre(char *alfabe, char *sifre)
{
	this->alfabe = alfabe;//private alfabe deðiþkeni fonksiyondaki alfabe deðiþkenine ulaþýr
	this->sifreKelimesi = sifre;//private sifreKelimesi deðiþkeni fonksiyondaki sifre deðiþkenine ulaþýr
}

Sifre::Sifre()
{
	const char* alfabe1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//alfabe1 adlý bir dizi oluþturuluyor
	const char* sifre1 = "BSM";//sifre1 adlý bir dizi oluþturuluyor
	this->alfabe = strcpy(alfabe, alfabe1);//alfabe1 deðiþkeni alfabeye kopyalanýyor
	this->sifreKelimesi = strcpy(sifreKelimesi,sifre1);//sifre1 deðiþkeni sifreKelimesine kopyalanýyor
}

char* Sifre::sifrele(char*)
{
	//Deðiþkenler tanýmlanýyor
	int i, j = 0, metinHarfSirasi, sifreHarfSirasi;
	int metinBoyut = strlen(metin);//Metnin boyutu bir deðiþkene atanýyor
	int sifreBoyut = strlen(sifre);//Þifrenin boyutu bir deðiþkene atanýyor

	for (i = 0; i < metinBoyut; i++, j++)//Döngüyü metin boyutu kadar döndürür
	{
		if (j >= sifreBoyut)//j metin boyutuna büyük eþit olduðunda j'yi sýfýrlar
		{
			j = 0;
		}
		metinHarfSirasi = bul(alfabe, metin[i]);//bul fonksiyonundan dönen deðeri metinHarfSirasina atar
		sifreHarfSirasi = bul(alfabe, sifre[j]);//bul fonksiyonundan dönen deðeri sifreHarfSirasina atar

		if (metinHarfSirasi != -1 && sifreHarfSirasi != -1)//bul fonksiyonundan dönen deðerler -1'den farklýysa çalýþýr
		{
			//metinHarfSirasi ve sifreHarfSirasiný toplayýp alfabeBoyutu kadar modunu alýr ve metinHarfsirasi deðiþkenine atar
			metinHarfSirasi = (metinHarfSirasi + sifreHarfSirasi) % alfabeBoyutu;
			metin[i] = alfabe[metinHarfSirasi];//metin dizisinin i. indisine alfabe dizisinin metinHarfSirasina eþit olan indisini atar
		}
	}
	return 0;
}

char* Sifre::sifreCoz(char*)
{
	//Deðiþkenler tanýmlanýyor
	int i, j = 0, metinHarfSirasi, sifreHarfSirasi;
	int metinBoyut = strlen(metin);//Metnin boyutu bir deðiþkene atanýyor
	int sifreBoyut = strlen(sifre);//Þifrenin boyutu bir deðiþkene atanýyor

	for (i = 0; i < metinBoyut; i++, j++)//Döngüyü metin boyutu kadar döndürür
	{
		if (j >= sifreBoyut)//j metin boyutuna büyük eþit olduðunda j'yi sýfýrlar
		{
			j = 0;
		}

		metinHarfSirasi = bul(alfabe, metin[i]);//bul fonksiyonundan dönen deðeri metinHarfSirasina atar
		sifreHarfSirasi = bul(alfabe, sifre[j]);//bul fonksiyonundan dönen deðeri sifreHarfSirasina atar

		if (metinHarfSirasi != -1 && sifreHarfSirasi != -1)//bul fonksiyonundan dönen deðerler -1'den farklýysa çalýþýr
		{
			//metinHarfSirasi ve sifreHarfSirasinýn farkýný alýp alfabeBoyutu kadar modunu alýr ve metinHarfsirasi deðiþkenine atar
			metinHarfSirasi = (metinHarfSirasi - sifreHarfSirasi) % alfabeBoyutu;

			if (metinHarfSirasi < 0)//metinHarfSirasi sýfýrdan küçükse çalýþýr
			{
				metinHarfSirasi += alfabeBoyutu;//metinHarfSirasi deðiþkeninin deðerine alfabeBoyutu deðiþkeninin deðerini ekler
			}
			metin[i] = alfabe[metinHarfSirasi];//metin dizisinin i. indisine alfabe dizisinin metinHarfSirasina eþit olan indisini atar
		}
	}
	return 0;
}

void Sifre::sifreKelimesiAta(char* kelime)
{
	this->sifreKelimesi = kelime;//private sifrekelimesi fonksiyondaki kelimeye ulaþýr
}

int main()
{
	char alfabe[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//alfabe adlý bir karakter dizisi oluþturuluyor
	char sifre[] = "SAU";//sifre adlý bir karakter dizisi oluþturuluyor

	alfabeBoyutu = strlen(alfabe);//alfabe dizisinin boyutu hesaplanýr

	//Kullanýcýdan bilgilein girmesi isteniyor
	cout << "ALFABE           :"; cin >> alfabe;
	cout << "SIFRE            :"; cin >> sifre;
	cout << "METIN            :"; cin >> metin;

	//Þifrelenmiþ metin ekrana yazdýrýlýyor
	Sifre sifrele(alfabe, sifre);
	cout << "SIFRELENMIS METIN:" << metin;
	cout << endl;

	//Deþifre metin ekrana yazdýrýlýyor
	Sifre sifreCoz(alfabe, sifre);
	cout << "DESIFRE METIN    :" << metin;
	cout << endl;


	system("pause");
	return 0;
}